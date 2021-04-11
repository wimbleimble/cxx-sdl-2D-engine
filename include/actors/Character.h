#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

#include "SDL.h"

#include "Actor.h"

class AnimatedSprite;

class Character : public Actor
{
	Vec2 _v;
public:
	static constexpr int speed{ 5 };
	Character(SDL_Renderer* context,
		const std::string& path,
		int width,
		int height,
		int frames);
	~Character();

	virtual void update();
	virtual bool visible() const;

	Sprite* sprite();

	AnimatedSprite* animatedSprite();

	const Vec2& v() const;
	void setV(const Vec2& v);
};

#endif