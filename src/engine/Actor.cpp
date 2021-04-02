#include "Actor.h"

Actor::Actor(SDL_Renderer* context, const std::string& path, int frames)
	: _sprite{ context, path, frames }, _position{}, _zIndex{ 0 }
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

void Actor::setZIndex(int zIndex)
{
	_zIndex = zIndex;
}

bool Actor::operator > (const Actor& actor) const
{
	return _zIndex > actor._zIndex;
}