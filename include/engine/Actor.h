#ifndef ACTOR_H
#define ACTOR_H
#include <string>

#include "SDL.h"

#include "Vec2.h"

class Sprite;
class Engine;
class Renderer;
class Camera;
class State;
class Input;

class Actor
{

protected:
	Vec2 _position;
	int _width;
	int _height;
	int _zIndex;

public:
	Actor() = default;
	Actor(int width, int height);
	virtual ~Actor();

	virtual State* handleEvent(Engine* engine, SDL_Event event) = 0;
	virtual State* update(Engine* engine) = 0;
	virtual bool visible() const;

	const Vec2& position() const;
	int width() const;
	int height() const;
	int zIndex() const;

	bool mouseOver(const Renderer& renderer,
		const Input& input,
		const Camera& camera) const;

	virtual void render(Renderer& renderer,
		const Camera& camera,
		double deltaTime) = 0;

	void setPosition(const Vec2& position);
	void setPosition(int x, int y);
	void setZIndex(int zIndex);

	bool operator > (const Actor& actor) const;
};

#endif