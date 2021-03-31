#include "Sprite.h"
#include "Err.h"

Sprite::Sprite(SDL_Renderer* context, const std::string& path, int frames)
	: _texture{},
	_width{},
	_height{},
	_sourceWidth{},
	_sourceHeight{},
	_frames{ frames },
	_context{ context },
	_path{} //set by loadTexture
{
	loadTexture(path);
}

Sprite::Sprite(const Sprite& sprite)
	: _texture{},
	_width{ sprite._width },
	_height{ sprite._height },
	_sourceWidth{ sprite._sourceWidth },
	_sourceHeight{ sprite._sourceHeight },
	_frames{ sprite._frames },
	_context{ sprite._context },
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
	_sourceWidth = surface->w;
	_sourceHeight = surface->h;

	if (_texture == nullptr)
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

Sprite& Sprite::operator=(const Sprite& sprite)
{
	_width = sprite._width;
	_height = sprite._height;
	_sourceWidth = sprite._sourceWidth;
	_sourceHeight = sprite._sourceHeight;
	_frames = sprite._frames;
	_context = sprite._context;
	loadTexture(sprite._path);
	return *this;
}