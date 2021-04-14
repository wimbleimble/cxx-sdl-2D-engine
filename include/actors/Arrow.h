#ifndef ARROW_H
#define ARROW_H
#include <string>

#include "SDL.h"

#include "Actor.h"

class AnimatedSprite;

class Arrow : public Actor
{
	Vec2 _v;
public:
	Arrow(SDL_Renderer* context,
		const std::string& path,
		int width,
		int height,
		int frames,
		Vec2 velocity);
	~Arrow();


	virtual State* handleEvent(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);
	virtual bool visible() const;

	Sprite* sprite();

	AnimatedSprite* animatedSprite();

	const Vec2& v() const;
	void setV(const Vec2& v);
};

#endif