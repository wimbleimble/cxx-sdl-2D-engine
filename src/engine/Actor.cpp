#include "Actor.h"

Actor::Actor(SDL_Renderer* context, const std::string& path)
	: _sprite{ new Sprite(context, path) }, _position{}, _zIndex{ 0 }
{
}

Actor::Actor(Sprite* sprite)
	: _sprite{ sprite }
{
}

Actor::~Actor()
{
	delete _sprite;
}

Sprite* const Actor::sprite() const
{
	return _sprite;
}

Sprite* Actor::sprite()
{
	return _sprite;
}

const Vec2& Actor::position() const
{
	return _position;
}

int Actor::width() const
{
	return _sprite->width();
}

int Actor::height() const
{
	return _sprite->height();
}

Vec2& Actor::position()
{
	return _position;
}

void Actor::setPosition(const Vec2& position)
{
	_position = position;
}

void Actor::setPosition(int x, int y)
{
	setPosition(Vec2(x, y));
}

void Actor::setZIndex(int zIndex)
{
	_zIndex = zIndex;
}

bool Actor::operator > (const Actor& actor) const
{
	return _zIndex > actor._zIndex;
}