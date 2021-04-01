#ifndef ACTOR_H
#define ACTOR_H
#include "Sprite.h"
#include "Vec2.h"

class Actor
{
	
protected:
	Sprite _sprite;
	Vec2 _position;
	int _zIndex;

public:
	Actor(SDL_Renderer* context, const std::string& path, int frames = 1);
	virtual ~Actor() {};

	virtual void update() = 0;
	virtual bool visible() const = 0;

	const Sprite& sprite() const;
	const Vec2& position() const;
	
	Vec2& position();
	Sprite& sprite();

	void setPosition(const Vec2& position);
	void setZIndex(int zIndex);

	//typecasts
	bool operator > (const Actor& actor) const;
};

#endif