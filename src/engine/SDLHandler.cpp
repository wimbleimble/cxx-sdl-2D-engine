#include "SDLHandler.h"
#include "SDL.h"
#include "SDL_Image.h"
#include "Err.h"

SDLHandler::SDLHandler()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw Err(SDL_GetError(), Err::Type::SDL);
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		throw Err(IMG_GetError(), Err::Type::SDLImage);
}
SDLHandler::~SDLHandler()
{
	SDL_Quit();
	IMG_Quit();
}