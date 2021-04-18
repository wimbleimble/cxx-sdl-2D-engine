#include "PlayState.h"

#include <iostream>

#include "Engine.h"
#include "Arrow.h"
#include "Shield.h"

PlayState::PlayState(Engine* engine)
	: State{ (int)Layers::NUM_LAYERS },
	_heart{ static_cast<AnimatedActor*>(
		_scene[(int)Layers::Player].addActor(
			new AnimatedActor(engine->renderer().context(),
			"media/heart.png",
			32,
			32,
			1)
		)
	) },
	_shield{ static_cast<Shield*>(
		_scene[(int)Layers::Player].addActor(
			new Shield(engine->renderer().context())
		)
	) }
{
	srand(engine->deltaTime());
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
	_timer += engine->deltaTime();
	if ((int)_timer % 500 == 0)
		_scene[(int)Layers::Arrows].addActor(
			new Arrow(engine->renderer().context(),
				(Arrow::Direction)(rand() % 4),
				1));

	return nullptr;
}

void PlayState::exit(Engine* engine)
{
}