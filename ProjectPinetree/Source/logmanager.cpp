// This include:
#include "logmanager.h"

// Library includes:
#include <Windows.h>

// Static Members:
LogManager LogManager::sm_pInstance;

LogManager::LogManager()
{

}

LogManager::~LogManager()
{

}

void 
LogManager::Log(const char* pcMessage)
{
	OutputDebugStringA(pcMessage);
	OutputDebugStringA("\n"); 
}

void LogManager::Log(std::string pcMessage)
{
	Log(pcMessage.c_str());
}
