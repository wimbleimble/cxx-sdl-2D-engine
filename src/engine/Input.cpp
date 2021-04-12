#include "Input.h"

Input::Input(int widthScale, int heightScale)
	: _mousePosition{}
{
	updateMousePosition(widthScale, heightScale);
}

Input::~Input() {}

void Input::updateMousePosition(int widthScale, int heightScale)
{
	int x{};
	int y{};
	SDL_GetMouseState(&x, &y);
	_mousePosition.set(x / widthScale, y / heightScale);
}

const Vec2& Input::mousePosition() const
{
	return _mousePosition;
}

const Uint8* Input::keyStates() const
{
	return SDL_GetKeyboardState(nullptr);
}

bool Input::mouseState(MouseButton button) const
{
	return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON((int)button);
}