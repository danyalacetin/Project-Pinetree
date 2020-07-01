// COMP710 GP 2D Framework 2019
#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

// Superclass Includes:
#include "state.h"

class BackBuffer;

class GameState : public State
{
public:
	//Member Methods:
	GameState();
	~GameState();

	bool Initialise();
	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);
	void InitialiseControls();

protected:

private:

	//Member Data:
public:

protected:

	// sprites:

private:

};

#endif // __MENUSTATE_H__


