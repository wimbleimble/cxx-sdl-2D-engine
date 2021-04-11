#include "MenuState.h"
#include <iostream>
#include "Engine.h"
#include "AnimatedSprite.h"

MenuState::MenuState(Engine* engine)
	: State{ engine->renderer().winWidth(),
		engine->renderer().winHeight(),
		1 },
	_startButton{ engine->renderer().context(), "start-button.png", 64, 32, 3 }
{
	_scene[0].addActor(&_startButton);
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
	if (_startButton.mouseOver(engine->renderer(),
		engine->input(), _camera))
		_startButton.animatedSprite()->setAnimation("Hover");
	else
		_startButton.animatedSprite()->setAnimation("Normal");
	return nullptr;
}

void MenuState::exit(Engine* engine)
{
}