#include "Input.h"

Input::Input()
	: _mousePosition{}
{
	updateMousePosition();
}

Input::~Input() {}

void Input::updateMousePosition()
{
	int x{};
	int y{};
	SDL_GetMouseState(&x, &y);
	_mousePosition.set(x, y);
}

const Vec2& Input::mousePosition() const
{
	return _mousePosition;
}

const Uint8* Input::keyStates() const
{
	return SDL_GetKeyboardState(nullptr);
}