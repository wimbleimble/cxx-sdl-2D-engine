#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H
#include <vector>
#include "SDL.h"
#include "SDL_Image.h"

class SDLHandler
{
	std::vector<SDL_Window*> _windows;
	std::vector<SDL_Surface*> _surfaces;
	std::vector<SDL_Renderer*> _renderers;
	std::vector<SDL_Texture*> _textures;
public:
	SDLHandler();
	~SDLHandler();

	SDL_Window* createWindow(const char* title, int width, int height);
	SDL_Renderer* createRenderer(SDL_Window* window);
	SDL_Surface* loadSurface(const char* path, SDL_Window* window = nullptr);
	SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer);

	void freeSurface(SDL_Surface* surface);
};

#endif