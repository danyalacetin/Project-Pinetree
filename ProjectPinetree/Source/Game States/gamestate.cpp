// COMP710 GP 2D Framework 2019

// This include:
#include "gamestate.h"

// Local includes:
#include "../game.h"
#include "../SDL Render/sprite.h"
#include "../player.h"
#include "gamemenustate.h"

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
	if (input.type == InputType::BUTTON_DOWN)
	{
		if (input.command == InputCommand::ESCAPE)
		{
			ChangeState(game, GameMenuState::GetInstance());
		}
	}
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
	game.PushState(newState);
}

void GameState::Pause()
{
}

void GameState::Resume()
{
}

