#include "Vec2.h"

template<typename T>
Vec2<T>::Vec2()
	: _x{}, _y{}
{
}

template<typename T>
Vec2<T>::Vec2(T x, T y)
	: _x{x}, _y{y}
{
}

template<typename T>
Vec2<T>::~Vec2()
{
}

template<typename T>
int Vec2<T>::x() const
{
	return _x;
}

template<typename T>
int Vec2<T>::y() const
{
	return _y;
}

template<typename T>
void Vec2<T>::setX(T x)
{
	_x = x;
}

template<typename T>
void Vec2<T>::setY(T y)
{
	_y = y;
}