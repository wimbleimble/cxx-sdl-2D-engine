#include "Button.h"

#include <iostream>

#include "AnimatedSprite.h"
#include "Engine.h"
#include "State.h"
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

void Button::activate() const
{
	if (_callback)
		_callback();
}

State* Button::handleEvent(Engine* engine, SDL_Event event)
{
	switch (event.type)
	{
	case SDL_MOUSEBUTTONUP:
		if (animatedSprite()->currentAnimation() == "Clicked")
			activate();

	};
	return nullptr;
}

State* Button::update(Engine* engine)
{
	if (mouseOver(engine->renderer(),
		engine->input(),
		engine->state()->camera()))
		if (engine->input().mouseState(Input::MouseButton::Left))
			animatedSprite()->setAnimation("Clicked");
		else
			animatedSprite()->setAnimation("Hover");
	else
		animatedSprite()->setAnimation("Normal");
	return nullptr;
}

bool Button::visible() const
{
	return true;
}


AnimatedSprite* Button::animatedSprite()
{
	return static_cast<AnimatedSprite*>(_sprite);
}

void Button::onClick(std::function<void()> callback)
{
	_callback = callback;
}