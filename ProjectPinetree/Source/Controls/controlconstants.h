#ifndef __CONTROLCONSTANTS_H__

#define __CONTROLCONSTANTS_H__

enum class InputCommand
{
	NONE,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_STOP,
	ACTIVATE,
	SHOW_MENU,
	QUIT,
	MENU_UP,
	MENU_DOWN,
	MENU_RIGHT,
	MENU_LEFT,
	MENU_SELECT,
	TEST,
};

enum class InputStateType
{
	MENU,
	GAME
};

struct CommandStateInstance
{
	InputCommand command;
	InputStateType state;

	bool operator==(const CommandStateInstance& o) const;
	bool operator<(const CommandStateInstance& o) const;
};

enum class ButtonEventType
{
	BUTTON_KEY_DOWN,
	BUTTON_KEY_UP,
};

#endif // !__CONTROLCONSTANTS_H__
