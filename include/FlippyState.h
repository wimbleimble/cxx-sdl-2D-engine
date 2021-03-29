#ifndef FLIPPYSTATE_H
#define FLIPPYSTATE_H
#include "State.h"
#include "Sprite.h"

class FlippyState : public State
{

	Sprite fuck;
	Sprite dirs[4];
	Sprite* current;


public:
	FlippyState();
	~FlippyState();

	virtual void enter(Engine* engine);
	virtual void handleInput(SDL_Event event);
	virtual void update(Engine* engine);
	virtual void exit(Engine* engine);

};

#endif