#ifndef __INPUTEVENTHANDLER_H__
#define __INPUTEVENTHANDLER_H__

// Local Includes:
#include "controlconstants.h"
#include "../Utilities/gameutils.h"

// Library Includes:
#include <map>
#include <functional>
#include <vector>

// Forward Declarations:

struct MouseListener
{
	InputStateType state;
	std::function<void(Vector2f)> function;
};

class InputEventHandler
{
	//Member Methods:
public:
	static InputEventHandler& GetInstance();
	static void DestroyInstance();

	bool Call(InputStateType state, InputCommand command, float fAmmount);
	void Register(InputStateType state, InputCommand command, std::function<void (float)> action);
	void Register(InputStateType state, InputCommand command, std::function<void ()> action);

	void NotifyMouseMovement(InputStateType state, Vector2f v2fCoords);
	void RegisterMouseListener(InputStateType state, std::function<void(Vector2f)> action);

protected:
	InputEventHandler();
	~InputEventHandler();

private:
	InputEventHandler(const InputEventHandler& inputeventhandler);
	InputEventHandler& operator=(const InputEventHandler& inputeventhandler);

	//Member Data:
public:

protected:
	static InputEventHandler* m_pInstance;
	std::map<CommandStateInstance, std::function<void (float)>> m_events;
	std::vector<MouseListener> m_mouseListeners;

private:

};

#endif //!__INPUTEVENTHANDLER_H__
