#include "Button.h"

#include <iostream>

#include "Engine.h"
#include "State.h"
#include "Renderer.h"
#include "Input.h"
#include "Camera.h"
#include "Animation.h"

Button::Button(SDL_Renderer* context,
	const std::string& path,
	int width,
	int height,
	int frames)
	: Ui{ context, path, width, height, frames }
{
	animator().addAnimation("Normal", 0, 1, 15);
	animator().addAnimation("Hover", 1, 1, 15);
	animator().addAnimation("Clicked", 2, 1, 15);
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
		if (animator().currentAnimation() == "Clicked")
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
			animator().playAnimation("Clicked");
		else
			animator().playAnimation("Hover");
	else
		animator().playAnimation("Normal");
	return nullptr;
}

void Button::onClick(std::function<void()> callback)
{
	_callback = callback;
}