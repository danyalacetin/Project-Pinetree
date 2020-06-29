#ifndef __MANAGERINTERFACE_H__
#define __MANAGERINTERFACE_H__

// Local Includes:

// Library Includes:
#include <string>

// Forward Declarations:

class ManagerInterface
{
	//Member Methods:
public:
	ManagerInterface();
	~ManagerInterface();

	void SetFileLocation(std::string location);

protected:

private:
	ManagerInterface(const ManagerInterface& managerinterface);
	ManagerInterface& operator=(const ManagerInterface& managerinterface);


	//Member Data:
public:

protected:
	std::string m_folderLocation;

private:

};

#endif //!__MANAGERINTERFACE_H__
