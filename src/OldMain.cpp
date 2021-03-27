#include <iostream>
#include <fstream>
#include "SDLHandler.h"
#include "Err.h"

class LogHandler //scoped handler that opens a log file and directs cout to it.
{
	std::ofstream log;
public:
	LogHandler()
		: log{ "log" }
	{

		log.open("test.txt", std::ofstream::out | std::ofstream::trunc);
		std::cout.rdbuf(log.rdbuf());
	}

	~LogHandler()
	{
		log.close();
	}
};

enum class DirectionTexture 
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NUM_DIR
};

int main(int argc, char* args[])
{
	LogHandler logHandler{};
	try
	{
		SDLHandler sdl{};
		SDL_Window* win{ sdl.createWindow("Fuck", 640, 480) };
		SDL_Renderer* renderer{ sdl.createRenderer(win) };
		SDL_Texture* fuck{ sdl.loadTexture("fuck.png", renderer) };
		SDL_Texture* currentTexture{ fuck };
		SDL_Texture* directionTextures[(int)DirectionTexture::NUM_DIR];
		directionTextures[(int)DirectionTexture::DOWN] = sdl.loadTexture("down.png", renderer);
		directionTextures[(int)DirectionTexture::UP] = sdl.loadTexture("up.png", renderer);
		directionTextures[(int)DirectionTexture::LEFT] = sdl.loadTexture("left.png", renderer);
		directionTextures[(int)DirectionTexture::RIGHT] = sdl.loadTexture("right.png", renderer);

		bool run{ true };
		SDL_Event event{};
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
						switch (event.key.keysym.sym)
						{
							case SDLK_UP:
								std::cout << "up pressed\n";
								currentTexture = directionTextures[(int)DirectionTexture::UP];
								break;
							case SDLK_DOWN:
								std::cout << "down pressed\n";
								currentTexture = directionTextures[(int)DirectionTexture::DOWN];
								break;
							case SDLK_LEFT:
								std::cout << "left pressed\n";
								currentTexture = directionTextures[(int)DirectionTexture::LEFT];
								break;
							case SDLK_RIGHT:
								std::cout << "right pressed\n";
								currentTexture = directionTextures[(int)DirectionTexture::RIGHT];
								break;
						}
						break;
				}
			}
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, currentTexture, nullptr, nullptr);
			SDL_RenderPresent(renderer);
		}
	}
	catch (const Err& err)
	{
		switch (err.type())
		{
			//maybe replace with lookup table?
			case Err::Type::SDL:
				std::cout << "SDL Err: " << err.info() << '\n';
				break;
			case Err::Type::SDLImage:
				std::cout << "SDL Image Err: " << err.info() << '\n';
				break;
			case Err::Type::SDLHandler:
				std::cout << "SDLHandler Err: " << err.info() << '\n';
			default:
				std::cout << "Unknown error, info: " << err.info() << '\n';
		}
	}

	return 0;
}