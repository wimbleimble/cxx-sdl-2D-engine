#ifndef ACTOR_H
#define ACTOR_H
#include "Sprite.h"
#include "Vec2.h"

class Actor
{

protected:
	Sprite* _sprite;
	Vec2 _position;
	int _zIndex;

	Actor(Sprite* sprite);

public:
	Actor(SDL_Renderer* context, const std::string& path);
	virtual ~Actor();

	virtual void update() = 0;
	virtual bool visible() const = 0;
	virtual bool sticky() const = 0;

	Sprite* const sprite() const;
	const Vec2& position() const;
	int width() const;
	int height() const;

	Vec2& position();
	Sprite* sprite();

	void setPosition(const Vec2& position);
	void setPosition(int x, int y);
	void setZIndex(int zIndex);

	//typecasts
	bool operator > (const Actor& actor) const;
};

#endif