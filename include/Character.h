#ifndef CHARACTER_H
#define CHARACTER_H
#include "Actor.h"

class Character : public Actor
{
	Vec2 _v;
public:
	static constexpr int speed{ 5 };
	Character(SDL_Renderer* context, const std::string& path, int frames);
	~Character();

	virtual void update();
	virtual bool visible() const;
	virtual bool sticky() const;

	const Vec2& v() const;
	void setV(const Vec2& v);
};

#endif