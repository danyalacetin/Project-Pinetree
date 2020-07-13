#ifndef __CONTROLCONSTANTS_H__

#define __CONTROLCONSTANTS_H__

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

struct UserInput
{
	InputCommand command;
	InputType type;
	Vector2f mousePosition;
};

enum class InputType
{
	BUTTON_DOWN,
	BUTTON_UP,
	MOUSE_MOTION,
	NONE,
};

#endif // !__CONTROLCONSTANTS_H__
