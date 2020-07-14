// COMP710 GP 2D Framework 2019

// This include:
#include "gamestate.h"

// Local includes:
#include "../game.h"
#include "../SDL Render/sprite.h"
#include "../player.h"

// Library includes:
#include <cassert>
#include <vector>

GameState GameState::gameStateInstance;

GameState::GameState()
	: State()
{

}

GameState* GameState::GetInstance()
{
	return &gameStateInstance;
}

bool
GameState::Initialise()
{

	return (true);
}

void GameState::Cleanup()
{
}

void GameState::HandleEvents(Game& game, UserInput input)
{
}

void
GameState::Process(float deltaTime)
{

}

void
GameState::Draw(BackBuffer& backBuffer)
{

}

void GameState::ChangeState(Game& game, State* newState)
{
}

void GameState::Pause()
{
}

void GameState::Resume()
{
}

