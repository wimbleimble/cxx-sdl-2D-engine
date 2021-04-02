#include "Ui.h"

Ui::Ui(SDL_Renderer* context, const std::string& path, int frames)
	: Actor{ context, path, frames }
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

bool Ui::sticky() const
{
	return true;
}