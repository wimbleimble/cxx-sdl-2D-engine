#ifndef UI_H
#define UI_H
#include "AnimatedActor.h"

class Ui : public AnimatedActor
{
public:
	Ui(SDL_Renderer* context,
		const std::string& path,
		int width,
		int height,
		int frames);
	virtual ~Ui();

	virtual void render(Renderer& renderer,
		const Camera& camera,
		double deltaTime);
};

#endif