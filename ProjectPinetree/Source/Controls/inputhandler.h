#ifndef __INPUTHANDER_H__
#define __INPUTHANDER_H__

// Local includes
#include "controlconstants.h"

// Library includes:
#include <SDL.h>

// Forward Declarations:
class Game;
class KeyboardBindings;

class InputHandler
{
	//Member Methods:
public:
	InputHandler();
	~InputHandler();

	bool Initialise();
	void ProcessInput(Game& game, InputStateType state);

	void RunCommand(InputStateType state, InputCommand command);
	void RunCommand(InputStateType state, InputCommand command, float fAmmount);

	void KeyDown(SDL_Keycode keycode, InputStateType state);
	void KeyUp(SDL_Keycode keycode, InputStateType state);

	void MouseClick(SDL_Event& event, InputStateType state);
	void Quit(InputStateType state);

protected:

private:
	InputHandler(const InputHandler& inputHandler);
	InputHandler& operator=(const InputHandler& inputHandler);

	//Member Data:
public:

protected:
	KeyboardBindings* m_pKeyboardBindings;

private:

};

#endif // __INPUTHANDER_H__
