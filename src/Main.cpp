#include <iostream>
#include "LogHandler.h"
#include "Err.h"
#include "Engine.h"
#include "FlippyState.h"

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
		FlippyState flippy{};
		Engine engine{ &flippy };

		return engine.exec();
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
		return 1;
	}
}