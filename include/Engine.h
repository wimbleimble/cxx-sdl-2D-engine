#ifndef ENGINE_H 
#define ENGINE_H
#include "SDL.h"
#include "SDLHandler.h"
#include <vector>
#include <string>
#include "Renderer.h"
#include "Sprite.h"
#include "State.h"

class Engine
{
public:
	struct WindowParams
	{
		std::string title;
		int width;
		int height;
	};

private:
	const SDLHandler _sdl;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	State* _state;

public:
	Engine() = delete;
	Engine(State* entryState, const WindowParams& windowParams = {"Piss", 640, 480});
	~Engine();

	void setState(State* state);
	SDL_Renderer* renderer();

	int exec();
};

#endif