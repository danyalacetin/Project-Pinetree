// COMP710 GP 2D Framework 2019
#ifndef __MENU_H__
#define __MENU_H__

#include "../Utilities/gameutils.h"

#include <vector>

class BackBuffer;
class Sprite;
class UIElement;
class Button;

class Menu
{
public:
	//Member Methods:
	Menu();
	~Menu();

	bool Initialise();
	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

	void AddChild(UIElement* uiElement);
	void AddChild(Button* button);

	void MouseClicked(Vector2f v2fMousePosition);

	void PositionElements(Vector2f containerDimensions);

protected:

private:

	//Member Data:
public:

protected:

private:
	std::vector<UIElement*> m_uiElementContainor;
	std::vector<Button*> m_buttonContainer; // TODO: has to be a better way.
};

#endif // __MENU_H__


