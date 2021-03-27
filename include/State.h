#ifndef STATE_H
#define STATE_H 
class Engine;
class State 
{
public:
	virtual ~State() {};

	virtual void enter(Engine* engine) = 0;
	virtual void update(Engine* engine) = 0;
	virtual void exit(Engine* engine) = 0;
};

#endif