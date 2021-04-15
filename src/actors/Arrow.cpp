#include "Arrow.h"

#include "Engine.h"

Arrow::Arrow(SDL_Renderer* context,
	const std::string& path,
	int width,
	int height,
	int frames,
	Direction direction,
	double speed)
	: AnimatedActor{ context, path, width, height, frames },
	_direction{ direction },
	_speed{ speed }
{
	switch (_direction)
	{
	case Direction::LeftRight:
		_angle = -90;
		_position.setX(-172);
		break;
	case Direction::RightLeft:
		_angle = -90;
		_position.setX(-172);
		_flip = (SDL_RendererFlip)(_flip | SDL_FLIP_HORIZONTAL);
		break;
	case Direction::TopBottom:
		_flip = (SDL_RendererFlip)(_flip | SDL_FLIP_VERTICAL);
		break;
	case Direction::BottomTop:
		_position.setY(-106);
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
			velocityLookup[(int)_direction][0] * _speed * engine->deltaTime(),
			velocityLookup[(int)_direction][1] * _speed * engine->deltaTime()
		));
	return nullptr;
}

bool Arrow::visible() const
{
	return true;
}