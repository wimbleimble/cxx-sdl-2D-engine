#include "Character.h"

Character::Character(SDL_Renderer* context, const std::string& path, int frames)
	: Actor{ context, path, frames }, _v{}
{
}

Character::~Character() {}

void Character::update()
{
}

bool Character::visible() const
{
	return true;
}

const Vec2& Character::v() const
{
	return _v;
}

void Character::setV(const Vec2& v)
{
	_v = v;
}