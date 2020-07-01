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
	m_events.clear();
	m_mouseListeners.clear();
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

void InputEventHandler::NotifyMouseMovement(InputStateType state, Vector2f v2fCoords)
{
	for each (MouseListener listener in m_mouseListeners)
	{
		if (listener.state == state)
		{
			listener.function(v2fCoords);
		}
	}
}

void InputEventHandler::RegisterMouseListener(InputStateType state, std::function<void(Vector2f)> action)
{
	MouseListener instance = { state, action };
	m_mouseListeners.push_back(instance);
}
