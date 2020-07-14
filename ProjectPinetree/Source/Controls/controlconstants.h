#ifndef __CONTROLCONSTANTS_H__

#define __CONTROLCONSTANTS_H__

// Local includes
#include "../Utilities/gameutils.h"

// Library includes
#include <map>

// Forward Declarations
typedef uint8_t Uint8;

enum class InputKey
{
	NONE,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	ENTER,
	CLICK,
	ESCAPE,
};

enum class InputType
{
	BUTTON_DOWN,
	BUTTON_UP,
	MOUSE_MOTION,
	NONE,
};

struct UserInput
{
	UserInput()
		: keyboardState(0)
	{
		Clean();
	}

	void Clean()
	{
		key = InputKey::NONE;
		type = InputType::NONE;
		mousePosition = Vector2f();
	}

	InputKey key;
	InputType type;
	Vector2f mousePosition;
	const Uint8* keyboardState;
};

#endif // !__CONTROLCONSTANTS_H__
