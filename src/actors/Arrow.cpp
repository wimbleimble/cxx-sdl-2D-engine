#include "Arrow.h"

#include "Engine.h"

Arrow::Arrow(SDL_Renderer* context,
	Direction direction,
	double speed)
	: AnimatedActor{ context, "media/arrlr.png", 16, 16, 1 },
	_direction{ direction },
	_speed{ speed }
{
	switch (_direction)
	{
	case Direction::LeftRight:
		_angle = -90;
		_position.setX(-106);
		break;
	case Direction::RightLeft:
		_angle = 90;
		_position.setX(106);
		_flip = SDL_FLIP_HORIZONTAL;
		break;
	case Direction::TopBottom:
		_position.setY(-106);
		break;
	case Direction::BottomTop:
		_flip = SDL_FLIP_VERTICAL;
		_position.setY(106);
		break;

	};
}

Arrow::~Arrow() {}

State* Arrow::handleEvent(Engine* engine, SDL_Event event)
{
	return nullptr;
}

State* Arrow::update(Engine* engine)
{
	setPosition(
		_position
		+ Vec2(
			velocityLookup[(int)_direction][0] * (_speed / 10) * engine->deltaTime(),
			velocityLookup[(int)_direction][1] * (_speed / 10) * engine->deltaTime()
		));
	return nullptr;
}