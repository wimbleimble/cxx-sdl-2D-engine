#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Vec2.h"

class Sprite
{
	SDL_Texture* _texture;
	int _width;
	int _height;
	int _sourceWidth;
	int _sourceHeight;
	int _frames;

	//these are two things i do not really want to store but its kinda
	//necessary for the copy constructor
	SDL_Renderer* _context;
	std::string _path;

public:

	Sprite() = default;
	Sprite(SDL_Renderer* context,
		const std::string& path,
		int frames = 1);
	Sprite(const Sprite& sprite);

	~Sprite();
	
	int width() const;
	int height() const;
	int sourceWidth() const;
	int sourceHeight() const;
	SDL_Texture* texture();

	void loadTexture(const std::string& path);
	void setWidth(int width);
	void setHeight(int height);

	Sprite& operator=(const Sprite& sprite);
};

#endif