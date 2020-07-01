// This include:
#include "inputeventhandler.h"

// Local includes:
#include "../logmanager.h"

// Library includes:

// Static
InputEventHandler* InputEventHandler::m_pInstance = nullptr;

InputEventHandler::InputEventHandler()
{
}

InputEventHandler::~InputEventHandler()
{

}

InputEventHandler & InputEventHandler::GetInstance()
{
	if (m_pInstance == 0)
	{
		m_pInstance = new InputEventHandler();
	}

	return *m_pInstance;
}

void InputEventHandler::DestroyInstance()
{
	if (m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

bool InputEventHandler::Call(InputStateType state, InputCommand command, float fAmmount)
{
	CommandStateInstance instance = { command, state };
	bool bFound = !(m_events.find(instance) == m_events.end());

	if (bFound)
	{
		m_events[instance](fAmmount);
	}

	return bFound;
}

void InputEventHandler::Register(InputStateType state, InputCommand command, std::function<void(float)> action)
{
	CommandStateInstance instance = { command, state };
	m_events[instance] = action;
}

void InputEventHandler::Register(InputStateType state, InputCommand command, std::function<void()> action)
{
	CommandStateInstance instance = { command, state };
	m_events[instance] = [action](float fIgnore) { action(); };
}