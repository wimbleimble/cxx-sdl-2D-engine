#include "MenuState.h"
#include <iostream>
#include <functional>
#include "Engine.h"
#include "AnimatedSprite.h"

void startButtonClicked()
{
	std::cout << "CLACK\n";
}

MenuState::MenuState(Engine* engine)
	: State{ 1 },
	_startButton{ engine->renderer().context(), "start-button.png", 64, 32, 3 }
{
	_scene[0].addActor(&_startButton);
	_startButton.onClick(&startButtonClicked);
}

MenuState::~MenuState() {}

void MenuState::enter(Engine* engine)
{
	std::cout << engine->renderer().renderWidth() << '\n';
	std::cout << engine->renderer().renderHeight() << '\n';
}

State* MenuState::handleEvent(Engine* engine, SDL_Event event)
{
	return nullptr;
}

State* MenuState::update(Engine* engine)
{
	return nullptr;
}

void MenuState::exit(Engine* engine)
{
}

