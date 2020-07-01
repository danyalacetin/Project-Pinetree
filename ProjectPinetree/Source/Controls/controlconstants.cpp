// This includes
#include "controlconstants.h"

bool CommandStateInstance::operator==(const CommandStateInstance& o) const
{
	return command == o.command && state == o.state;
}

bool CommandStateInstance::operator<(const CommandStateInstance& o) const
{
	return command < o.command;
}
