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


	m_menuCommandBindings["enter"] = InputCommand::ACTIVATE;
	m_menuCommandBindings["leftclick"] = InputCommand::ACTIVATE;
}

InputCommand KeyboardBindings::GetCommand(InputState state, std::string request)
{
	InputCommand command = InputCommand::NONE;

	if (InputState::MENU == state)
	{
		command = m_menuCommandBindings[request];
	}
	else if (InputState::GAME == state)
	{
		command = m_gameCommandBindings[request];
	}

	return command;
}
