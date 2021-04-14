#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <string>

#include "SDL.h"

#include "Sprite.h"

class Animator
{
	struct Animation
	{
		int startFrame;
		int length;
		int frameRate;
	};

	Sprite _sprite;

	int _width;
	int _height;
	int _frames;
	double _frameTimer;
	std::map<std::string, Animation> _animations;
	std::string _currentAnimation;
	int _currentFrame; // relative to animation not overall spritesheet

public:
	Animator(SDL_Renderer* context,
		const std::string& path,
		int width,
		int height,
		int frames);

	// i can't see any reason why you would want to copy this so im just deleting
	// it in case i do by accident, might implement later
	Animator(const Animator& animator) = delete;
	~Animator();

	const Sprite& sprite() const;
	const std::string& currentAnimation() const;
	int currentFrame() const;

	SDL_Rect srcRect(double deltaTime);

	void addAnimation(
		const std::string& name, int startFrame, int length, int frameRate);
	void setAnimation(const std::string& animation);

};

#endif