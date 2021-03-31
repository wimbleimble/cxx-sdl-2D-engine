#include "FlippyState.h"
#include "Engine.h"
#include "WelpState.h"

#include <iostream>

FlippyState::FlippyState(Engine* engine)
	: State{},
	fuck{ engine->renderer(), "vriska.png", 138 }
{
	_actors.push_back(&fuck);
	fuck.sprite().addAnimation("WalkDown", 16, 9, 30);
	fuck.sprite().addAnimation("WalkLeft", 44, 8, 30);
	fuck.sprite().addAnimation("WalkRight", 25, 9, 30);
	fuck.sprite().addAnimation("WalkUp", 34, 8, 30);
	fuck.sprite().addAnimation("Idle", 0, 1, 30);
	fuck.sprite().setAnimation("Idle");
}

FlippyState::~FlippyState()
{
}

void FlippyState::enter(Engine* engine)
{
}

State* FlippyState::handleInput(Engine* engine, SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_TAB:
		return new WelpState(engine);
	}
	return nullptr;
}

State* FlippyState::update(Engine* engine)
{
	const Uint8* k{ SDL_GetKeyboardState(nullptr) };
	fuck.setV(
		(int)k[SDL_SCANCODE_UP] * Vec2(0, -fuck.speed) 
		+ (int)k[SDL_SCANCODE_DOWN] * Vec2(0, fuck.speed) 
		+ (int)k[SDL_SCANCODE_LEFT] * Vec2(-fuck.speed, 0) 
		+ (int)k[SDL_SCANCODE_RIGHT] * Vec2(fuck.speed, 0) 
	);

	if (k[SDL_SCANCODE_UP])
		fuck.sprite().setAnimation("WalkUp");
	else if (k[SDL_SCANCODE_DOWN])
		fuck.sprite().setAnimation("WalkDown");
	else if (k[SDL_SCANCODE_LEFT])
		fuck.sprite().setAnimation("WalkLeft");
	else if (k[SDL_SCANCODE_RIGHT])
		fuck.sprite().setAnimation("WalkRight");
	else
		fuck.sprite().setAnimation("Idle");

	fuck.position() += fuck.v();
	return nullptr;
}
void FlippyState::exit(Engine* engine)
{
}