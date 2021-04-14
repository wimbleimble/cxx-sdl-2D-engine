#include "Actor.h"

#include <string>

#include "SDL.h"

#include "Sprite.h"
#include "Camera.h"
#include "Renderer.h"
#include "Input.h"

Actor::Actor(int width, int height)
	: _position{},
	_width{ width },
	_height{ height },
	_angle{},
	_flip{ SDL_FLIP_NONE },
	_zIndex{}
{
}

Actor::~Actor()
{
}

bool Actor::visible() const { return false; }

const Vec2& Actor::position() const { return _position; }
int Actor::width() const { return _width; }
int Actor::height() const { return _height; }
double Actor::angle() const { return _angle; }
SDL_RendererFlip Actor::flip() const { return _flip; }
int Actor::zIndex() const { return _zIndex; }

void Actor::setPosition(const Vec2& position)
{
	_position = position;
}

void Actor::setPosition(int x, int y)
{
	setPosition(Vec2(x, y));
}

void Actor::setWidth(int width)
{
	_width = width;
}

void Actor::setHeight(int height)
{
	_height = height;
}

void Actor::setAngle(double angle)
{
	_angle = angle;
}

void Actor::setFlip(SDL_RendererFlip flip)
{
	_flip = flip;
}

void Actor::setZIndex(int zIndex)
{
	_zIndex = zIndex;
}

bool Actor::mouseOver(const Renderer& renderer,
	const Input& input,
	const Camera& camera) const
{
	int viewportXPos{
		(position().x() - width() / 2)
		- (camera.position().x() - renderer.renderWidth() / 2)
	};
	int viewportYPos{
		(position().y() - height() / 2)
		- (camera.position().y() - renderer.renderHeight() / 2)
	};
	return input.mousePosition().x() >= viewportXPos
		&& input.mousePosition().x() <= viewportXPos + width()
		&& input.mousePosition().y() >= viewportYPos
		&& input.mousePosition().y() <= viewportYPos + height();

}

bool Actor::operator > (const Actor& actor) const
{
	return _zIndex > actor._zIndex;
}