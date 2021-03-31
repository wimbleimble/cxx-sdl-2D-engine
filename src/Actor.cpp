#include "Actor.h"

Actor::Actor(SDL_Renderer* context, const std::string& path)
	: _sprite{ context, path }, _position{}
{
}

const Sprite& Actor::sprite() const
{
	return _sprite;
}

Sprite& Actor::sprite()
{
	return _sprite;
}

const Vec2& Actor::position() const
{
	return _position;
}
Vec2& Actor::position()
{
	return _position;
}
void Actor::setPosition(const Vec2& position)
{
	_position = position;
}