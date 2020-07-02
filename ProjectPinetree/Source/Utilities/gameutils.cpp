// This include:
#include "gameutils.h"

// Local includes:

// Library includes:

Vector2f::Vector2f()
: x(0.0f)
, y(0.0f)
{
}

Vector2f::Vector2f(float fX, float fY)
: x(fX)
, y(fY)
{
}

Vector2f::Vector2f(int iX, int iY)
: x(static_cast<float>(iX))
, y(static_cast<float>(iY))
{
}

Vector2f Vector2f::FromB2Vec2(b2Vec2 vec)
{
	Vector2f toVec;

	toVec.x = vec.x;
	toVec.y = vec.y;

	return toVec;
}

Vector2f Vector2f::FromIntVector(Vector2i vec)
{
	float fX = static_cast<float>(vec.x);
	float fY = static_cast<float>(vec.y);

	return Vector2f(fX, fY);
}

Vector2i Vector2f::ToIntVector() const
{
	int iX = static_cast<int>(x);
	int iY = static_cast<int>(y);

	return Vector2i(iX, iY);
}

Vector2f Vector2f::Plus(Vector2f v2fVec1, Vector2f v2fVec2)
{
	float fX = v2fVec1.x + v2fVec2.x;
	float fY = v2fVec1.y + v2fVec2.y;

	return Vector2f(fX, fY);
}

Vector2f Vector2f::Multiply(Vector2f v2fVec, float scalar)
{
	return Vector2f(v2fVec.x * scalar, v2fVec.y * scalar);
}

Vector2i::Vector2i()
: x(0)
, y(0)
{
}

Vector2i::Vector2i(int iX, int iY)
: x(iX)
, y(iY)
{
}

Vector2i Vector2i::FromB2Vec2(b2Vec2 vec)
{
	int x = static_cast<int>(vec.x);
	int y = static_cast<int>(vec.y);

	return Vector2i(x, y);
}
