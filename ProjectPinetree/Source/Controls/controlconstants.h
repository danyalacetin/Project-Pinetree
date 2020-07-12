#ifndef __CONTROLCONSTANTS_H__

#define __CONTROLCONSTANTS_H__

enum class InputCommand
{
	NONE,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	ACTIVATE,
	SHOW_MENU,
	QUIT,
};

enum class InputState
{
	MENU,
	GAME
};

struct CommandStateInstance
{
	InputCommand command;
	InputState state;

	bool operator==(const CommandStateInstance& o) const;
	bool operator<(const CommandStateInstance& o) const;
};

enum class ButtonEventType
{
	BUTTON_KEY_DOWN,
	BUTTON_KEY_UP,
};

#endif // !__CONTROLCONSTANTS_H__
