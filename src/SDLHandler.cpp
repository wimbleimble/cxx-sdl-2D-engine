#include <iostream>
#include <algorithm>
#include "SDLHandler.h"
#include "Err.h"

SDLHandler::SDLHandler()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw Err(SDL_GetError(), Err::Type::SDL);
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		throw Err(IMG_GetError(), Err::Type::SDLImage);
}
SDLHandler::~SDLHandler()
{
	// this is a potentially dangerous because it leaves dangling pointers but
	// they immediately go out of scope so it shouldnt be a problem
	for (SDL_Window* win : _windows)
		SDL_DestroyWindow(win);
	for (SDL_Surface* surface : _surfaces)
		SDL_FreeSurface(surface);
	for (SDL_Renderer* renderer : _renderers)
		SDL_DestroyRenderer(renderer);

	SDL_Quit();
}

SDL_Window* SDLHandler::createWindow(const char* title , int width, int height)
{
	SDL_Window* win{ SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_SHOWN
	)};
	if (win == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);
	_windows.push_back(win);
	return win;
}

SDL_Renderer* SDLHandler::createRenderer(SDL_Window* window)
{
	SDL_Renderer* renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED) };
	if (renderer == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);
	_renderers.push_back(renderer);
	return renderer;
}

SDL_Surface* SDLHandler::loadSurface(const char* path, SDL_Window* window)
{
	SDL_Surface* unoptimised{ IMG_Load(path) };
	if (unoptimised == nullptr)
		throw Err(IMG_GetError(), Err::Type::SDLImage);

	if (window == nullptr)
	{
		_surfaces.push_back(unoptimised);
		return unoptimised;
	}
	SDL_Surface* optimised{ SDL_ConvertSurface(
		unoptimised,
		SDL_GetWindowSurface(window)->format, 0)
	};
	SDL_FreeSurface(unoptimised);
	if (optimised == nullptr)
		throw Err(IMG_GetError(), Err::Type::SDL);
	
	_surfaces.push_back(optimised);
	return optimised;
}

SDL_Texture* SDLHandler::loadTexture(const char* path, SDL_Renderer* renderer)
{
	SDL_Surface* surface{ loadSurface(path, nullptr) };

	SDL_Texture* texture{ SDL_CreateTextureFromSurface(renderer, surface) };

	freeSurface(surface);
	if (texture == nullptr)
		throw Err(IMG_GetError(), Err::Type::SDL);
	
	_textures.push_back(texture);
	return texture;
}

void SDLHandler::freeSurface(SDL_Surface* surface)
{
	std::vector<SDL_Surface*>::iterator it{
		std::find(_surfaces.begin(), _surfaces.end(), surface)
	};

	if (it == _surfaces.end())
		throw Err("Err erasing surface: Surface not found.", Err::Type::SDLHandler);

	_surfaces.erase(it);
}