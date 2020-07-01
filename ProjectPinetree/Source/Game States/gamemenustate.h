// COMP710 GP 2D Framework 2019
#ifndef __GAMEMENUSTATE_H__
#define __GAMEMENUSTATE_H__

// Superclass Includes:
#include "state.h"

class BackBuffer;
class Sprite;
class Button;
class Menu;

class GameMenuState : public State
{
public:
	//Member Methods:
	GameMenuState();
	~GameMenuState();

	bool Initialise(Sprite* buttonSprite);
	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

	void InitialiseControls();

	void UpButtonPressed();

	void DownButtonPressed();

	void EnterButtonPressed();

protected:

private:

	//Member Data:
public:

protected:
	Menu* m_pInGameMenu;
	Button* m_pButton;

private:

};

#endif // __GAMEMENUSTATE_H__


