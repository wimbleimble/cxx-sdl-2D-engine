#ifndef LAYER_H 
#define LAYER_H
#include <vector>

class Actor;

class Layer
{
	std::vector<Actor*> _vec;

public:
	Layer() = default;
	Layer(const Layer& layer);
	~Layer();

	Actor* addActor(Actor* actor);
	void removeActor(Actor* actor);
	void sort();

	std::vector<Actor*>::iterator begin();
	const std::vector<Actor*>::const_iterator begin() const;
	std::vector<Actor*>::iterator end();
	const std::vector<Actor*>::const_iterator end() const;

	Layer& operator = (const Layer&) = delete; //see copy constructor above.

};

#endif