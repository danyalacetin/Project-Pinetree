#ifndef __GAMEUTILS_H__
#define __GAMEUTILS_H__

// Local Includes:

// Library Includes:
#include <Box2D.h>

// Forward Declarations:

struct Vector2i
{
	Vector2i();
	Vector2i(int iX, int iY);

	static Vector2i FromB2Vec2(b2Vec2 vec);

	int x;
	int y;
};

struct Vector2f
{
	Vector2f();
	Vector2f(float fX, float fY);
	Vector2f(int iX, int iY);

	static Vector2f FromB2Vec2(b2Vec2 vec);
	static Vector2f FromIntVector(Vector2i vec);
	Vector2i ToIntVector() const;
	
	static Vector2f Plus(Vector2f v2fVec1, Vector2f v2fVec2);
	static Vector2f Multiply(Vector2f v2fVec, float scalar);

	float x;
	float y;
};

enum TextAlignment
{
	ALIGN_BOT_LEFT,
	ALIGN_CENTRE,
};

#endif //!__GAMEUTILS_H__
