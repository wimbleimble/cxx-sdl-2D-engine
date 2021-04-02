#include "Scene.h"

Scene::Scene(int layers)
{
	for (int i{ 0 }; i < layers; ++i)
		_vec.push_back(Layer());
}

Scene::~Scene() {}

int Scene::numLayers() const
{
	return _vec.size();
}

int Scene::addLayer()
{
	_vec.push_back(Layer());
	return numLayers() - 1;
}

Layer& Scene::operator[] (int index)
{
	return _vec[index];
}

const Layer& Scene::operator[] (int index) const
{
	return _vec[index];
}

std::vector<Layer>::iterator Scene::begin()
{
	return _vec.begin();
}

const std::vector<Layer>::const_iterator Scene::begin() const
{
	return _vec.begin();
}

std::vector<Layer>::iterator Scene::end()
{
	return _vec.end();
}

const std::vector<Layer>::const_iterator Scene::end() const
{
	return _vec.end();
}