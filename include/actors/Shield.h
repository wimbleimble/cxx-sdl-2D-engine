#ifndef SHEILD_H 
#define SHEILD_H
#include <string>

#include "SDL.h"

#include "AnimatedActor.h"


class Shield : public AnimatedActor
{
public:

	enum class Direction
	{
		Up,
		Down,
		Left,
		Right,
		Num
	};

private:

	Direction _direction;
	int _transitionCounter;

public:
	Shield(SDL_Renderer* context);
	~Shield();

	virtual State* handleEvent(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);

	void setDirection(Direction direction);

	const Vec2& v() const;
	void setV(const Vec2& v);
};

#endif