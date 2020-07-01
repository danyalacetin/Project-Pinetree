#ifndef __KEYBOARDBINDINGS_H__
#define __KEYBOARDBINDINGS_H__

// Local Includes:
#include "controlconstants.h"

// Library Includes:
#include <map>
#include <string>

// Forward Declarations:

class KeyboardBindings
{
	//Member Methods:
public:
	KeyboardBindings();
	~KeyboardBindings();

	void Initialise();

	InputCommand GetCommand(InputStateType state, std::string request);

protected:

private:
	KeyboardBindings(const KeyboardBindings& keyboardbindings);
	KeyboardBindings& operator=(const KeyboardBindings& keyboardbindings);


	//Member Data:
public:

protected:
	std::map<std::string, InputCommand> m_gameCommandBindings;
	std::map<std::string, InputCommand> m_menuCommandBindings;

private:

};

#endif //!__KEYBOARDBINDINGS_H__
