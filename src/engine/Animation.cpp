#include "Animation.h"
#include <cassert>

Animation::Animation(int startFrame, int length, int frameRate)
	: _startFrame{ startFrame },
	_length{ length },
	_frameRate{ frameRate },
	_frameCallbacks(length, std::function<void()>())
{
}

Animation::~Animation() {}

int Animation::startFrame() const { return _startFrame; }
int Animation::length() const { return _length; }
int Animation::frameRate() const { return _frameRate; }

void Animation::callFrame(int index) const
{
	assert(index < _length);
	if (_frameCallbacks[index])
		_frameCallbacks[index]();
}
void Animation::callEnd() const
{
	if (_endCallback)
		_endCallback();
}

void Animation::onFrame(int index,
	const std::function<void()>& callback)
{
	assert((index < _length) && "Animation::onFrame: index out of range.");
	_frameCallbacks[index] = callback;

}

void Animation::onEnd(const std::function<void()>& callback)
{
	_endCallback = callback;
}