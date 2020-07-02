// This include:
#include "sprite.h"

// Local includes:
#include "../Resource Management/texture.h"
#include "backbuffer.h"

Sprite::Sprite()
	: m_pTexture(0)
	, m_x(0)
	, m_y(0)
	, m_alpha(0)
	, m_width(0)
	, m_height(0)
	, m_angle(0.0f)
	, m_centerX(0)
	, m_centerY(0)
	, m_positionHandle(SpritePositionHandle::CENTRE)
{

}

Sprite::~Sprite()
{

}

bool
Sprite::Initialise(Texture& texture)
{
	m_pTexture = &texture;

	m_width = m_pTexture->GetWidth();
	m_height = m_pTexture->GetHeight();

	m_alpha = 255;

	return (true);
}

void
Sprite::Process(float deltaTime)
{

}

void
Sprite::Draw(BackBuffer& backbuffer)
{
	backbuffer.DrawSprite(*this, m_positionHandle);
}

void
Sprite::SetX(int x)
{
	m_x = x;
}

void
Sprite::SetY(int y)
{
	m_y = y;
}

void Sprite::SetPosition(Vector2f position)
{
	m_x = static_cast<int>(position.x);
	m_y = static_cast<int>(position.y);
}

int
Sprite::GetX() const
{
	return (m_x);
}

int
Sprite::GetY() const
{
	return (m_y);
}

Vector2i Sprite::GetDimensions()
{
	return Vector2i(m_width, m_height);
}

Vector2f Sprite::GetDimensionsf()
{
	return Vector2f::FromIntVector(GetDimensions());
}

int
Sprite::GetAlpha()
{
	return m_alpha;
}

void
Sprite::SetAlpha(int alpha)
{
	m_alpha = alpha;
}

void
Sprite::SetAngle(float angle)
{
	m_angle = angle;
}

float
Sprite::GetAngle() const
{
	return (m_angle);
}

void
Sprite::SetCenter(int x, int y)
{
	m_centerX = x;
	m_centerY = y;
}

void
Sprite::SetHandleCenter()
{
	m_centerX = m_width / 2;
	m_centerY = m_height / 2;
}

void Sprite::SetHandle(SpritePositionHandle handle)
{
	m_positionHandle = handle;
}

Texture*
Sprite::GetTexture()
{
	return (m_pTexture);
}

bool Sprite::InUse()
{
	return m_pTexture != nullptr;
}

void Sprite::Free()
{
	m_pTexture = nullptr;
}

int
Sprite::GetWidth() const
{
	return (m_width);

}

int
Sprite::GetHeight() const
{
	return (m_height);
}

void
Sprite::SetWidth(int iWidth)
{
	m_width = iWidth;
}

void
Sprite::SetHeight(int iHeight)
{
	m_height = iHeight;
}