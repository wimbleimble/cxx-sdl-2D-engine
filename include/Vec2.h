#ifndef VEC_H
#define VEC_H

template<typename T = int>
class Vec2
{
	int _x;
	int _y;

public:
	Vec2();
	Vec2(T x, T y);

	~Vec2();

	int x() const;
	int y() const;
	void setX(T x);
	void setY(T y);
};

#endif