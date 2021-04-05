#include "Character.h"
#include "AnimatedSprite.h"

Character::Character(SDL_Renderer* context,
	const std::string& path,
	int width,
	int height,
	int frames)
	: Actor{ new AnimatedSprite(context, path, width, height, frames) },
	_v{}
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

AnimatedSprite* Character::animatedSprite()
{
	return static_cast<AnimatedSprite*>(_sprite);
}