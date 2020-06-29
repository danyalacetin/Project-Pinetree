#ifndef __INIMANAGER_H__

#define __INIMANAGER_H__

#include <map>
#include <string>

#include "managerinterface.h"

// Forward Declarations
class IniParser;

class IniManager : public ManagerInterface
{
public:
	IniManager();
	~IniManager();

	IniParser& GetIniParser(std::string filename);

protected:
	std::map<std::string, IniParser*> m_loadedIniFiles;
};

#endif // !__INIMANAGER_H__