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
//#include "../Controls/inputeventhandler.h"
#include "state.h"

// Library includes:
#include <cassert>
#include <cstdio>

GameMenuState::GameMenuState()
	: State()
{
}


GameMenuState::~GameMenuState()
{
	delete m_pInGameMenu;
}

bool
GameMenuState::Initialise(Sprite* buttonSprite)
{
	m_pInGameMenu = new Menu();
	m_pInGameMenu->Initialise();

	m_pButton = new Button();
	m_pButton->Initialise(buttonSprite, "Resume");
	m_pButton->SetSelected(true);
	m_pButton->SetOnPress([&] { Game::GetInstance().DeleteState(); });
	m_pInGameMenu->AddChild(m_pButton);

	m_pButton = new Button();
	m_pButton->Initialise(buttonSprite, "Quit to Lobby");
	m_pButton->SetOnPress([&] { Game::GetInstance().DeleteState(); Game::GetInstance().DeleteState(); });
	m_pInGameMenu->AddChild(m_pButton);

	m_pButton = new Button();
	m_pButton->Initialise(buttonSprite, "Quit to Desktop");
	m_pButton->SetOnPress([&] { Game::GetInstance().Quit(); });
	m_pInGameMenu->AddChild(m_pButton);

	m_pInGameMenu->PositionElements(Game::screenDimensions);

	InitialiseControls();

	return (true);
}

void
GameMenuState::Process(float deltaTime)
{
	Game::GetInstance().GetPreviousState()->Process(deltaTime);
}

void
GameMenuState::Draw(BackBuffer& backBuffer)
{
	Game::GetInstance().GetPreviousState()->Draw(backBuffer);
	m_pInGameMenu->Draw(backBuffer);
}

void
GameMenuState::InitialiseControls()
{
	//InputEventHandler::GetInstance().Register(COMMAND_NONE, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_MOVE_LEFT, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_MOVE_STOP, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_MOVE_RIGHT, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_JUMP, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_ACTIVATE_WEAPON, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_SHOW_MENU, [] {});
	//InputEventHandler::GetInstance().Register(COMMAND_QUIT, [this] { Game::GetInstance().DeleteState(); });
	//InputEventHandler::GetInstance().Register(COMMAND_MENU_SELECT, [this] {EnterButtonPressed(); });
	//InputEventHandler::GetInstance().Register(COMMAND_MENU_SELECT_UP, [this] {UpButtonPressed(); });
	//InputEventHandler::GetInstance().Register(COMMAND_MENU_SELECT_DOWN, [this] {DownButtonPressed(); });
	//InputEventHandler::GetInstance().Register(COMMAND_TEST, [] {});
}

void
GameMenuState::UpButtonPressed()
{
	//int iselected;

	//iselected = m_pInGameMenu->DecrementSelected();

	//for (unsigned i = 0; i < m_pInGameMenu->GetButtonContainor().size(); i++)
	//{
	//	if (i == iselected)
	//	{
	//		m_pInGameMenu->GetButtonContainor()[i]->SetSelected(true);
	//	}
	//	else
	//	{
	//		m_pInGameMenu->GetButtonContainor()[i]->SetSelected(false);
	//	}
	//}
}

void
GameMenuState::DownButtonPressed()
{
	//int iselected;

	//iselected = m_pInGameMenu->IncrementSelected();

	//for (unsigned i = 0; i < m_pInGameMenu->GetButtonContainor().size(); i++)
	//{
	//	if (i == iselected)
	//	{
	//		m_pInGameMenu->GetButtonContainor()[i]->SetSelected(true);
	//	}
	//	else
	//	{
	//		m_pInGameMenu->GetButtonContainor()[i]->SetSelected(false);
	//	}
	//}
}

void
GameMenuState::EnterButtonPressed()
{
	//m_pInGameMenu->GetSelectedButton().OnPress();
}