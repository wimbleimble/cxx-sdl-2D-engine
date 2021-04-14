#include "Arrow.h"

Arrow::Arrow(SDL_Renderer* context,
	const std::string& path,
	int width,
	int height,
	int frames
	Vec2 velocity)
	: Ui{ new AnimatedSprite(context, path, width, height, frames) },
	_v{ velocity }
{
}

Arrow::~Arrow() {}

State* Arrow::handleEvent(Engine* engine, SDL_Event event)
{
	return nullptr;
}

State* Arrow::update(Engine* engine)
{
	return nullptr;
}

bool Arrow::visible() const
{
	return true;
}


AnimatedSprite* Arrow::animatedSprite()
{
	return static_cast<AnimatedSprite*>(_sprite);
}