#include "Sprite.h"
#include "Err.h"

//Sprite::Sprite()
//	: _texture{},
//	_width{},
//	_height{}
//{
//}

Sprite::Sprite(const std::string& texturePath, SDL_Renderer* context)
	: _texture{},
	_width{},
	_height{}
{
	loadTexture(texturePath, context);
}

Sprite::~Sprite()
{
}

void Sprite::loadTexture(const std::string& path, SDL_Renderer* context)
{
	SDL_Surface* surface{ IMG_Load(path.c_str()) };

	if (surface == nullptr)
		throw Err(IMG_GetError(), Err::Type::SDLImage);

	_width = surface->w;
	_height = surface->h;

	_texture = SDL_CreateTextureFromSurface(context, surface);
	SDL_FreeSurface(surface);
	if (_texture == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);
}

SDL_Texture* Sprite::texture()
{
	return _texture;
}
