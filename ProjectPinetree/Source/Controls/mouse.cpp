// This Includes
#include "mouse.h"

// Local Includes
#include "../SDL Render/sprite.h"

MousePointer MousePointer::mouseInstance;

MousePointer::MousePointer()
: m_pSprite(0)
, m_v2fPosition(0, 0)
{
}

MousePointer::~MousePointer()
{
}

MousePointer* MousePointer::GetInstance()
{
	return &mouseInstance;
}

bool MousePointer::Initialise(Sprite* pSprite)
{
	m_pSprite = pSprite;
	m_pSprite->SetHandle(SpritePositionHandle::TOP_LEFT);

	return true;
}

void MousePointer::Cleanup()
{
	m_pSprite = nullptr;
}

void MousePointer::Process(float fDeltaTime)
{
}

void MousePointer::Draw(BackBuffer& backBuffer)
{
	m_pSprite->SetPosition(m_v2fPosition);
	m_pSprite->Draw(backBuffer);
}

void MousePointer::SetPosition(Vector2f v2fNewPosition)
{
	m_v2fPosition.x = v2fNewPosition.x;
	m_v2fPosition.y = v2fNewPosition.y;
}

Vector2f MousePointer::GetPosition() const
{
	return m_v2fPosition;
}
