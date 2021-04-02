#ifndef CAMERA_H
#define CAMERA_H
#include "Vec2.h"

class Camera
{
	Vec2 _position;
public:
	Camera() = default;

	const Vec2& position() const;
	Vec2& position();
};

#endif