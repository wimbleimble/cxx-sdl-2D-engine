#include "Ui.h"

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

bool Ui::sticky() const
{
	return true;
}