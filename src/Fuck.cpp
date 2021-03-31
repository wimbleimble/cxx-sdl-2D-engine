#include "Fuck.h"

Fuck::Fuck(SDL_Renderer* context, const std::string& path)
	: Actor{ context, path }, _v{}
{
}

Fuck::~Fuck() {}

void Fuck::update()
{
}

bool Fuck::visible() const
{
	return true;
}

const Vec2& Fuck::v() const
{
	return _v;
}

void Fuck::setV(const Vec2& v)
{
	_v = v;
}