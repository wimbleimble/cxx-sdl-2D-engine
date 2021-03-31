#ifndef WELPSTATE_H
#define WELPSTATE_H
#include "State.h"
#include "Fuck.h"

class WelpState : public State
{

	Fuck fuck;
	
public:
	WelpState(Engine* engine);
	~WelpState();

	virtual void enter(Engine* engine);
	virtual State* handleInput(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);
	virtual void exit(Engine* engine);

};

#endif