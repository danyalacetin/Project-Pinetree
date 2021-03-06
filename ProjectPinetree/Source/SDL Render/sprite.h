// COMP710 GP 2D Framework 2019
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "../Utilities/gameutils.h"

// Forward Declarations:
class BackBuffer;
class Texture;

enum class SpritePositionHandle
{
	CENTRE,
	TOP_LEFT
};

class Sprite
{
	//Member Methods:
public:
	Sprite();
	~Sprite();

	bool Initialise(Texture& texture);

	void Process(float deltaTime);
	void Draw(BackBuffer& backbuffer);

	void SetX(int x);
	void SetY(int y);
	void SetPosition(Vector2f position);

	int GetX() const;
	int GetY() const;

	Vector2i GetDimensions();
	Vector2f GetDimensionsf();

	int GetAlpha();
	void SetAlpha(int alpha);

	void SetAngle(float angle);
	float GetAngle() const;

	void SetCenter(int x, int y);
	void SetHandleCenter();

	void SetHandle(SpritePositionHandle handle);

	int GetWidth() const;
	int GetHeight() const;

	void SetWidth(int iwidth);
	void SetHeight(int iheight);

	Texture* GetTexture();

	bool InUse();
	void Free();

protected:

private:
	Sprite(const Sprite& sprite);
	Sprite& operator=(const Sprite& sprite);

	//Member Data:
public:

protected:
	Texture* m_pTexture;
	int m_x;
	int m_y;

	int m_alpha;

	float m_angle;
	int m_centerX;
	int m_centerY;

	int m_width;
	int m_height;

	SpritePositionHandle m_positionHandle;

private:

};

#endif // __SPRITE_H__
