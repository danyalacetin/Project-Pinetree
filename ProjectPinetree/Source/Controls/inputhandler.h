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
struct Vector2f;
class MousePointer;
class Sprite;

class InputHandler
{
	//Member Methods:
public:
	InputHandler();
	~InputHandler();

	bool Initialise();
	void ProcessInput(Game& game);

protected:
	InputKey GetKeyCommand(SDL_Event event);

private:
	InputHandler(const InputHandler& inputHandler);
	InputHandler& operator=(const InputHandler& inputHandler);

	//Member Data:
public:

protected:
	UserInput input;
	MousePointer* m_pMouseInstance;
	Sprite* m_pMouseSprite;

private:

};

#endif // __INPUTHANDER_H__
