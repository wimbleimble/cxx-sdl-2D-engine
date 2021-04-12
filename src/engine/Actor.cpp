#include "Actor.h"

#include <string>

#include "SDL.h"

#include "Sprite.h"
#include "Camera.h"
#include "Renderer.h"
#include "Input.h"

Actor::Actor(SDL_Renderer* context, const std::string& path)
	: _sprite{ new Sprite(context, path) }, _position{}, _zIndex{ 0 }
{
}

Actor::Actor(Sprite* sprite)
	: _sprite{ sprite }
{
}

Actor::~Actor()
{
	delete _sprite;
}

Sprite* const Actor::sprite() const
{
	return _sprite;
}

Sprite* Actor::sprite()
{
	return _sprite;
}

const Vec2& Actor::position() const
{
	return _position;
}

int Actor::width() const
{
	return _sprite->width();
}

int Actor::height() const
{
	return _sprite->height();
}

Vec2& Actor::position()
{
	return _position;
}

void Actor::setPosition(const Vec2& position)
{
	_position = position;
}

void Actor::setPosition(int x, int y)
{
	setPosition(Vec2(x, y));
}

void Actor::setZIndex(int zIndex)
{
	_zIndex = zIndex;
}

bool Actor::operator > (const Actor& actor) const
{
	return _zIndex > actor._zIndex;
}

void Actor::render(Renderer& renderer,
	const Camera& camera,
	double deltaTime)
{
	const SDL_Rect srcRect{ sprite()->srcRect(deltaTime) };
	const SDL_Rect dstRect{
		(position().x() - width() / 2)
		- (camera.position().x() - renderer.renderWidth() / 2),

		(position().y() - height() / 2)
		- (camera.position().y() - renderer.renderHeight() / 2),

		width(),

		height()
	};
	renderer.renderTexture(sprite()->texture(), srcRect, dstRect);

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