#include "State.h"

State::State(int layers)
	: _scene{ layers }, _camera{}
{
}

const Scene& State::scene() const
{
	return _scene;
}

const Camera& State::camera() const
{
	return _camera;
}