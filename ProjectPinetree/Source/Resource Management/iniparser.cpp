#include "iniparser.h"
#include "../logmanager.h"
#include <fstream>

// TODO: Make Stable
IniParser::IniParser()
{
}


IniParser::~IniParser()
{
}

bool
IniParser::LoadIniFile(const std::string& filename)
{
	std::ifstream is;
	is.open(filename.c_str());
	if (!is.is_open())
	{
		LogManager::Log("Unable to read .ini file");
	}

	std::string section = "";
	std::string line;

	while (getline(is, line))
	{
		if (line == "") {}
		else if (line.at(0) == '[')
		{
			section = line.substr(1, line.size() - 2);
			std::map<std::string, std::string> emptyMap;
			sections[section] = emptyMap;
		}
		else
		{
			std::string optionName = line.substr(0, line.find_first_of("=") - 1);
			std::string optionValue = line.substr(line.find_first_of("=") + 2);

			std::map<std::string, std::string>& options = sections[section];
			options[optionName] = optionValue;
		}
	}
	is.close();
	return (true);
}

std::string IniParser::GetValueAsString(const std::string & iniSection, const std::string & key)
{
	return sections[iniSection][key];
}

int IniParser::GetValueAsInt(const std::string & iniSection, const std::string & key)
{
	return std::stoi(sections[iniSection][key]);
}

float
IniParser::GetValueAsFloat(const std::string& iniSection, const std::string& key)
{
	return std::stof(sections[iniSection][key]);
}

bool
IniParser::GetValueAsBoolean(const std::string& iniSection, const std::string& key)
{
	return sections[iniSection][key] == "true"; // TODO: EWW
}