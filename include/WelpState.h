#ifndef WELPSTATE_H
#define WELPSTATE_H
#include "State.h"
#include "Character.h"

class WelpState : public State
{

	Character fuck;

public:
	WelpState(Engine* engine);
	~WelpState();

	virtual void enter(Engine* engine);
	virtual State* handleEvent(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);
	virtual void exit(Engine* engine);

};

#endif