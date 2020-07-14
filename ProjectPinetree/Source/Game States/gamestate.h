#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

// Superclass Includes:
#include "state.h"

class BackBuffer;

class GameState : public State
{
public:
	static GameState* GetInstance();

	bool Initialise();
	void Cleanup();

	void HandleEvents(Game& game, UserInput input);
	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

	void ChangeState(Game& game, State* newState);
	void Pause();
	void Resume();

protected:
	GameState();

private:

	//Member Data:
public:

protected:


private:
	static GameState gameStateInstance;

};

#endif // __MENUSTATE_H__


