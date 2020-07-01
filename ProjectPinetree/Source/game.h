// COMP710 GP 2D Framework 2019
#ifndef __GAME_H__
#define __GAME_H__

// Local Includes:
#include "Resource Management/objectpool.h"
#include "./Utilities/gameutils.h"

// Library Includes:
#include <string>
#include <vector>

// Forward Declarations
class BackBuffer;
class InputHandler;
class MenuHandler;
class Sprite;
class Player;
struct b2Vec2;
class GameObject;
class MenuHandler;
class GameState;
class MenuState;
class GameMenuState;
class State;

class Game
{
	//Member Methods:
public:
	static Game& GetInstance();
	static void DestroyInstance();

	static Vector2i WorldToScreenConversion(Vector2f worldCoords);
	static Vector2f ScreenToWorldConversion(Vector2i screenCoords);

	static float WorldToScreenConversionf(float worldValue);
	static float ScreenToWorldConversionf(float screenCoords);

	~Game();

	bool Initialise();
	bool DoGameLoop();
	void Quit();

	bool LoadSprites();

	State* GetPreviousState();
	void AddGameState();
	void AddGameMenuState();
	void DeleteState();

protected:
	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

private:
	Game(const Game& game);
	Game& operator=(const Game& game);
	
	Game();

	//Member Data:
public:
	static Vector2f screenDimensions;
	static float metreToPixelFraction;

protected:
	static Game* sm_pInstance;
	BackBuffer* m_pBackBuffer;
	InputHandler* m_pInputHandler;
	bool m_looping;

	// Simulation Counters:
	float m_elapsedSeconds;
	float m_lag;
	float m_executionTime;
	__int64 m_lastTime;
	int m_frameCount;
	int m_FPS;
	int m_numUpdates;
	bool m_drawDebugInfo;

	// Game States:
	MenuState* m_pMenuState;
	GameState* m_pGameState;
	GameMenuState* m_pGameMenuState;

	std::vector<State*> m_pGameStateStack;

	//-----Sprites-----

	//	Splash Screen
	Sprite* m_pAUT;
	Sprite* m_pBox2D;
	Sprite* m_pFMOD;
	Sprite* m_pRakNet;

	// Main Menu
	Sprite* m_pTitleScreen;

	// Buttons
	Sprite* m_pButton;

	// Weapons
	Sprite* m_pSmgSprite;
	Sprite* m_pBulletSprite;

	// Player
	Sprite* m_pPlayerSprite;

	//-----------------

	// Game Entities
	Player* m_pPlayer;
	
private:

};

#endif // __GAME_H__
