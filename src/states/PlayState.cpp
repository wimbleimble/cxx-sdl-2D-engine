#include "PlayState.h"

#include <iostream>

PlayState::PlayState(Engine* engine)
	: State{ (int)Layers::NUM_LAYERS }
{
	std::cout << "Entered PlayState\n";
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