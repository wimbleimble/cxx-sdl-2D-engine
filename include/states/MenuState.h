#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "State.h"
#include "Button.h"

class Engine;

class MenuState : public State
{

	Button* _startButton;
	bool _start;

public:
	MenuState(Engine* engine);
	~MenuState();

	virtual void enter(Engine* engine);
	virtual State* handleEvent(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);
	virtual void exit(Engine* engine);

	void startCallback(Engine* engine);

};

#endif