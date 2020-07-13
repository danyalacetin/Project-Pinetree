#ifndef __INPUTHANDER_H__
#define __INPUTHANDER_H__

// Local includes
#include "controlconstants.h"

// Library includes:
#include <SDL.h>

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
	void ProcessInput(Game& game, InputState state);

	void RunCommand(InputState state, InputCommand command);

	void KeyDown(SDL_Keycode keycode, InputState state);
	void KeyUp(SDL_Keycode keycode, InputState state);

	void MouseClick(SDL_Event& event, InputState state);
	void MouseMovement(SDL_Event& event, InputState state);
	void Quit(InputState state);

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
