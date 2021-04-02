#include "Vec2.h"

Vec2::Vec2()
	: _x{}, _y{}
{
}

Vec2::Vec2(int x, int y)
	: _x{ x }, _y{ y }
{
}

Vec2::~Vec2()
{
}

int Vec2::x() const
{
	return _x;
}

int Vec2::y() const
{
	return _y;
}

void Vec2::setX(int x)
{
	_x = x;
}

void Vec2::setY(int y)
{
	_y = y;
}

void Vec2::set(int x, int y)
{
	setX(x);
	setY(y);
}

Vec2& Vec2::operator+=(const Vec2& vec)
{
	_x += vec.x();
	_y += vec.y();
	return *this;
}

Vec2 operator+(const Vec2& vec1, const Vec2& vec2)
{
	return Vec2(vec1.x() + vec2.x(), vec1.y() + vec2.y());
}

Vec2 operator-(const Vec2& vec1, const Vec2& vec2)
{
	return Vec2(vec1.x() - vec2.x(), vec1.y() - vec2.y());
}

Vec2 operator*(int scalar, const Vec2& vec)
{
	return Vec2(scalar * vec.x(), scalar * vec.y());
}

Vec2 operator*(const Vec2& vec, int scalar)
{
	return scalar * vec;
}