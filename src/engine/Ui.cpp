#include "Ui.h"

#include <string>

#include "SDL.h"

#include "Camera.h"
#include "Renderer.h"

Ui::Ui(SDL_Renderer* context, const std::string& path)
	: Actor{ context, path }
{
}

Ui::Ui(Sprite* sprite)
	: Actor{ sprite }
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
	Actor::render(renderer,
		Camera(),
		deltaTime);
}