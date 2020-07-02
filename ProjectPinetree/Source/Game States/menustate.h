// COMP710 GP 2D Framework 2019
#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

// Superclass Includes:
#include "state.h"

// Library includes:
#include <stack> 

//forward Declerations

class BackBuffer;
class Sprite;
class SplashScreen;
class Menu;
class Image;
class Button;
class Label;
class MousePointer;

class MenuState : public State
{
public:
	//Member Methods:
	MenuState();
	~MenuState();
	bool Initialise(Sprite* FMOD, Sprite* Box2D, Sprite* RakNet, Sprite* AUT, Sprite* TileScreen, Sprite* Button, Sprite* pPointerSprite);
	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

	void ProcessSplash(float deltaTime);
	void DrawSplash(BackBuffer& backBuffer);

	void CreateSplash();
	void CreateMainMenu();
	void CreateOptionsMenu();
	void CreateCreditsMenu();
	void CreateLobbyMenu();

	void MenuReturn();

	void InitialiseControls();

	void UpButtonPressed();
	void DownButtonPressed();
	void EnterButtonPressed();
	void ExcapeButtonPressed();

	std::stack<Menu*> GetMenuStack();


protected:

private:

	//Member Data:
public:

protected:

private:
	Button* m_pButton;
	Image* m_pImage;
	Label* m_pLabel;

	Sprite* m_pRakNet;
	Sprite* m_pBox2D;
	Sprite* m_pFMOD;
	Sprite* m_pAUT;
	Sprite* m_pTitleScreen;
	Sprite* m_pButtonSprite;

	MousePointer* m_pMousePointer;


	//MenuState m_menuState;

	SplashScreen* m_pSplash;
	std::stack<SplashScreen*> m_splashStack;

	Menu* m_pMainMenu;
	Menu* m_pOptionsMenu;
	Menu* m_pCreditsMenu;
	Menu* m_pJoinMenu;
	Menu* m_pHostMenu;
	Menu* m_pLobbyMenu;
	Menu* m_pInGameMenu;
	std::stack<Menu*> m_menuStack;
	int m_playerCount;
};

#endif // __MENUSTATE_H__


