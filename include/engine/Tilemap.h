#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>
#include <map>
#include "SDL.h"
#include "SDL_image.h"
#include "Vec2.h"

class Sprite
{
	struct Animation
	{
		int startFrame;
		int length;
		int frameRate;
	};


	SDL_Texture* _texture;
	int _width;
	int _height;
	int _sourceWidth;
	int _sourceHeight;
	int _frames;
	double _frameTimer;
	std::map<std::string, Animation> _animations;
	std::string _currentAnimation;
	int _currentFrame; //relative to animation, not overall spritesheet


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
	SDL_Rect srcRect(double deltaTime);
	SDL_Texture* texture();

	void loadTexture(const std::string& path);
	void setWidth(int width);
	void setHeight(int height);

	void addAnimation(
		const std::string& name, int startFrame, int length, int frameRate
	);
	void setAnimation(const std::string& animation);

	Sprite& operator=(const Sprite& sprite);
};

#endif