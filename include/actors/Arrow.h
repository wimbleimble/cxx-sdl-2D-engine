#ifndef ARROW_H
#define ARROW_H
#include <string>

#include "SDL.h"

#include "AnimatedActor.h"


class Arrow : public AnimatedActor
{
public:

	enum class Direction
	{
		LeftRight,
		TopBottom,
		RightLeft,
		BottomTop,
		Num
	};

private:
	double _speed;
	Direction _direction;

	inline static constexpr int velocityLookup[(int)Direction::Num][2]{
		{1, 0}, {0, 1}, {-1, 0}, {0, -1} };

public:
	Arrow(SDL_Renderer* context,
		const std::string& path,
		int width,
		int height,
		int frames,
		Direction direction,
		double speed);
	~Arrow();


	virtual State* handleEvent(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);

	const Vec2& v() const;
	void setV(const Vec2& v);
};

#endif