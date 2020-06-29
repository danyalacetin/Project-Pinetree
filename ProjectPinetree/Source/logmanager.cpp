// COMP710 GP 2D Framework 2019

// This include:
#include "logmanager.h"

// Library includes:
#include <Windows.h>

// Static Members:
LogManager* LogManager::sm_pInstance = 0;

void LogManager::DestroyInstance()
{
	if (sm_pInstance)
	{
		delete sm_pInstance;
		sm_pInstance = nullptr;
	}
}

LogManager::LogManager()
{

}

LogManager::~LogManager()
{

}

void 
LogManager::Log(const char* pcMessage)
{
	if (sm_pInstance == 0)
	{
		sm_pInstance = new LogManager();
	}

	OutputDebugStringA(pcMessage);
	OutputDebugStringA("\n"); 
}

void LogManager::Log(std::string pcMessage)
{
	Log(pcMessage.c_str());
}
