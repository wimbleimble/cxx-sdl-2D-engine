#ifndef INPUT_H
#define INPUT_H
#include "Vec2.h"
#include "SDL.h"

class Input
{

	Vec2 _mousePosition;

public:
	enum class MouseButton
	{
		Left = 1,
		Middle = 2,
		Right = 3,
		X1 = 4,
		X2 = 5,
		NUM_BUTTONS = 5
	};

	Input(int widthScale, int heightScale);
	~Input();
	void updateMousePosition(int widthScale, int heightScale);

	const Uint8* keyStates() const;
	const Vec2& mousePosition() const;
	bool mouseState(MouseButton button) const;

};

#endif