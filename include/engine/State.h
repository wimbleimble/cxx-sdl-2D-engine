#ifndef STATE_H
#define STATE_H 
#include "SDL.h"

#include <vector>

#include "Scene.h"

class Engine;
class State 
{

protected:
	Scene _scene;

public:

	State() = default;
	State(int layers);

	virtual ~State() {};

	virtual void enter(Engine* engine) = 0;
	virtual State* handleInput(Engine* engine, SDL_Event event) = 0;
	virtual State* update(Engine* engine) = 0;
	virtual void exit(Engine* engine) = 0;
	const Scene& scene() const;
};

#endif