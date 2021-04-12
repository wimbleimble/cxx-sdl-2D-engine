#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include "State.h"
#include "Button.h"

class Engine;

class PlayState : public State
{
	enum class Layers
	{
		Background,
		Main,
		Ui,
		NUM_LAYERS
	};

public:
	PlayState(Engine* engine);
	~PlayState();

	virtual void enter(Engine* engine);
	virtual State* handleEvent(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);
	virtual void exit(Engine* engine);

};

#endif