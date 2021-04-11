#include "AnimatedSprite.h"
#include "Err.h"
#include <cassert>
#include <iostream>

AnimatedSprite::AnimatedSprite(SDL_Renderer* context,
	const std::string& path,
	int width,
	int height,
	int frames)
	: Sprite{ context, path },
	_frames{ frames },
	_animations{},
	_currentAnimation{},
	_frameTimer{},
	_currentFrame{}
{
	_width = width;
	_height = height;
}

AnimatedSprite::AnimatedSprite(const AnimatedSprite& sprite)
	: Sprite{ sprite },
	_frames{ sprite._frames },
	_animations{ sprite._animations },
	_currentAnimation{ sprite._currentAnimation },
	_frameTimer{ sprite._frameTimer },
	_currentFrame{ sprite._currentFrame }
{
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::addAnimation(
	const std::string& name, int startFrame, int length, int frameRate)
{
	assert(startFrame >= 0);
	assert(startFrame < _frames);
	assert(startFrame + length <= _frames);
	Animation animation{ startFrame, length, frameRate };
	_animations.insert(std::pair<std::string, Animation>(name, animation));
}

void AnimatedSprite::setAnimation(const std::string& animation)
{
	if (_animations.find(animation) != _animations.end()
		&& animation != _currentAnimation)
	{
		_currentFrame = 0;
		_currentAnimation = animation;
	}

}

SDL_Rect AnimatedSprite::srcRect(double deltaTime)
{
	if (_frames == 1 || _currentAnimation == "")
		return SDL_Rect({ 0, 0, _width, _height });

	_frameTimer += deltaTime;
	Animation& animation{ _animations[_currentAnimation] };

	if (_frameTimer >= 1000.0 / (double)animation.frameRate)
	{
		++_currentFrame;
		_frameTimer = 0;
	}
	if (_currentFrame >= animation.length)
		_currentFrame = 0;

	return SDL_Rect({
		(_currentFrame + animation.startFrame) * _width, 0, _width, _height
		});
}

AnimatedSprite& AnimatedSprite::operator=(const AnimatedSprite& sprite)
{
	_frames = sprite._frames;
	_context = sprite._context;
	loadTexture(sprite._path);
	_width = sprite._width;
	_height = sprite._height;
	return *this;
}