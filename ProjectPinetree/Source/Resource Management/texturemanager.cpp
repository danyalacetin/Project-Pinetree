// COMP710 GP 2D Framework 2019

// This include:
#include "texturemanager.h"

// Local includes:
#include "texture.h"
#include "../logmanager.h"

// Library includes:
#include <SDL.h>

TextureManager::TextureManager()
: m_pRenderer(0)
{

}

TextureManager::~TextureManager()
{
	for each (std::pair<std::string, Texture*> entry in m_pLoadedTextures)
	{
		delete entry.second;
		entry.second = 0;
	}

	m_pLoadedTextures.clear();
}

bool 
TextureManager::Initialise(SDL_Renderer* pRenderer)
{
	m_pRenderer = pRenderer;

	return (true);
}

Texture*
TextureManager::GetTexture(const char* pcFilename)
{
	Texture* pTexture = 0;
	std::string filename = ManagerInterface::m_folderLocation + pcFilename;

	if (m_pLoadedTextures.find(filename) == m_pLoadedTextures.end())
	{
		// Not already loaded... so load...
		pTexture = new Texture();
		if (!pTexture->InitialiseImage(filename.c_str(), m_pRenderer))
		{
			LogManager::Log("Texture failed to initialise!");
		}
		
		m_pLoadedTextures[filename] = pTexture;
	}
	else
	{
		// Is already loaded...
		pTexture = m_pLoadedTextures[filename];
	}

	return (pTexture);
}
