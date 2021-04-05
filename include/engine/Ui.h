#ifndef UI_H
#define UI_H
#include "Actor.h"

class Ui : public Actor
{
public:
	Ui(SDL_Renderer* context, const std::string& path);
	~Ui();

	virtual void update();
	virtual void render(Renderer& renderer,
		const Camera& camera,
		double deltaTime);
	virtual bool visible() const;
};

#endif