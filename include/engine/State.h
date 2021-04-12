#ifndef STATE_H
#define STATE_H 
#include "SDL.h"

#include <vector>

#include "Scene.h"
#include "Camera.h"

class Engine;

class State
{

protected:
	Scene _scene;
	Camera _camera;

public:

	State() = delete;
	State(int layers = 1);

	virtual ~State() {};

	virtual void enter(Engine* engine) = 0;
	State* handleActorEvent(Engine* engine, SDL_Event event);
	virtual State* handleEvent(Engine* engine, SDL_Event event) = 0;
	State* actorUpdate(Engine* engine);
	virtual State* update(Engine* engine) = 0;
	virtual void exit(Engine* engine) = 0;
	const Scene& scene() const;
	const Camera& camera() const;
};

#endif