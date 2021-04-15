#include "State.h"
#include "Actor.h"

#include <iostream>

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

State* State::handleActorEvent(Engine* engine, SDL_Event event)
{
	State* ret{};
	for (Layer& layer : _scene)
		for (Actor* actor : layer)
		{
			ret = actor->handleEvent(engine, event);
			if (ret != nullptr)
				return ret;
		}

	return nullptr;
}

State* State::actorUpdate(Engine* engine)
{
	State* ret{};
	for (Layer& layer : _scene)
		for (Actor* actor : layer)
		{
			ret = actor->update(engine);
			if (ret != nullptr)
				return ret;
		}

	return nullptr;
}