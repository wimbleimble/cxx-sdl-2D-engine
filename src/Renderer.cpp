#include "Renderer.h"
#include "Err.h"

Renderer::Renderer(SDL_Window* window)
	: _renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED) }
{
	if (_renderer == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(_renderer);
}

SDL_Renderer* Renderer::renderer()
{
	return _renderer;
}