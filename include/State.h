#ifndef STATE_H
#define STATE_H 
#include "SDL.h"

class Engine;
class State 
{
public:
	virtual ~State() {};

	virtual void enter(Engine* engine) = 0;
	virtual void update(Engine* engine) = 0;
	virtual void handleInput(SDL_Event event) = 0;
	virtual void exit(Engine* engine) = 0;
};

#endif