#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include <map>

#include "SDL.h"
#include "SDL_image.h"

class Sprite
{
protected:

	SDL_Texture* _texture;
	int _width;
	int _height;

	SDL_Renderer* _context;
	std::string _path;
	void loadTexture(const std::string& path);

public:

	Sprite(SDL_Renderer* context,
		const std::string& path);
	Sprite(const Sprite& sprite);

	~Sprite();

	virtual int width() const;
	virtual int height() const;
	SDL_Texture* texture() const;

	Sprite& operator=(const Sprite& sprite);
};

#endif