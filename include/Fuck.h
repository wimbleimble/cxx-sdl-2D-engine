#ifndef FUCK_H
#define FUCK_H
#include "Actor.h"
#include "Sprite.h"

class Fuck : public Actor
{
	Vec2 _v;
public:
	static constexpr int speed{ 5 };
	Fuck(SDL_Renderer* context, const std::string& path, int frames);
	~Fuck();

	virtual void update();
	virtual bool visible() const;

	const Vec2& v() const;
	void setV(const Vec2& v);
};

#endif