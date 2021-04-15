#include "Layer.h"

#include <algorithm>
#include <cassert>

#include "Actor.h"

// ugh i guess i have to learn move semantics already
Layer::Layer(const Layer& layer)
{
}

Layer::~Layer()
{
	for (Actor* actor : _vec)
		delete actor;
}

void Layer::sort()
{
	std::sort(_vec.begin(), _vec.end(), [](Actor* a, Actor* b) {
		return *b > *a;
		});
}

Actor* Layer::addActor(Actor* actor)
{
	_vec.push_back(actor);
	sort();
	return actor;
}

void Layer::removeActor(Actor* actor)
{
	auto it{ std::find(_vec.begin(), _vec.end(), actor) };
	assert(it != _vec.end());

	_vec.erase(it);
}


std::vector<Actor*>::iterator Layer::begin()
{
	return _vec.begin();
}

const std::vector<Actor*>::const_iterator Layer::begin() const
{
	return _vec.begin();
}

std::vector<Actor*>::iterator Layer::end()
{
	return _vec.end();
}

const std::vector<Actor*>::const_iterator Layer::end() const
{
	return _vec.end();
}