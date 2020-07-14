// COMP710 GP 2D Framework 2019
#ifndef __TEXTUREMANAGER_H__
#define __TEXTUREMANAGER_H__

// Local Includes:
#include "managerinterface.h"

// Library Includes:
#include <string>
#include <map>

// Forward Declarations:
class Texture;
struct SDL_Renderer;
class Sprite;

class TextureManager : public ManagerInterface
{
	//Member Methods:
public:
	TextureManager();
	~TextureManager();

	bool Initialise(SDL_Renderer* pRenderer);

	Texture* GetTexture(const char* pcFilename);

protected:

private:
	TextureManager(const TextureManager& textureManager);
	TextureManager& operator=(const TextureManager& textureManager);

	//Member Data:
public:

protected:
	SDL_Renderer* m_pRenderer;

	std::map<std::string, Texture*> m_pLoadedTextures;

private:

};

#endif // __TEXTUREMANAGER_H__
