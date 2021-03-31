#include "FlippyState.h"
#include "Engine.h"
#include "WelpState.h"

#include <iostream>

FlippyState::FlippyState(Engine* engine)
	: State{},
	fuck{ engine->renderer(), "tiny.png" }
{
	_actors.push_back(&fuck);
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

	fuck.position() += fuck.v();
	return nullptr;
}
void FlippyState::exit(Engine* engine)
{
}