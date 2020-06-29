#include "inimanager.h"

// Local includes
#include "iniparser.h"
#include "../logmanager.h"

IniManager::IniManager()
{
}


IniManager::~IniManager()
{
	for each (std::pair<std::string, IniParser*> entry in m_loadedIniFiles)
	{
		delete entry.second;
		entry.second = 0;
	}

	m_loadedIniFiles.clear();
}

IniParser& IniManager::GetIniParser(std::string filename)
{
	IniParser* pParser = 0;
	std::string filepath = ManagerInterface::m_folderLocation + filename;

	if (m_loadedIniFiles.find(filepath) == m_loadedIniFiles.end())
	{
		// Not already loaded... so load...
		pParser = new IniParser();
		if (!pParser->LoadIniFile(filepath))
		{
			char buffer[32];

			sprintf_s(buffer, "Ini file %s failed to load", filepath.c_str());

			LogManager::Log(buffer);
		}

		m_loadedIniFiles[filepath] = pParser;
	}
	else
	{
		// Is already loaded...
		pParser = m_loadedIniFiles[filepath];
	}

	return (*pParser);
}
