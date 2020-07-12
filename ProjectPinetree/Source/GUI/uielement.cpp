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

bool UIElement::ContainsPoint(Vector2f v2fPoint) // TODO: maybe broken...
{
	Vector2f halfnegDimension = Vector2f::Multiply(m_dimensions, -0.5f);
	Vector2f halfDimension = Vector2f::Multiply(m_dimensions, 0.5f);

	Vector2f v2fStartPosition = Vector2f::Plus(m_position, halfnegDimension);
	Vector2f v2fEndPosition = Vector2f::Plus(m_position, halfDimension);

	bool bInXRange = v2fPoint.x >= v2fStartPosition.x && v2fPoint.x <= v2fEndPosition.x;
	bool bInYRange = v2fPoint.y >= v2fStartPosition.y && v2fPoint.y <= v2fEndPosition.y;

	return bInXRange && bInYRange;
}
