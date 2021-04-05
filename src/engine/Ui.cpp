#include "Ui.h"

#include <string>

#include "SDL.h"

#include "Camera.h"

Ui::Ui(SDL_Renderer* context, const std::string& path)
	: Actor{ context, path }
{
}

Ui::~Ui() {}

void Ui::update()
{
}

bool Ui::visible() const
{
	return true;
}

void Ui::render(Renderer& renderer,
	const Camera& camera,
	double deltaTime)
{
	Actor::render(renderer, Camera(), deltaTime);
}