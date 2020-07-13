#ifndef __SPLASHSTATE_H__
#define __SPLASHSTATE_H__

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

class SplashState : public State
{
public:
	//Member Methods:
	bool Initialise();
	void Cleanup();

	void HandleEvents(Game& game, UserInput input);
	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

	void ChangeState(Game& game, State* newState);
	void Pause();
	void Resume();

	static SplashState* GetInstance();

protected:

private:

	//Member Data:
public:

protected:
	SplashState();

private:
	static SplashState m_splashState;

	Sprite* m_pFMODSprite;
	Sprite* m_pBox2DSprite;
	bool m_bIsFinished;

	std::stack<SplashScreen*> m_splashStack;
};

#endif // __SPLASHSTATE_H__


