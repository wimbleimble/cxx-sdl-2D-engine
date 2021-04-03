#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include <map>
#include "SDL.h"
#include "SDL_image.h"
#include "Vec2.h"

class Sprite
{
protected:

	SDL_Texture* _texture;
	int _width;
	int _height;
	int _sourceWidth;
	int _sourceHeight;

	SDL_Renderer* _context;
	std::string _path;
	void loadTexture(const std::string& path);

public:

	Sprite() = default;
	Sprite(SDL_Renderer* context,
		const std::string& path);
	Sprite(const Sprite& sprite);

	~Sprite();

	int width() const;
	int height() const;
	int sourceWidth() const;
	int sourceHeight() const;
	SDL_Texture* texture();

	virtual SDL_Rect srcRect(double deltaTime);

	void setWidth(int width);
	void setHeight(int height);

	Sprite& operator=(const Sprite& sprite);
};

#endif