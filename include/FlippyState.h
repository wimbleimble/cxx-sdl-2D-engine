#ifndef FLIPPYSTATE_H
#define FLIPPYSTATE_H
#include "State.h"
#include "Fuck.h"
#include "Sprite.h"

class FlippyState : public State
{

	Fuck fuck;


public:
	FlippyState(Engine* engine);
	~FlippyState();

	virtual void enter(Engine* engine);
	virtual State* handleInput(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);
	virtual void exit(Engine* engine);

};

#endif