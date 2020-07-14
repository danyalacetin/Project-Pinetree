// COMP710 GP 2D Framework 2019

// This include:
#include "gamestate.h"

// Local includes:
#include "../game.h"
#include "../SDL Render/sprite.h"
#include "../player.h"
#include "gamemenustate.h"
#include "../SDL Render/backbuffer.h"
#include "../Controls/inputhandler.h"

// Library includes:
#include <cassert>
#include <vector>

GameState GameState::gameStateInstance;

GameState::GameState()
	: State()
	, m_pPlayer(0)
	, m_pPlayerSprite(0)
{

}

Vector2f GameState::CalculatePlayerMovement(const Uint8* movementMap)
{
	float speed = 200.0f;

	float horizontalVel = 0.0f;
	float verticalVel = 0.0f;

	if (movementMap[SDL_SCANCODE_A])
	{
		horizontalVel -= speed;
	}
	if (movementMap[SDL_SCANCODE_D])
	{
		horizontalVel += speed;
	}
	if (movementMap[SDL_SCANCODE_W])
	{
		verticalVel -= speed;
	}
	if (movementMap[SDL_SCANCODE_S])
	{
		verticalVel += speed;
	}

	return Vector2f(horizontalVel, verticalVel);
}

GameState* GameState::GetInstance()
{
	return &gameStateInstance;
}

bool
GameState::Initialise()
{
	m_pPlayerSprite = BackBuffer::CreateSprite("playership.png");
	m_pPlayer = new Entity();
	m_pPlayer->Initialise(m_pPlayerSprite);
	m_pPlayer->SetPosition(Vector2f(200, 200));

	return (true);
}

void GameState::Cleanup()
{
	delete m_pPlayerSprite;
	m_pPlayerSprite = nullptr;

	delete m_pPlayer;
	m_pPlayer = nullptr;
}

void GameState::HandleEvents(Game& game, UserInput input)
{
	if (input.type == InputType::BUTTON_DOWN)
	{
		if (input.key == InputKey::ESCAPE)
		{
			ChangeState(game, GameMenuState::GetInstance());
		}
	}

	Vector2f velocity = CalculatePlayerMovement(input.keyboardState);
	m_pPlayer->SetVelocity(velocity);
}

void
GameState::Process(float deltaTime)
{
	m_pPlayer->Process(deltaTime);
}

void
GameState::Draw(BackBuffer& backBuffer)
{
	m_pPlayer->Draw(backBuffer);
}

void GameState::ChangeState(Game& game, State* newState)
{
	game.PushState(newState);
}

void GameState::Pause()
{
}

void GameState::Resume()
{
}

