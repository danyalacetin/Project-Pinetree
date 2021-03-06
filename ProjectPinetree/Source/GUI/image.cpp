// COMP710 GP 2D Framework 2019

// This include:
#include "image.h"

// Local includes:
#include "../SDL Render/sprite.h"
#include "../game.h"

// Library includes:
#include <cassert>

Image::Image()
{
}


Image::~Image()
{
}

bool
Image::Initialise(Sprite* sprite)
{
	m_pSprite = sprite;

	m_dimensions.x = static_cast<float>(m_pSprite->GetWidth());
	m_dimensions.y = static_cast<float>(m_pSprite->GetHeight());

	return (true);
}

void
Image::Draw(BackBuffer& backBuffer)
{
	assert(m_pSprite);
	m_pSprite->SetX(static_cast<int>(m_position.x));
	m_pSprite->SetY(static_cast<int>(m_position.y));
	m_pSprite->Draw(backBuffer);
}

void Image::PositionChildren()
{
}
