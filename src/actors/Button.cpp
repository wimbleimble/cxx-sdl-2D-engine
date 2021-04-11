#include "Button.h"
#include "AnimatedSprite.h"
#include "Renderer.h"
#include "Input.h"
#include "Camera.h"

Button::Button(SDL_Renderer* context,
	const std::string& path,
	int width,
	int height,
	int frames)
	: Ui{ new AnimatedSprite(context, path, width, height, frames) }
{
	animatedSprite()->addAnimation("Normal", 0, 1, 15);
	animatedSprite()->addAnimation("Hover", 1, 1, 15);
	animatedSprite()->addAnimation("Clicked", 2, 1, 15);
}

Button::~Button() {}

void Button::update()
{
}

bool Button::visible() const
{
	return true;
}

bool Button::mouseOver(const Renderer& renderer,
	const Input& input,
	const Camera& camera) const
{
	int viewportXPos{
		(position().x() - width() / 2)
		- (camera.position().x() - renderer.winWidth() / 2)
	};
	int viewportYPos{
		(position().y() - height() / 2)
		- (camera.position().y() - renderer.winHeight() / 2)
	};
	return input.mousePosition().x() >= viewportXPos
		&& input.mousePosition().x() <= viewportXPos + width()
		&& input.mousePosition().y() >= viewportYPos
		&& input.mousePosition().y() <= viewportYPos + height();

}

AnimatedSprite* Button::animatedSprite()
{
	return static_cast<AnimatedSprite*>(_sprite);
}