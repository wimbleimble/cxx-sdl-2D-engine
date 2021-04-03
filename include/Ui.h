#ifndef UI_H
#define UI_H
#include "Actor.h"

class Ui : public Actor
{
public:
	Ui(SDL_Renderer* context, const std::string& path);
	~Ui();

	virtual void update();
	virtual bool visible() const;
	virtual bool sticky() const;
};

#endif