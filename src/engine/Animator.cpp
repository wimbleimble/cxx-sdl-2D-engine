#include "Animator.h"

#include <cassert>
#include <iostream>

#include "Animation.h"
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
	_frameTimer{}, _animations{}, _currentAnimation{}, _currentFrame{},
	_playState{ PlayState::Stopped }, _reverse{ false }
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

	Animation& animation{ _animations[_currentAnimation] };
	if (_playState != PlayState::Stopped)
	{
		_frameTimer += deltaTime;

		if (_frameTimer >= 1000.0 / (double)animation.frameRate())
		{
			_frameTimer = 0;
			if (_reverse)
			{
				if (_currentFrame - 1 < 0)
				{
					_currentFrame = 0;
					animationEnd();
				}
				else
				{
					--_currentFrame;
					animation.callFrame(_currentFrame);
				}
			}
			else
			{
				if (_currentFrame == animation.length() - 1)
				{
					animationEnd();
				}
				else
				{
					++_currentFrame;
					animation.callFrame(_currentFrame);
				}
			}
		}
	}

	return SDL_Rect({
		(_currentFrame + animation.startFrame()) * _width, 0, _width, _height
		});
}

void Animator::animationEnd()
{
	switch (_playState)
	{
	case PlayState::Loop:
		_currentFrame = _reverse ?
			_animations[_currentAnimation].length() - 1 : 0;
		break;
	default:
		stop();
	}
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

void Animator::playAnimation(const std::string& animation,
	bool loop,
	bool reverse)
{
	auto it{ _animations.find(animation) };
	if (it != _animations.end())
	{
		if (animation != _currentAnimation)
		{
			_currentFrame = reverse ? it->second.length() - 1 : 0;
			_currentAnimation = animation;
			_reverse = reverse;
			_playState = loop ? PlayState::Loop : PlayState::Play;
		}
	}
	else
		assert(false && "Supplied name does not match any known animation.");

}

void Animator::stop()
{
	_animations[_currentAnimation].callEnd();
	_playState = PlayState::Stopped;
}

Animation& Animator::operator [] (const std::string& key)
{
	assert(_animations.find(key) != _animations.end());
	return _animations[key];
}