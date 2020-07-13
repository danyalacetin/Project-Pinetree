// COMP710 GP 2D Framework 2019

// This include:
#include "gamemenustate.h"

// Local includes:
#include "../SDL Render/sprite.h"
#include "../game.h"
#include "../Menus/splashscreen.h"
#include "../SDL Render/backbuffer.h"
#include "../GUI/label.h"
#include "../GUI/button.h"
#include "../GUI/image.h"
#include "../logmanager.h"
#include "../Utilities/gameutils.h"
#include "../Menus/menu.h"
#include "state.h"
#include "../mouse.h"
#include "menustate.h"

// Library includes:
#include <cassert>
#include <cstdio>

GameMenuState GameMenuState::gameMenuStateInstance;

GameMenuState::GameMenuState()
	: State()
	, m_pInGameMenu(0)
	, m_pButtonSprite(0)
{

}

void GameMenuState::ExitMenu(Game& game)
{
	game.PopState();
}

void GameMenuState::MainMenu(Game& game)
{
	game.PopState();
	game.ChangeState(MenuState::GetInstance());
}

void GameMenuState::ExitGame(Game& game)
{
	game.Quit();
}

GameMenuState* GameMenuState::GetInstance()
{
	return nullptr;
}

bool
GameMenuState::Initialise()
{
	Button* pButton;
	m_pButtonSprite = BackBuffer::CreateSprite("Button.png");

	m_pInGameMenu = new Menu();
	m_pInGameMenu->Initialise();

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Resume");
	pButton->SetSelected(true);
	pButton->SetOnPress([&] (Game& game){ ExitMenu(game); });
	m_pInGameMenu->AddChild(pButton);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Quit to Main Menu");
	pButton->SetOnPress([&](Game& game) { MainMenu(game); });
	m_pInGameMenu->AddChild(pButton);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Quit to Desktop");
	pButton->SetOnPress([&](Game& game) { ExitGame(game); });
	m_pInGameMenu->AddChild(pButton);

	m_pInGameMenu->PositionElements(Game::screenDimensions);

	return (true);
}

void GameMenuState::Cleanup()
{
	delete m_pInGameMenu;
}

void GameMenuState::HandleEvents(Game& game, UserInput input)
{
	switch (input.type)
	{
	case InputType::MOUSE_MOTION:
		Game::GetInstance().GetMouse().SetPosition(input.mousePosition);
		m_pInGameMenu->MouseMoved(input.mousePosition);
		break;
	case InputType::BUTTON_DOWN:
		switch (input.command)
		{
		case InputCommand::CLICK:
			m_pInGameMenu->MouseClicked(input.mousePosition, game);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void
GameMenuState::Process(float deltaTime)
{
}

void
GameMenuState::Draw(BackBuffer& backBuffer)
{
	m_pInGameMenu->Draw(backBuffer);
}

void GameMenuState::ChangeState(Game& game, State* newState)
{
}

void GameMenuState::Pause()
{
}

void GameMenuState::Resume()
{
}
