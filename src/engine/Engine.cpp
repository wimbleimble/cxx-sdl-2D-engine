#include "Engine.h"

#include <vector>
#include <iostream>

#include "State.h"

Engine::Engine(const Renderer::WindowParams& windowParams)
	: _sdl{},
	_renderer{ windowParams },
	_input{},
	_state{ nullptr },
	_run{ true }
{
}

Engine::~Engine()
{
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
			case SDL_MOUSEMOTION:
				_input.updateMousePosition();
				break;
			case SDL_KEYDOWN:
				newState = _state->handleEvent(this, event);
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
		_renderer.renderState(_state, _deltaTime);
	}
	_state->exit(this);
	return 0;
}

const Renderer& Engine::renderer() const
{
	return _renderer;
}

Renderer& Engine::renderer()
{
	return _renderer;
}

const Input& Engine::input()
{
	return _input;
}

double Engine::deltaTime() const
{
	return _deltaTime;
}

void Engine::setState(State* state)
{
	std::cout << "Changing state\n";
	if (_state != nullptr)
		_state->exit(this);
	_state = state;
	_state->enter(this);
}