#include "FlippyState.h"
#include "Engine.h"
#include "WelpState.h"

#include <iostream>

FlippyState::FlippyState(Engine* engine)
	: State{},
	vriska{ engine->renderer(), "vriska.png", 138 },
	karkat{ engine->renderer(), "karkat.png", 141 }
{
	vriska.setZIndex(69);

	_scene.push_back(Layer());
	_scene[0].addActor(&vriska);
	_scene[0].addActor(&karkat);

	vriska.sprite().addAnimation("WalkDown", 16, 9, 30);
	vriska.sprite().addAnimation("WalkLeft", 44, 8, 30);
	vriska.sprite().addAnimation("WalkRight", 25, 9, 30);
	vriska.sprite().addAnimation("WalkUp", 34, 8, 30);
	vriska.sprite().addAnimation("Idle", 0, 1, 30);
	vriska.sprite().setAnimation("Idle");

	karkat.sprite().addAnimation("WalkDown", 16, 9, 30);
	karkat.sprite().addAnimation("WalkLeft", 44, 8, 30);
	karkat.sprite().addAnimation("WalkRight", 25, 9, 30);
	karkat.sprite().addAnimation("WalkUp", 34, 8, 30);
	karkat.sprite().addAnimation("Idle", 16, 9, 7);
	karkat.sprite().setAnimation("Idle");
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
	vriska.setV(
		(int)k[SDL_SCANCODE_UP] * Vec2(0, -vriska.speed) 
		+ (int)k[SDL_SCANCODE_DOWN] * Vec2(0, vriska.speed) 
		+ (int)k[SDL_SCANCODE_LEFT] * Vec2(-vriska.speed, 0) 
		+ (int)k[SDL_SCANCODE_RIGHT] * Vec2(vriska.speed, 0) 
	);

	if (k[SDL_SCANCODE_UP])
		vriska.sprite().setAnimation("WalkUp");
	else if (k[SDL_SCANCODE_DOWN])
		vriska.sprite().setAnimation("WalkDown");
	else if (k[SDL_SCANCODE_LEFT])
		vriska.sprite().setAnimation("WalkLeft");
	else if (k[SDL_SCANCODE_RIGHT])
		vriska.sprite().setAnimation("WalkRight");
	else
		vriska.sprite().setAnimation("Idle");

	vriska.position() += vriska.v();
	return nullptr;
}
void FlippyState::exit(Engine* engine)
{
}