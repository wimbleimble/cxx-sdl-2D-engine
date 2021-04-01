#ifndef VEC_H
#define VEC_H

class Vec2
{
	int _x;
	int _y;

public:
	Vec2();
	Vec2(int x, int y);

	~Vec2();

	int x() const;
	int y() const;
	void setX(int x);
	void setY(int y);
	void add(const Vec2& vec);

	Vec2& operator+=(const Vec2& vec);
};

Vec2 operator+(const Vec2& vec1, const Vec2& vec2);
Vec2 operator-(const Vec2& vec1, const Vec2& vec2);
Vec2 operator*(int scalar, const Vec2& vec);
Vec2 operator*(const Vec2& vec, int scalar);
#endif