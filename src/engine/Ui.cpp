#include "Ui.h"

#include <string>

#include "SDL.h"

#include "Camera.h"
#include "Renderer.h"

Ui::Ui(SDL_Renderer* context,
	const std::string& path,
	int width,
	int height,
	int frames)
	: AnimatedActor{ context, path, width, height, frames }
{
}

Ui::~Ui() {}

void Ui::render(Renderer& renderer,
	const Camera& camera,
	double deltaTime)
{
	AnimatedActor::render(renderer,
		Camera(),
		deltaTime);
}