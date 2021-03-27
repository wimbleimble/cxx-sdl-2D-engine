#ifndef RENDERER_H
#define RENDERER_H
#include "SDL.h"

class Renderer
{
	SDL_Renderer* _renderer;

public:
	Renderer() = delete;
	Renderer(SDL_Window* window);
	~Renderer();

	SDL_Renderer* renderer();

};

#endif