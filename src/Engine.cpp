#include "Engine.h"
#include "Err.h"
#include <vector>
#include <iostream>

Engine::Engine(const WindowParams& windowParams)
	: _sdl{},
	_window{ SDL_CreateWindow(
		windowParams.title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		windowParams.width,
		windowParams.height,
		SDL_WINDOW_SHOWN
	) },
	_state{ nullptr },
	_run{ true }
{
	if (_window == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL); 

	_renderer = SDL_CreateRenderer(_window, 
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (_renderer == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);
}

Engine::~Engine()
{
	SDL_DestroyWindow(_window);
}

int Engine::exec(State* entryState)
{
	setState(entryState);

	Uint64 currentTime{ SDL_GetPerformanceCounter() };
	Uint64 prevTime{ 0 };

	SDL_Event event;
	State* newState{ nullptr };

	_run = true;
	while (_run)
	{
		prevTime = currentTime;
		currentTime = SDL_GetPerformanceCounter();

		_deltaTime = static_cast<double>(
			(currentTime - prevTime) * 1000
			/
			static_cast<double>(SDL_GetPerformanceFrequency())
		);
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					_run = false;
					continue;
				case SDL_KEYDOWN:
					newState = _state->handleInput(this, event);
					break;
			}
		} 
		if (newState != nullptr)
		{
			setState(newState);
			newState = nullptr;
			continue;
		}

		newState = _state->update(this);

		if (newState != nullptr)
		{
			setState(newState);
			newState = nullptr;
			continue;
		}
		render();
	}
	_state->exit(this);
	return 0;
}

SDL_Renderer* Engine::renderer()
{
	return _renderer;
}

double Engine::deltaTime() const
{
	return _deltaTime;
}

void Engine::setState(State* state)
{
	std::cout << "Changing state\n";
	if (_state == nullptr)
		_state = state;
	else
	{
		_state->exit(this);
		_state = state;
	}
	_state->enter(this);
}

void Engine::render()
{
	SDL_RenderClear(_renderer);
	for(Actor* actor : _state->actors())
	{
		SDL_Rect srcRect{ actor->sprite().srcRect(_deltaTime) };
		SDL_Rect dstRect{
			actor->position().x(),
			actor->position().y(),
			actor->sprite().width(),
			actor->sprite().height()
		};

		SDL_RenderCopy(
			_renderer,
			actor->sprite().texture(),
			&srcRect,
			&dstRect
		);
	}
	SDL_RenderPresent(_renderer);
}