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
	// idea - state machine, that can be in two states - normal, or state change.
	// or encapsulate this all in a function called 'shit' or something that i can
	// return from.

	// literally anything is better than the current deal.

	// actually no i thought of a worse way of doing it and it involves exceptions

	// oh god im actually entertaining the idea of doing the exception thing.

	setState(entryState);

	Uint64 currentTime{ SDL_GetPerformanceCounter() };
	Uint64 prevTime{ 0 };

	SDL_Event event;
	State* newState{ nullptr };

	_run = true;
	while (_run)
	{
		// why
		if (newState)
		{
			setState(newState);
			newState = nullptr;
		}
		prevTime = currentTime;
		currentTime = SDL_GetPerformanceCounter();

		_deltaTime = static_cast<double>(
			(currentTime - prevTime) * 1000
			/
			static_cast<double>(SDL_GetPerformanceFrequency())
			);
		while (SDL_PollEvent(&event))
		{
			// please no
			if (newState)
				break;

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
				if (newState)
					continue;

				newState = _state->handleEvent(this, event);

				// please just stop
				if (newState)
					continue;

				break;
			}
		}

		// i want this to stop
		if (newState)
			continue;

		newState = _state->actorUpdate(this);

		// what the fuck am i doing with my life
		if (newState)
			continue;

		newState = _state->update(this);

		// i can't believe i thought i was good at programming
		if (newState)
			continue;

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
	if (_state)
		_state->exit(this);
	_state = state;
	_state->enter(this);
}