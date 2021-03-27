#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>
#include "SDL.h"
#include "SDLHandler.h"
#include "Vec2.h"

class Sprite
{
	SDL_Texture* _texture;
	int _width;
	int _height;
	//Vec2<> _position;

public:

	Sprite() = default;
	Sprite(const std::string& texturePath, SDL_Renderer* context);

	~Sprite();
	
	int width() const;
	int height() const;
	Vec2<> position() const;
	SDL_Texture* texture();

	void loadTexture(const std::string&, SDL_Renderer* context);
	void setWidth(int width);
	void setHeight(int height);
	void setPosition(int x, int y);
	void setPosition(Vec2<> position);

};

#endif