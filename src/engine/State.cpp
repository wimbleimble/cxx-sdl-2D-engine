#include "State.h"

const Scene& State::scene() const
{
	return _scene;
}

State::State(int layers)
	: _scene{ layers }
{
}