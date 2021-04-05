#include "Sprite.h"

#include <cassert>
#include <iostream>

#include "Err.h"

Sprite::Sprite(SDL_Renderer* context, const std::string& path)
	: _context{ context },
	_texture{},
	_width{},
	_height{},
	_sourceWidth{},		// set in loadTexture
	_sourceHeight{},	// diito
	_path{}				// ditto
{
	loadTexture(path);
	_width = _sourceWidth;
	_height = _sourceHeight;
}

Sprite::Sprite(const Sprite& sprite)
	: _context{ sprite._context },
	_texture{},
	_width{},
	_height{},
	_sourceWidth{},		// set in loadTexture
	_sourceHeight{},	// ditto
	_path{}				// ditto
{
	loadTexture(sprite._path);
	_width = _sourceWidth;
	_height = _sourceHeight;
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

	_sourceWidth = surface->w;
	_sourceHeight = surface->h;
	if (_texture != nullptr)
		SDL_DestroyTexture(_texture);

	_texture = SDL_CreateTextureFromSurface(_context, surface);
	SDL_FreeSurface(surface);

	if (_texture == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);
}

SDL_Texture* Sprite::texture()
{
	return _texture;
}

int Sprite::sourceWidth() const
{
	return _sourceWidth;
}

int Sprite::sourceHeight() const
{
	return _sourceHeight;
}

int Sprite::width() const
{
	return _width;
}

int Sprite::height() const
{
	return _height;
}

SDL_Rect Sprite::srcRect(double deltaTime)
{
	return SDL_Rect({ 0, 0, _width, _height });
}

Sprite& Sprite::operator=(const Sprite& sprite)
{
	_context = sprite._context;
	loadTexture(sprite._path);
	_width = sprite._width;
	_height = sprite._height;
	return *this;
}