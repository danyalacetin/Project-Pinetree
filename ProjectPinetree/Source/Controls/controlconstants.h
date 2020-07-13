#ifndef __CONTROLCONSTANTS_H__

#define __CONTROLCONSTANTS_H__

// Local includes
#include "../Utilities/gameutils.h"

enum class InputCommand
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
	{
		command = InputCommand::NONE;
		type = InputType::NONE;
		mousePosition = Vector2f();
	}

	InputCommand command;
	InputType type;
	Vector2f mousePosition;
};

#endif // !__CONTROLCONSTANTS_H__
