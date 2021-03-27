#include "FlippyState.h"
#include "Engine.h"
#include <iostream>


FlippyState::FlippyState()
	: fuck{}, dirs{}, current{ nullptr }
{
}

FlippyState::~FlippyState() {}

//maybe reimpliment with constructor??
void FlippyState::enter(Engine* engine)
{
	std::cout << "Entered State.\n";
	fuck = Sprite("fuck.png", engine->renderer());

	dirs[0] = Sprite("up.png", engine->renderer());
	dirs[1] = Sprite("down.png", engine->renderer());
	dirs[2] = Sprite("left.png", engine->renderer());
	dirs[3] = Sprite("right.png", engine->renderer());
		
	current = &fuck;
}

void FlippyState::update(Engine* engine)
{
	std::cout << "updating state.\n";
	bool run{ true };
	SDL_Event event;
	while (run)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
						run = false;
						break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
						case SDLK_UP:
							std::cout << "up pressed\n";
							current = &dirs[0];
							break;
						case SDLK_DOWN:
							std::cout << "down pressed\n";
							current = &dirs[1];
							break;
						case SDLK_LEFT:
							std::cout << "left pressed\n";
							current = &dirs[2];
							break;
						case SDLK_RIGHT:
							std::cout << "right pressed\n";
							current = &dirs[3];
							break;
					}
					break;
			}
		} 
		SDL_RenderClear(engine->renderer());
		SDL_RenderCopy(engine->renderer(), current->texture(), nullptr, nullptr);
		SDL_RenderPresent(engine->renderer());
	}
}

void FlippyState::exit(Engine* engine)
{
	std::cout << "Exitingstate.\n";
}