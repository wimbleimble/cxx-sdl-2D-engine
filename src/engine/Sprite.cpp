#include "Sprite.h"

#include <cassert>
#include <iostream>

#include "Err.h"

Sprite::Sprite(SDL_Renderer* context, const std::string& path)
	: _context{ context },
	_texture{},
	_width{},
	_height{},
	_path{}
{
	loadTexture(path);
}

Sprite::Sprite(const Sprite& sprite)
	: _context{ sprite._context },
	_texture{},
	_width{},
	_height{},
	_path{}
{
	loadTexture(sprite._path);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(_texture);
}

void Sprite::loadTexture(const std::string& path)
{
	SDL_Surface* surface{ IMG_Load(path.c_str()) };
	_path = path;

	if (surface == nullptr)
		throw Err(IMG_GetError(), Err::Type::SDLImage);

	_width = surface->w;
	_height = surface->h;
	if (_texture != nullptr)
		SDL_DestroyTexture(_texture);

	_texture = SDL_CreateTextureFromSurface(_context, surface);
	SDL_FreeSurface(surface);

	if (_texture == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);
}

SDL_Texture* Sprite::texture() const
{
	return _texture;
}

int Sprite::width() const
{
	return _width;
}

int Sprite::height() const
{
	return _height;
}

Sprite& Sprite::operator=(const Sprite& sprite)
{
	_context = sprite._context;
	loadTexture(sprite._path);
	_width = sprite._width;
	_height = sprite._height;
	return *this;
}