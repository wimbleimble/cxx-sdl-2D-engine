#ifndef LAYER_H 
#define LAYER_H
#include <vector>
#include "Actor.h"

class Layer
{
	std::vector<Actor*> _vec;

	void sort();
public:
	Layer() = default;
	~Layer();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);

	std::vector<Actor*>::iterator begin();
	const std::vector<Actor*>::const_iterator begin() const;
	std::vector<Actor*>::iterator end();
	const std::vector<Actor*>::const_iterator end() const;

};

#endif