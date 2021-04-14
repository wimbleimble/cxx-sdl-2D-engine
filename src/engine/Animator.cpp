#include "Animator.h"

#include <cassert>
#include <iostream>

#include "Err.h"

Animator::Animator(SDL_Renderer* context,
	const std::string& path,
	int width,
	int height,
	int frames)
	: _sprite{ context, path },
	_width{ width },
	_height{ width },
	_frames{ frames },
	_frameTimer{}, _animations{}, _currentAnimation{}, _currentFrame{}
{
}

Animator::~Animator() {}

const Sprite& Animator::sprite() const { return _sprite; }
const std::string& Animator::currentAnimation() const
{
	return _currentAnimation;
}
int Animator::currentFrame() const { return _currentFrame; }

SDL_Rect Animator::srcRect(double deltaTime)
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

void Animator::addAnimation(
	const std::string& name, int startFrame, int length, int frameRate)
{
	assert(startFrame >= 0);
	assert(startFrame < _frames);
	assert(startFrame + length <= _frames);
	_animations.insert(std::pair<std::string, Animation>(
		name,
		{ startFrame, length, frameRate }));
}

void Animator::setAnimation(const std::string& animation)
{
	if (_animations.find(animation) != _animations.end())
	{
		if (animation != _currentAnimation)
		{
			_currentFrame = 0;
			_currentAnimation = animation;
		}
	}
	else
		assert(false && "Supplied name does not match any known animation.");

}
