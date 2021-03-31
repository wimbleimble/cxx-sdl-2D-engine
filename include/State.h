#ifndef STATE_H
#define STATE_H 
#include "SDL.h"

#include <vector>

#include "Actor.h"

class Engine;
class State 
{
protected:
	std::vector<Actor*> _actors;
	State() = default;

public:
	virtual ~State() {};

	virtual void enter(Engine* engine) = 0;
	virtual State* handleInput(Engine* engine, SDL_Event event) = 0;
	virtual State* update(Engine* engine) = 0;
	virtual void exit(Engine* engine) = 0;
	const std::vector<Actor*>& actors() const;
};

#endif