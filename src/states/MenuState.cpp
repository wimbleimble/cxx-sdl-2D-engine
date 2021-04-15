#include "MenuState.h"
#include <iostream>
#include <functional>
#include "Engine.h"
#include "PlayState.h"

MenuState::MenuState(Engine* engine)
	: State{ 1 },
	_startButton{
		static_cast<Button*>(_scene[0].addActor(
			new Button(engine->renderer().context(),
			"start-button.png",
			64,
			32,
			3))) },
	_start{ false }
{
	_startButton->onClick(std::bind([this](Engine* engine) {
		this->startCallback(engine);
		}, engine));

}

MenuState::~MenuState() {}

void MenuState::enter(Engine* engine)
{
}

State* MenuState::handleEvent(Engine* engine, SDL_Event event)
{
	return nullptr;
}

State* MenuState::update(Engine* engine)
{
	if (_start)
		return new PlayState(engine);
	_startButton->setAngle(engine->deltaTime() * 0.4 + _startButton->angle());
	return nullptr;
}

void MenuState::exit(Engine* engine)
{
}

void MenuState::startCallback(Engine* engine)
{
	_start = true;
}