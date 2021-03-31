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
	std::cout << "Entered State.\n";
}

State* FlippyState::handleInput(Engine* engine, SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_RETURN:
		return new WelpState(engine);
	}
	return nullptr;
}

State* FlippyState::update(Engine* engine)
{
	const Uint8* currentKeyStates{ SDL_GetKeyboardState(nullptr) };
	if (currentKeyStates[SDL_SCANCODE_UP])
		fuck.setV(Vec2(0, -fuck.speed));
	else if (currentKeyStates[SDL_SCANCODE_DOWN])
		fuck.setV(Vec2(0, fuck.speed));
	else if (currentKeyStates[SDL_SCANCODE_LEFT])
		fuck.setV(Vec2(-fuck.speed, 0));
	else if (currentKeyStates[SDL_SCANCODE_RIGHT])
		fuck.setV(Vec2(fuck.speed, 0));
	else
		fuck.setV(Vec2(0, 0));

	fuck.position() += fuck.v();
	return nullptr;
}
void FlippyState::exit(Engine* engine)
{
}