#include <iostream>
#include "LogHandler.h"
#include "Err.h"
#include "Engine.h"
#include "MenuState.h"

int main(int argc, char* args[])
{
	LogHandler logHandler{};
	try
	{
		Engine engine{ Renderer::WindowParams{
			"oh wow its just the undyne fight from undertale",
			720, 720},
		Renderer::RenderParams{180, 180}
		};
		return engine.exec(new MenuState(&engine));
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
			break;
		default:
			std::cout << "Unknown error, info: " << err.info() << '\n';
		}
		return 1;
	}
}