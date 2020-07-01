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

bool InputEventHandler::Call(InputState state, InputCommand command)
{
	CommandStateInstance instance = { command, state };
	bool bFound = !(m_events.find(instance) == m_events.end());

	if (bFound)
	{
		m_events[instance]();
	}

	return bFound;
}

void InputEventHandler::Register(InputState state, InputCommand command, std::function<void()> action)
{
	CommandStateInstance instance = { command, state };
	m_events[instance] = action;
}

void InputEventHandler::NotifyMouseMovement(InputState state, Vector2f v2fCoords)
{
	for each (MouseListener listener in m_mouseListeners)
	{
		if (listener.state == state)
		{
			listener.function(v2fCoords);
		}
	}
}

void InputEventHandler::RegisterMouseListener(InputState state, std::function<void(Vector2f)> action)
{
	MouseListener instance = { state, action };
	m_mouseListeners.push_back(instance);
}
