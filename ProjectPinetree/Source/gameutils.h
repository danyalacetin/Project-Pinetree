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
	


	float x;
	float y;
};

enum class TextAlignment
{
	ALIGN_BOT_LEFT,
	ALIGN_CENTRE,
};

#endif //!__GAMEUTILS_H__
