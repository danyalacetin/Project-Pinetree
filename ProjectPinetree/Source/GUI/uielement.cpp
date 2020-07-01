// This include:
#include "uielement.h"

// Local includes:

// Library includes:

UIElement::UIElement()
{

}

UIElement::~UIElement()
{

}

void UIElement::SetPosition(Vector2f newPosition)
{
	m_position = newPosition;
	PositionChildren();
}

void UIElement::SetPosition(float fX, float fY)
{
	SetPosition(Vector2f(fX, fY));
}

void UIElement::SetPosition(int iX, int iY)
{
	float fX = static_cast<float>(iX);
	float fY = static_cast<float>(iY);

	SetPosition(fX, fY);
}

void UIElement::SetDimensions(Vector2f newDimensions)
{
	m_dimensions = newDimensions;
}

Vector2f UIElement::GetDimensions()
{
	return m_dimensions;
}

Vector2f UIElement::GetPosition()
{
	return m_position;
}

bool UIElement::ContainsPoint(Vector2f v2fPoint)
{
	Vector2f v2fEndPosition = Vector2f::Plus(m_position, m_dimensions);

	bool bInXRange = v2fPoint.x >= m_position.x && v2fPoint.x <= v2fEndPosition.x;
	bool bInYRange = v2fPoint.y >= m_position.y && v2fPoint.y <= v2fEndPosition.y;

	return bInXRange && bInYRange;
}