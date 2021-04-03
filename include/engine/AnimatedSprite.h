#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include "Sprite.h"
#include <string>
#include <map>
#include "SDL.h"
#include "SDL_image.h"
#include "Vec2.h"

class AnimatedSprite : public Sprite
{
	struct Animation
	{
		int startFrame;
		int length;
		int frameRate;
	};

	int _frames;
	double _frameTimer;
	std::map<std::string, Animation> _animations;
	std::string _currentAnimation;
	int _currentFrame; //relative to animation, not overall spritesheet

public:

	AnimatedSprite() = default;
	AnimatedSprite(SDL_Renderer* context,
		const std::string& path,
		int width,
		int height,
		int frames);
	AnimatedSprite(const AnimatedSprite& sprite);

	~AnimatedSprite();

	virtual SDL_Rect srcRect(double deltaTime);

	void addAnimation(
		const std::string& name, int startFrame, int length, int frameRate
	);
	void setAnimation(const std::string& animation);

	AnimatedSprite& operator=(const AnimatedSprite& sprite);
};

#endif