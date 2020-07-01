#ifndef __INPUTEVENTHANDLER_H__
#define __INPUTEVENTHANDLER_H__

// Local Includes:
#include "controlconstants.h"

// Library Includes:
#include <map>
#include <functional>

// Forward Declarations:

class InputEventHandler
{
	//Member Methods:
public:
	static InputEventHandler& GetInstance();
	static void DestroyInstance();

	bool Call(InputStateType state, InputCommand command, float fAmmount);
	void Register(InputStateType state, InputCommand command, std::function<void (float)> action);
	void Register(InputStateType state, InputCommand command, std::function<void ()> action);

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

private:

};

#endif //!__INPUTEVENTHANDLER_H__
