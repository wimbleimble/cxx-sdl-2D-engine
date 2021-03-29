#include "Engine.h"
#include "Err.h"
#include <vector>
#include <iostream>

Engine::Engine(State* entryState, const WindowParams& windowParams)
	: _sdl{},
	_window{ SDL_CreateWindow(
		windowParams.title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		windowParams.width,
		windowParams.height,
		SDL_WINDOW_SHOWN
	) },
	_renderer{},
	_state{entryState}
{
	if (_window == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);
}

Engine::~Engine()
{
	SDL_DestroyWindow(_window);
}

int Engine::exec()
{
	_state->enter(this);
	bool run{ true };
	SDL_Event event;
	while(run)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					run = false;
					break;
				case SDL_KEYDOWN:
					_state->handleInput(event);
					break;
			}
		} 
		if(run)
			_state->update(this);
	}
	_state->exit(this);
	return 0;
}

SDL_Renderer* Engine::renderer()
{
	return _renderer;
}

void Engine::setState(State* state)
{
}