#include "Sprite.h"
#include "Err.h"
#include <cassert>
#include <iostream>

Sprite::Sprite(SDL_Renderer* context, const std::string& path, int frames)
	: _frames{ frames },
	_context{ context },
	_animations{},
	_currentAnimation{},
	_frameTimer{},
	_currentFrame{},

	 //set by loadTexture
	_texture{},
	_width{},
	_height{},
	_sourceWidth{},
	_sourceHeight{},
	_path{}
{
	loadTexture(path);
}

Sprite::Sprite(const Sprite& sprite)
	: _frames{ sprite._frames },
	_context{ sprite._context },

	//set by loadTexture
	_texture{},
	_width{},
	_height{},
	_sourceWidth{},
	_sourceHeight{},
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

	_sourceWidth = surface->w;
	_sourceHeight = surface->h;
	_width = surface->w / _frames;
	_height = surface->h;
	if (_texture == nullptr)
		SDL_DestroyTexture(_texture);

	_texture = SDL_CreateTextureFromSurface(_context, surface);
	SDL_FreeSurface(surface);

	if (_texture == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);
}

void Sprite::addAnimation(
	const std::string& name, int startFrame, int length, int frameRate
)
{
	assert(startFrame >= 0);
	assert(startFrame < _frames);
	assert(startFrame + length < _frames);
	Animation animation{ startFrame, length, frameRate };
	_animations.insert(std::pair<std::string, Animation>(name, animation));
}

void Sprite::setAnimation(const std::string& animation)
{
	if (_animations.find(animation) != _animations.end() && animation != _currentAnimation)
	{
		_currentFrame = 0;
		_currentAnimation = animation;
	}

	std::cout << "What.\n";
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

SDL_Rect Sprite::srcRect(double deltaTime)
{
	if (_frames == 1 || _currentAnimation == "")
		return SDL_Rect({ 0, 0, _width, _height });

	_frameTimer += deltaTime;
	std::cout << deltaTime << ", " << _frameTimer << '\n';

	Animation& animation{ _animations[_currentAnimation] };

	if (_frameTimer >= 1000.0 / (double)animation.frameRate)
	{
		++_currentFrame;
		_frameTimer = 0;
	}
	if (_currentFrame >= animation.length)
		_currentFrame = 0;

	return SDL_Rect({
		(_currentFrame + animation.startFrame)* _width, 0, _width, _height
	});
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