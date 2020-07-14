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
	static GameMenuState* GetInstance();

	bool Initialise();
	void Cleanup();

	void HandleEvents(Game& game, UserInput input);
	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

	void ChangeState(Game& game, State* newState);
	void Pause();
	void Resume();

protected:
	GameMenuState();

	void ExitMenu(Game& game);
	void MainMenu(Game& game);
	void ExitGame(Game& game);

private:

	//Member Data:
public:

protected:
	Menu* m_pInGameMenu;
	Sprite* m_pButtonSprite;

private:
	static GameMenuState gameMenuStateInstance;

};

#endif // __GAMEMENUSTATE_H__


