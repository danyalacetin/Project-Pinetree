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

GameState::GameState()
	: State()
{

}

GameState::~GameState()
{

}

bool
GameState::Initialise()
{
	InitialiseControls();

	return (true);
}

void
GameState::Process(float deltaTime)
{

}

void
GameState::Draw(BackBuffer& backBuffer)
{

}

void
GameState::InitialiseControls()
{
	//InputEventHandler::GetInstance().Register(COMMAND_NONE, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_MOVE_LEFT, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_MOVE_STOP, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_MOVE_RIGHT, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_JUMP, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_ACTIVATE_WEAPON, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_SHOW_MENU, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_QUIT, [this] {
	//InputEventHandler::GetInstance().Register(COMMAND_MENU_SELECT, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_MENU_SELECT_UP, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_MENU_SELECT_DOWN, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_TEST, [] {});
}

