#ifndef FLIPPYSTATE_H
#define FLIPPYSTATE_H
#include "State.h"
#include "Character.h"
#include "Ui.h"

class FlippyState : public State
{

	Character vriska;
	Character karkat;
	Ui smiley;

	enum class Layers
	{
		BACKGROUND,
		OBJECTS,
		UI,
		MAX_LAYERS

	};

public:
	FlippyState(Engine* engine);
	~FlippyState();

	virtual void enter(Engine* engine);
	virtual State* handleEvent(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);
	virtual void exit(Engine* engine);

};

#endif