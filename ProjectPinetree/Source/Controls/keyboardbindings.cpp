// This include:
#include "keyboardbindings.h"

// Local includes:

// Library includes:

KeyboardBindings::KeyboardBindings()
{

}

KeyboardBindings::~KeyboardBindings()
{
	m_gameCommandBindings.clear();
	m_menuCommandBindings.clear();
}

void KeyboardBindings::Initialise()
{
	m_gameCommandBindings["escape"] = InputCommand::QUIT;
	m_menuCommandBindings["escape"] = InputCommand::QUIT;
}

InputCommand KeyboardBindings::GetCommand(InputStateType state, std::string request)
{
	InputCommand command = InputCommand::NONE;

	if (InputStateType::MENU == state)
	{
		command = m_menuCommandBindings[request];
	}
	else if (InputStateType::GAME == state)
	{
		command = m_gameCommandBindings[request];
	}

	return command;
}
