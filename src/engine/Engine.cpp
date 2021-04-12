#include "Engine.h"

#include <vector>
#include <iostream>

#include "State.h"

Engine::Engine(const Renderer::WindowParams& windowParams,
	const Renderer::RenderParams& renderParams)
	: _sdl{},
	_renderer{ windowParams, renderParams },
	_input{ _renderer.widthScale(), _renderer.heightScale() },
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
				_input.updateMousePosition(_renderer.widthScale(),
					_renderer.heightScale());
				break;
			case SDL_KEYDOWN:
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
				// this is the ugliest fucking thing i have ever written and i
				// have no idea what to do with it.
				newState = _state->handleActorEvent(this, event);
				if (newState != nullptr)
				{
					setState(newState);
					newState = nullptr;
					continue;
				}
				newState = _state->handleEvent(this, event);
				if (newState != nullptr)
				{
					setState(newState);
					newState = nullptr;
					continue;
				}
				break;
			}
		}

		// what the fuck am i doing with my life

		newState = _state->actorUpdate(this);

		if (newState != nullptr)
		{
			setState(newState);
			newState = nullptr;
			continue;
		}

		// i can't believe i thought i was good at programming

		newState = _state->update(this);

		if (newState != nullptr)
		{
			setState(newState);
			newState = nullptr;
			continue;
		}

		// i don't believe in a god or any sort of afterlife but i do believe i
		// am going to hell for this.

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

State* Engine::state()
{
	return _state;
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