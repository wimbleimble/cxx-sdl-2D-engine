#ifndef ENGINE_H 
#define ENGINE_H
#include "SDL.h"

#include <vector>
#include <string>

#include "SDLHandler.h"
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
	bool _run;

	void setState(State* state);

	void render();

public:
	Engine(const WindowParams& windowParams = {"Title", 640, 480});
	~Engine();

	SDL_Renderer* renderer();

	int exec(State* entryState);
};

#endif