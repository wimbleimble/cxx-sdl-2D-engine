#include "WelpState.h"
#include "Engine.h"
#include "FlippyState.h"


WelpState::WelpState(Engine* engine)
	: State{}, fuck { engine->renderer(), "fuck.png", 1}
{
	_scene.push_back(Layer());
	_scene[0].addActor(&fuck);
}

WelpState::~WelpState()
{
}

void WelpState::enter(Engine* engine)
{

}
State* WelpState::handleInput(Engine* engine, SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_TAB:
		return new FlippyState(engine);
	}
	return nullptr;
}

State* WelpState::update(Engine* engine)
{
	return nullptr;
}

void WelpState::exit(Engine* engine)
{

}