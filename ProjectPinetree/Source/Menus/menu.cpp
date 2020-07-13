// COMP710 GP 2D Framework 2019

// This include:
#include "menu.h"

// Local includes:
#include "../SDL Render/sprite.h"
#include "../game.h"
#include "../GUI/button.h"
#include "../GUI/uielement.h"
//#include "../soundmanager.h"

// Library includes:
#include <cassert>

Menu::Menu()
{

}


Menu::~Menu()
{
	for (UIElement* m_uiElement : m_uiElementContainor)
	{
		delete m_uiElement;
	}

	m_uiElementContainor.clear();
}

bool
Menu::Initialise()
{

	return (true);
}

void Menu::Process(float deltaTime)
{
	for each (Button* pButton in m_buttonContainer)
	{
		pButton->Process(deltaTime);
	}
}

void Menu::Draw(BackBuffer& backBuffer)
{
	for (UIElement* m_uiElement : m_uiElementContainor)
	{
		m_uiElement->Draw(backBuffer);
	}
}

// Adds a UIElement to the menu
void Menu::AddChild(UIElement* uiElement)
{
	m_uiElementContainor.push_back(uiElement);
}

// Adds a Button to the menu.
void Menu::AddChild(Button* button)
{
	m_uiElementContainor.push_back(button);
	m_buttonContainer.push_back(button);
}

// Passes mouse click coordinates to all buttons in the menu.
void Menu::MouseClicked(Vector2f v2fMousePosition)
{
	Button* pSelectedButton = 0;

	for each (Button * pButton in m_buttonContainer)
	{
		if (pButton->ContainsPoint(v2fMousePosition))
		{
			pSelectedButton = pButton;
		}
	}

	pSelectedButton->OnPress();
}

/*
Positions elements vertically in the centre of the container.
*/
void Menu::PositionElements(Vector2f containerDimensions)
{
	// calcluate / set spacing
	float fHSpacing = 50.0f;

	// calculate max height and width
	float fCurrentHeight = -fHSpacing;
	float fCurrentWidth = 0.0f;

	for each (UIElement * element in m_uiElementContainor)
	{
		Vector2f dimensions = element->GetDimensions();
		fCurrentHeight += fHSpacing + dimensions.y;

		if (fCurrentWidth < dimensions.x)
		{
			fCurrentWidth = dimensions.x;
		}
	}

	UIElement* pPrevElement = m_uiElementContainor[0];
	float fFirstElementHeight = pPrevElement->GetDimensions().y;

	float fStartX = containerDimensions.x / 2.0f;
	float fCurrY = (containerDimensions.y - fCurrentHeight + fFirstElementHeight) / 2.0f;

	pPrevElement->SetPosition(fStartX, fCurrY);

	for (size_t i = 1; i < m_uiElementContainor.size(); ++i)
	{
		UIElement* pCurrElement = m_uiElementContainor[i];

		float fPrevHeight = pPrevElement->GetDimensions().y;
		float fCurrHeight = pCurrElement->GetDimensions().y;

		float fChangeX = (fPrevHeight + fCurrHeight) / 2.0f + fHSpacing;

		fCurrY += fChangeX;

		pCurrElement->SetPosition(fStartX, fCurrY);
		pPrevElement = pCurrElement;
	}
}