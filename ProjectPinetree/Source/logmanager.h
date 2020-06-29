// COMP710 GP 2D Framework 2019
#ifndef __LOGMANAGER_H__
#define __LOGMANAGER_H__

#include <string>

class LogManager
{
	//Member Methods:
public:
	static void DestroyInstance();
	~LogManager();

	static void Log(const char* pcMessage);
	static void Log(std::string pcMessage);
protected:

private:
	LogManager();
	LogManager(const LogManager& logManager);
	LogManager& operator=(const LogManager& logManager);

	//Member Data:
public:

protected:
	static LogManager* sm_pInstance;

private:

};

#endif //__LOGMANAGER_H__
