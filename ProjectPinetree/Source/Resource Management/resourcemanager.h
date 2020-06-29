#ifndef __RESOURCEMANAGER_H__
#define __RESOURCEMANAGER_H__

// Local Includes:

// Library Includes:
#include <string>

// Forward Declarations:
class TextureManager;
class IniManager;
struct SDL_Renderer;
class FontManager;

class ResourceManager
{
	//Member Methods:
public:
	~ResourceManager();


	static bool Setup(SDL_Renderer* pRenderer);
	static ResourceManager& GetInstance();
	static void DestroyInstance();

	FontManager& GetFontManager();
	TextureManager& GetTextureManager();
	IniManager& GetIniManager();

	void SetFileLocation(std::string location);

protected:
	bool Initialise(SDL_Renderer * pRenderer);

private:
	ResourceManager();
	ResourceManager(const ResourceManager& resourcemanager);
	ResourceManager& operator=(const ResourceManager& resourcemanager);


	//Member Data:
public:

protected:
	static ResourceManager* sm_pInstance;

	IniManager* m_pIniManager;
	TextureManager* m_pTextureManager;
	FontManager* m_pFontManager;

	bool m_bIsInitialised;
	std::string m_folderLocation;

private:

};

#endif //!__RESOURCEMANAGER_H__
