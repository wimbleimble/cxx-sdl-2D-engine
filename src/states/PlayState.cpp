#include "PlayState.h"

#include <iostream>

#include "Engine.h"
#include "Arrow.h"

PlayState::PlayState(Engine* engine)
	: State{ (int)Layers::NUM_LAYERS }/* ,
	_heart{ static_cast<AnimatedActor*>(
		_scene[(int)Layers::Main].addActor(
			new AnimatedActor(engine->renderer().context(),
			"media/path.png",
			32,
			32,
			1)
		)
	) } */
{
}

PlayState::~PlayState() {}

void PlayState::enter(Engine* engine)
{
}

State* PlayState::handleEvent(Engine* engine, SDL_Event event)
{
	return nullptr;
}

State* PlayState::update(Engine* engine)
{
	return nullptr;
}

void PlayState::exit(Engine* engine)
{
}