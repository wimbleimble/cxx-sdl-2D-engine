#include "Shield.h"

#include <iostream>

#include "Animation.h"

Shield::Shield(SDL_Renderer* context)
	: AnimatedActor{ context, "media/swoop.png", 32, 32, 3 },
	_direction{ Direction::Up },
	_transitionCounter{}
{
	_animator.addAnimation("Idle", 0, 1, 60);
	_animator.addAnimation("Move", 1, 2, 12);
	_animator["Move"].onEnd(std::bind([](Animator* animator) {
		std::cout << "done";
		animator->playAnimation("Idle");
		}, & _animator));
}

Shield::~Shield()
{
}

State* Shield::handleEvent(Engine* engine, SDL_Event event)
{

	if (event.type == SDL_KEYDOWN && _transitionCounter == 0)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
		case SDLK_w:
			setDirection(Direction::Up);
			break;
		case SDLK_DOWN:
		case SDLK_s:
			setDirection(Direction::Down);
			break;
		case SDLK_LEFT:
		case SDLK_a:
			setDirection(Direction::Left);
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			setDirection(Direction::Right);
			break;
		}
	}
	return nullptr;
}

State* Shield::update(Engine* engine)
{
	return nullptr;
}

void Shield::setDirection(Direction direction)
{
	if ((int)direction > (int)_direction)
		_animator.playAnimation("Move", false, true);
	else
		_animator.playAnimation("Move");

	switch (direction)
	{
	case Direction::Up:
		_angle = 0;
		break;
	case Direction::Down:
		_angle = 180;
		break;
	case Direction::Left:
		_angle = 270;
		break;
	case Direction::Right:
		_angle = 90;
		break;
	}
	_direction = direction;
}