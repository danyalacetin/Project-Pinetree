// This include:
#include "resourcemanager.h"

// Local includes:
#include "texturemanager.h"
#include "inimanager.h"
#include "fontmanager.h"
#include "../logmanager.cpp"

// Library includes:

ResourceManager* ResourceManager::sm_pInstance = 0;

ResourceManager::ResourceManager()
: m_pTextureManager(0)
, m_pFontManager(0)
, m_pIniManager(0)
, m_bIsInitialised(false)
{

}

ResourceManager::~ResourceManager()
{
	delete m_pFontManager;
	m_pFontManager = nullptr;

	delete m_pTextureManager;
	m_pTextureManager = nullptr;

	delete m_pIniManager;
	m_pIniManager = nullptr;
}

bool ResourceManager::Initialise(SDL_Renderer * pRenderer)
{
	bool bSuccess = true;

	m_pTextureManager = new TextureManager();
	m_pTextureManager->Initialise(pRenderer);

	m_pIniManager = new IniManager();

	m_pFontManager = new FontManager(pRenderer);

	SetFileLocation("assets");

	return (true);
}

bool ResourceManager::Setup(SDL_Renderer * pRenderer)
{
	bool bSuccess = false;

	if (sm_pInstance == 0)
	{
		sm_pInstance = new ResourceManager();
		bSuccess = sm_pInstance->Initialise(pRenderer);
	}
	else
	{
		bSuccess = true;
	}

	return (bSuccess);
}

ResourceManager& ResourceManager::GetInstance()
{
	if (sm_pInstance == 0)
	{
		
		LogManager::Log("GetInstance called on ResourceManager before Setup.");
	}

	return (*sm_pInstance);
}

void ResourceManager::DestroyInstance()
{
	if (sm_pInstance)
	{
		delete sm_pInstance;
		sm_pInstance = nullptr;
	}
}

FontManager& ResourceManager::GetFontManager()
{
	FontManager* pFontManager = 0;

	if (m_bIsInitialised)
	{
		if (m_pTextureManager)
		{
			pFontManager = m_pFontManager;
		}
		else
		{
			LogManager::Log("Font Manager is null");
		}
	}
	else
	{
		LogManager::Log("Attempting to get FontManager before ResourceManager is initialised");
	}

	return (*pFontManager);
}

TextureManager& ResourceManager::GetTextureManager()
{
	TextureManager* pTextureManager = 0;

	if (m_bIsInitialised)
	{
		if (m_pTextureManager)
		{
			pTextureManager = m_pTextureManager;
		}
		else
		{
			LogManager::Log("Texture Manager is null");
		}
	}
	else
	{
		LogManager::Log("Attempting to get TextureManager before ResourceManager is initialised");
	}

	return (*pTextureManager);
}

IniManager& ResourceManager::GetIniManager()
{
	IniManager* pIniManager = 0;

	if (m_bIsInitialised)
	{
		if (m_pIniManager)
		{
			pIniManager = m_pIniManager;
		}
		else
		{
			LogManager::Log("Ini Manager is null.");
		}
	}
	else
	{
		LogManager::Log("Attempting to get IniManager before ResourceManager is initialised");
	}

	return (*pIniManager);
}

void ResourceManager::SetFileLocation(std::string location)
{
	m_folderLocation = location;

	m_pTextureManager->SetFileLocation(location + "\\" + "textures\\");
	m_pIniManager->SetFileLocation(location + "\\" + "ini\\");
	m_pFontManager->SetFileLocation(location + "\\" + "fonts\\");
}
