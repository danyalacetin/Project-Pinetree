#ifndef __INPUTHANDER_H__
#define __INPUTHANDER_H__

// Local includes
#include "controlconstants.h"

// Library includes:
#include <SDL.h>
#include <map>

// Forward Declarations:
class Game;
class KeyboardBindings;
class Vector2f;

class InputHandler
{
	//Member Methods:
public:
	InputHandler();
	~InputHandler();

	bool Initialise();
	void ProcessInput(Game& game);

protected:
	InputCommand GetKeyCommand(SDL_Event event);

private:
	InputHandler(const InputHandler& inputHandler);
	InputHandler& operator=(const InputHandler& inputHandler);

	//Member Data:
public:

protected:

private:

};

#endif // __INPUTHANDER_H__
