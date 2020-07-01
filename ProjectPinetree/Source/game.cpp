// COMP710 GP 2D Framework 2019

// This includes:
#include "game.h"

// Local includes:
#include "SDL Render/backbuffer.h"
#include "Controls/inputhandler.h"
#include "Controls/inputeventhandler.h"
#include "logmanager.h"
#include "SDL Render/sprite.h"
#include "player.h"
#include "Resource Management/resourcemanager.h"
#include "Resource Management/textures.h"

// Library includes:
#include <cassert>
#include <SDL.h>
#include <cstdio>
#include <string>

// Static Members:
Game* Game::sm_pInstance = 0;
const int Game::sm_iWidth = 1920;
const int Game::sm_iHeight = 1080;

Game&
Game::GetInstance()
{
	if (sm_pInstance == 0)
	{ 
		sm_pInstance = new Game();
	}

	assert(sm_pInstance);

	return (*sm_pInstance);
}

void 
Game::DestroyInstance()
{
	delete sm_pInstance; 
	sm_pInstance = 0;
}

Game::Game()
: m_pBackBuffer(0)
, m_pInputHandler(0)
, m_looping(true)
, m_executionTime(0)
, m_elapsedSeconds(0)
, m_frameCount(0)
, m_FPS(0)
, m_numUpdates(0)
, m_lastTime(0)
, m_lag(0)
, m_drawDebugInfo(true)
, m_pPlayer(0)
, m_pPlayerSprite(0)
{
	
}

Game::~Game()
{
	delete m_pPlayer;
	m_pPlayer = 0;

	delete m_pPlayerSprite;
	m_pPlayerSprite = 0;

	ResourceManager::DestroyInstance();

	delete m_pBackBuffer;
	m_pBackBuffer = 0;

	delete m_pInputHandler;
	m_pInputHandler = 0;
}

bool 
Game::Initialise()
{
	m_pBackBuffer = new BackBuffer();
	if (!m_pBackBuffer->Initialise(sm_iWidth, sm_iHeight))
	{
		LogManager::Log("BackBuffer Init Fail!");
		return (false);
	}

	m_pInputHandler = new InputHandler();
	if (!m_pInputHandler->Initialise())
	{
		LogManager::Log("InputHandler Init Fail!");
		return (false);
	}

	if (!ResourceManager::Setup(m_pBackBuffer->GetRenderer()))
	{
		LogManager::Log("ResourceManager Setup Failed");
		return (false);
	}

	m_lastTime = SDL_GetPerformanceCounter();
	m_lag = 0.0f;

	m_pBackBuffer->SetClearColour(0xCC, 0xCC, 0xCC);

	InputEventHandler::GetInstance().Register(InputStateType::GAME, InputCommand::QUIT, [this] { Quit(); });
	InputEventHandler::GetInstance().Register(InputStateType::MENU, InputCommand::QUIT, [this] { Quit(); });

	m_pPlayerSprite = m_pBackBuffer->CreateSprite("playership.png");
	m_pPlayer = new Player();
	m_pPlayer->Initialise(m_pPlayerSprite);

	return (true);
}

bool 
Game::DoGameLoop()
{
	const float stepSize = 1.0f / 60.0f;

	assert(m_pInputHandler);
	m_pInputHandler->ProcessInput(*this, InputStateType::GAME);
	
	if (m_looping)
	{
		Uint64 current = SDL_GetPerformanceCounter();

		float deltaTime = (current - m_lastTime) / static_cast<float>(SDL_GetPerformanceFrequency());
		
		m_lastTime = current;

		m_executionTime += deltaTime;
	
		m_lag += deltaTime;

		int innerLag = 0;

		while (m_lag >= stepSize)
		{
			Process(stepSize);

			m_lag -= stepSize;

			++m_numUpdates;
			++innerLag;
		}

		// DEBUG STUB:
//		char buffer[64];
//		sprintf(buffer, "%f", deltaTime);
//		LogManager::GetInstance().Log(buffer);

		Draw(*m_pBackBuffer);
	}

	return (m_looping);
}

void 
Game::Process(float deltaTime)
{
	// Count total simulation time elapsed:
	m_elapsedSeconds += deltaTime;

	// Frame Counter:
	if (m_elapsedSeconds > 1)
	{
		m_elapsedSeconds -= 1;
		m_FPS = m_frameCount;
		m_frameCount = 0;
	}

	// Update the game world simulation:
	m_pPlayer->Process(deltaTime);
}

void 
Game::Draw(BackBuffer& backBuffer)
{
	++m_frameCount;

	backBuffer.Clear();

	// Draw game world
	m_pPlayer->Draw(backBuffer);

	backBuffer.Present();
}

void 
Game::Quit()
{
	m_looping = false;
}
