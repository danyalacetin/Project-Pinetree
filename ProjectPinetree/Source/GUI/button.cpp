// COMP710 GP 2D Framework 2019

// This include:
#include "button.h"

// Local includes:
#include "../SDL Render/sprite.h"
#include "../game.h"
#include "label.h"
//#include "../soundmanager.h"

// Library includes:
#include <cassert>

Button::Button()
	: m_selected(false)
	, m_fnOnPress([] (Game&){})
{
}


Button::~Button()
{
	delete m_pLabel;
}

bool
Button::Initialise(Sprite* sprite, std::string text)
{
	m_pSprite = sprite;
	m_text = text;

	SetDimensions(sprite->GetDimensionsf());

	m_pLabel = new Label();
	m_pLabel->Initialise(text);
	m_pLabel->SetAlignment(ALIGN_CENTRE);
	m_pLabel->SetColour(0x00, 0x00, 0x00);

	return (true);
}

void
Button::Process(float deltaTime)
{
	if (m_selected)
	{
		m_pLabel->SetColour(0xFF, 0x00, 0x00);
	}
	else
	{
		m_pLabel->SetColour(0x00, 0x00, 0x00);
	}
}

void
Button::Draw(BackBuffer& backBuffer)
{
	assert(m_pSprite);
	m_pSprite->SetPosition(m_position);
	m_pSprite->Draw(backBuffer);
	m_pLabel->Draw(backBuffer);
}

void
Button::OnPress(Game& game)
{
	//SoundManager::GetInstance().PlaySound(BUTTONPRESS);
	m_fnOnPress(game);
}

void
Button::SetOnPress(std::function<void(Game&)> fnOnPress)
{
	m_fnOnPress = fnOnPress;
}

void
Button::SetOnPress(std::function<void()> fnOnPress)
{
	m_fnOnPress = [fnOnPress](Game&) {fnOnPress(); };
}

bool
Button::IsSelected()
{
	return m_selected;
}

void
Button::SetSelected(bool selected)
{
	m_selected = selected;
	if (selected)
	{
		m_pLabel->SetColour(0xFF, 0x00, 0x00);
	}
	else
	{
		m_pLabel->SetColour(0x00, 0x00, 0x00);
	}

}

void
Button::SetPosition(Vector2f newPosition)
{
	UIElement::SetPosition(newPosition);
}

void
Button::SetPosition(float fX, float fY)
{
	SetPosition(Vector2f(fX, fY));
}

void
Button::SetPosition(int iX, int iY)
{
	float fX = static_cast<float>(iX);
	float fY = static_cast<float>(iY);

	SetPosition(fX, fY);
}

void Button::PositionChildren()
{
	m_pLabel->SetPosition(m_position.x, m_position.y + 3);
}
