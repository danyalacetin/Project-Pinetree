#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

// Superclass Includes:
#include "state.h"

// Local includes
#include "../Utilities/gameutils.h"

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

class MenuState : public State
{
public:
	//Member Methods:
	static MenuState* GetInstance();

	bool Initialise();
	void Cleanup();

	void HandleEvents(Game& game, UserInput input);
	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

	void ChangeState(Game& game, State* newState);
	void Pause();
	void Resume();

	void CreateMainMenu();
	void CreateOptionsMenu();
	void CreateCreditsMenu();

	void PushMenu(Menu* menu);
	void PopMenu();

	void Quit(Game& game);


protected:
	MenuState();

	void MouseClicked(Vector2f position, Game& game);

private:

	//Member Data:
public:

protected:

private:
	static MenuState menuState;

	Sprite* m_pTitleScreen;
	Sprite* m_pButtonSprite;

	std::stack<Menu*> m_menuStack;
};

#endif // __MENUSTATE_H__


