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
#include "Resource Management/inimanager.h"
#include "Resource Management/iniparser.h"
#include "Resource Management/resourcemanager.h"
#include "Resource Management/textures.h"
#include "Game States/menustate.h"
#include "Game States/gamestate.h"
#include "Game States/gamemenustate.h"
#include "Game States/state.h"
#include "mouse.h"
#include "Game States/splashstate.h"

// Library includes:
#include <cassert>
#include <SDL.h>
#include <cstdio>
#include <string>
#include <sstream>

// Static Members:
Game* Game::sm_pInstance = 0;
Vector2f Game::screenDimensions = Vector2f();
float Game::metreToPixelFraction = 77.0f;

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

Vector2i Game::WorldToScreenConversion(Vector2f worldCoords)
{
	Vector2f convertedCoords;

	convertedCoords.x = metreToPixelFraction * worldCoords.x;
	convertedCoords.y = screenDimensions.y - metreToPixelFraction * worldCoords.y;

	return convertedCoords.ToIntVector();
}

Vector2f Game::ScreenToWorldConversion(Vector2i screenCoords)
{
	Vector2f convertedCoords;
	Vector2f castedScreenCoords = Vector2f::FromIntVector(screenCoords);

	convertedCoords.x = castedScreenCoords.x / metreToPixelFraction;
	convertedCoords.y = (screenDimensions.y - castedScreenCoords.y) / metreToPixelFraction;

	return convertedCoords;
}

float Game::WorldToScreenConversionf(float worldValue)
{
	return metreToPixelFraction * worldValue;
}

float Game::ScreenToWorldConversionf(float screenCoords)
{
	return screenCoords / metreToPixelFraction;
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
, m_pPointerSprite(0)
, m_pMousePointer(0)
{
	
}

Game::~Game()
{
	delete m_pPlayerSprite;
	m_pPlayerSprite = 0;

	delete m_pPointerSprite;
	m_pPointerSprite = 0;

	delete m_pPlayer;
	m_pPlayer = 0;

	delete m_pMousePointer;
	m_pMousePointer = 0;

	ResourceManager::DestroyInstance();
	InputEventHandler::DestroyInstance();

	delete m_pBackBuffer;
	m_pBackBuffer = 0;

	delete m_pInputHandler;
	m_pInputHandler = 0;
}

bool 
Game::Initialise()
{
	const int width = 1920;
	const int height = 1080;

	m_pBackBuffer = new BackBuffer();
	if (!m_pBackBuffer->Initialise(width, height))
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
	SDL_ShowCursor(SDL_DISABLE);

	LoadSprites();

	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);

	screenDimensions.x = static_cast<float>(displayMode.w);
	screenDimensions.y = static_cast<float>(displayMode.h);

	State* pState = SplashState::GetInstance();
	ChangeState(pState);

	m_pPlayer = new Player();
	m_pPlayer->Initialise(m_pPlayerSprite);

	m_pMousePointer = new MousePointer();
	m_pMousePointer->Initialise(m_pPointerSprite);

	return (true);
}

bool 
Game::DoGameLoop()
{
	const float stepSize = 1.0f / 60.0f;

	assert(m_pInputHandler);
	m_pInputHandler->ProcessInput(*this);
	
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
	m_states.top()->Process(deltaTime);
}

void 
Game::Draw(BackBuffer& backBuffer)
{
	++m_frameCount;

	backBuffer.Clear();

	// Draw game world

	m_states.top()->Draw(backBuffer);

	backBuffer.Present();
}

void 
Game::Quit()
{
	m_looping = false;
}

bool Game::LoadSprites()
{
	m_pPlayerSprite = m_pBackBuffer->CreateSprite("playership.png");
	m_pPointerSprite = m_pBackBuffer->CreateSprite("mouse_pointer.png");

	return true;
}

void Game::HandleInput(UserInput input)
{
	m_states.top()->HandleEvents(*this, input);
}

void Game::ChangeState(State* state)
{
	if (!m_states.empty())
	{
		m_states.top()->Cleanup();
		m_states.pop();
	}

	m_states.push(state);
	m_states.top()->Initialise();
}

void Game::PushState(State* state)
{
	if (!m_states.empty())
	{
		m_states.top()->Pause();
	}

	m_states.push(state);
	m_states.top()->Initialise();
}

void Game::PopState()
{
	if (!m_states.empty())
	{
		m_states.top()->Cleanup();
		m_states.pop();

		m_states.top()->Resume();
	}
}

MousePointer& Game::GetMouse()
{
	return *m_pMousePointer;
}
