#ifndef INPUT_H
#define INPUT_H
#include "Vec2.h"
#include "SDL.h"

class Input
{

	Vec2 _mousePosition;

public:
	Input();
	~Input();
	void updateMousePosition();

	const Uint8* keyStates() const;
	const Vec2& mousePosition() const;

};

#endif