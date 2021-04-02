#ifndef SCENE_H
#define SCENE_H
#include "Layer.h"

class Scene
{

	std::vector<Layer> _vec;

public:

	Scene() = default;
	Scene(int layers);

	~Scene();

	int addLayer();
	int numLayers() const;

	Layer& operator [](int index);
	const Layer& operator [](int index) const;

	std::vector<Layer>::iterator begin();
	const std::vector<Layer>::const_iterator begin() const;

	std::vector<Layer>::iterator end();
	const std::vector<Layer>::const_iterator end() const;

};

#endif