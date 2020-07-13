// COMP710 GP 2D Framework 2019
#ifndef __STATE_H__
#define __STATE_H__

// Local includes
#include "../Controls/controlconstants.h"

class Game;
class BackBuffer;

class State
{
public:
	//Member Methods:
	virtual bool Initialise() = 0;
	virtual void Cleanup() = 0;

	virtual void HandleEvents(Game& game, UserInput input) = 0;
	virtual void Process(float deltaTime) = 0;
	virtual void Draw(BackBuffer& backBuffer) = 0;

	virtual void ChangeState(Game& game, State* newState) = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

protected:
	State();

private:

	//Member Data:
public:

protected:

private:

};

#endif // __GAMESTATE_H__


