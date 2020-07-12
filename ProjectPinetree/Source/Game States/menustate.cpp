// COMP710 GP 2D Framework 2019

// This include:
#include "menustate.h"

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
#include "../Controls/inputeventhandler.h"
#include "gamestate.h"
#include "../mouse.h"

// Library includes:
#include <cassert>
#include <cstdio>

MenuState::MenuState()
	: State()
	, m_pMainMenu(0)
	, m_pSplash(0)
	, m_playerCount(0)
{
}


MenuState::~MenuState()
{
	while (!m_splashStack.empty())
	{
		delete m_splashStack.top();
		m_splashStack.pop();
	}

	while (!m_menuStack.empty())
	{
		delete m_menuStack.top();
		m_menuStack.pop();
	}
}

bool
MenuState::Initialise(Sprite* pFMOD, Sprite* pBox2D, Sprite* pRakNet, Sprite* pAUT, Sprite* pTitleScreen, Sprite* pButton)
{
	m_pRakNet = pRakNet;
	m_pBox2D = pBox2D;
	m_pFMOD = pFMOD;
	m_pTitleScreen = pTitleScreen;
	m_pAUT = pAUT;
	m_pButtonSprite = pButton;

	CreateSplash();

	InitialiseControls();

	return (true);
}

void
MenuState::Process(float deltaTime)
{
	if (!m_splashStack.empty())
	{
		ProcessSplash(deltaTime);
	}
	else
	{
		m_menuStack.top()->Process(deltaTime);
		Game::GetInstance().GetMouse().Process(deltaTime);
	}
}

void
MenuState::Draw(BackBuffer& backBuffer)
{

	if (!m_splashStack.empty())
	{
		DrawSplash(backBuffer);
	}
	else
	{
		backBuffer.SetClearColour(0x77, 0x77, 0x77); //Should this go here? No it shouldn't.
		m_menuStack.top()->Draw(backBuffer);
		Game::GetInstance().GetMouse().Draw(backBuffer);
	}
}

void
MenuState::CreateMainMenu()
{
	m_pMainMenu = new Menu();
	m_pMainMenu->Initialise();

	m_pImage = new Image();
	m_pImage->Initialise(m_pTitleScreen);
	m_pMainMenu->AddChild(m_pImage);

	m_pButton = new Button();
	m_pButton->Initialise(m_pButtonSprite, "Join Game");
	m_pButton->SetOnPress([&] {CreateLobbyMenu(); });
	m_pMainMenu->AddChild(m_pButton);

	m_pButton = new Button();
	m_pButton->Initialise(m_pButtonSprite, "Credits");
	m_pButton->SetOnPress([&] {CreateCreditsMenu(); });
	m_pMainMenu->AddChild(m_pButton);

	m_pButton = new Button();
	m_pButton->Initialise(m_pButtonSprite, "Quit");
	m_pButton->SetOnPress([] { Game::GetInstance().Quit(); });
	m_pMainMenu->AddChild(m_pButton);

	m_pMainMenu->PositionElements(Game::screenDimensions);

	m_menuStack.push(m_pMainMenu);
}

void
MenuState::CreateSplash()
{
	m_pAUT->SetWidth(static_cast<int>(Game::screenDimensions.x / 8));
	m_pAUT->SetHeight(static_cast<int>(Game::screenDimensions.x / 8));

	m_pAUT->SetY(m_pAUT->GetHeight() / 2);
	m_pAUT->SetX(static_cast<int>((Game::screenDimensions.x - m_pAUT->GetWidth() / 2) - m_pAUT->GetWidth() / 4.615));

	m_pSplash = new SplashScreen();
	m_pSplash->Initialise(m_pFMOD);
	m_splashStack.push(m_pSplash);

	m_pSplash = new SplashScreen();
	m_pSplash->Initialise(m_pBox2D);
	m_splashStack.push(m_pSplash);

	m_pSplash = new SplashScreen();
	m_pSplash->Initialise(m_pRakNet);
	m_splashStack.push(m_pSplash);
}

void
MenuState::CreateOptionsMenu()
{
	m_pOptionsMenu = new Menu();
	m_pOptionsMenu->Initialise();

	m_pLabel = new Label();
	m_pLabel->Initialise("Options");
	m_pLabel->SetAlignment(ALIGN_CENTRE);
	m_pLabel->SetColour(0x00, 0x00, 0x00);
	m_pOptionsMenu->AddChild(m_pLabel);

	m_pButton = new Button();
	m_pButton->Initialise(m_pButtonSprite, "Back");
	m_pButton->SetSelected(true);
	m_pButton->SetOnPress([&] { MenuReturn(); });
	m_pOptionsMenu->AddChild(m_pButton);

	m_pOptionsMenu->PositionElements(Game::screenDimensions);

	m_menuStack.push(m_pOptionsMenu);
}

void
MenuState::CreateCreditsMenu()
{
	m_pCreditsMenu = new Menu();
	m_pCreditsMenu->Initialise();

	m_pLabel = new Label();
	m_pLabel->Initialise("Credits");
	m_pLabel->SetAlignment(ALIGN_CENTRE);
	m_pLabel->SetColour(0xFF, 0x00, 0x00);
	m_pCreditsMenu->AddChild(m_pLabel);

	m_pLabel = new Label();
	m_pLabel->Initialise("Aidan");
	m_pLabel->SetAlignment(ALIGN_CENTRE);
	m_pLabel->SetColour(0x00, 0x00, 0x00);
	m_pCreditsMenu->AddChild(m_pLabel);

	m_pLabel = new Label();
	m_pLabel->Initialise("Danyal");
	m_pLabel->SetAlignment(ALIGN_CENTRE);
	m_pLabel->SetColour(0x00, 0x00, 0x00);
	m_pCreditsMenu->AddChild(m_pLabel);

	m_pLabel = new Label();
	m_pLabel->Initialise("Josh");
	m_pLabel->SetAlignment(ALIGN_CENTRE);
	m_pLabel->SetColour(0x00, 0x00, 0x00);
	m_pCreditsMenu->AddChild(m_pLabel);

	m_pButton = new Button();
	m_pButton->Initialise(m_pButtonSprite, "Back");
	m_pButton->SetSelected(true);
	m_pButton->SetOnPress([&] { MenuReturn(); });
	m_pCreditsMenu->AddChild(m_pButton);

	m_pCreditsMenu->PositionElements(Game::screenDimensions);

	m_menuStack.push(m_pCreditsMenu);
}

void
MenuState::CreateLobbyMenu()
{
	m_pLobbyMenu = new Menu();
	m_pLobbyMenu->Initialise();

	m_pLabel = new Label();
	m_pLabel->Initialise("Lobby");
	m_pLabel->SetAlignment(ALIGN_CENTRE);
	m_pLabel->SetColour(0xFF, 0x00, 0x00);
	m_pLobbyMenu->AddChild(m_pLabel);

	m_pLabel = new Label();
	m_pLabel->Initialise("Waiting for more players . . .");
	m_pLabel->SetAlignment(ALIGN_CENTRE);
	m_pLabel->SetColour(0x00, 0x00, 0x00);
	m_pLobbyMenu->AddChild(m_pLabel);

	m_pButton = new Button();
	m_pButton->Initialise(m_pButtonSprite, "Back");
	m_pButton->SetOnPress([&] { MenuReturn(); });
	m_pButton->SetPosition(Game::screenDimensions.x - m_pButtonSprite->GetWidth(), Game::screenDimensions.y - m_pButtonSprite->GetHeight());
	m_pLobbyMenu->AddChild(m_pButton);

	m_pLobbyMenu->PositionElements(Game::screenDimensions);

	m_menuStack.push(m_pLobbyMenu);
}

void
MenuState::ProcessSplash(float deltaTime)
{
	if (!m_splashStack.empty())
	{
		if (m_splashStack.top()->Isfinished())
		{
			delete m_splashStack.top();
			m_splashStack.pop();

			if (m_splashStack.empty())
			{
				CreateMainMenu();
			}

		}
		else
		{
			m_splashStack.top()->Process(deltaTime);
		}
	}
}

void
MenuState::DrawSplash(BackBuffer& backBuffer)
{
	m_pAUT->Draw(backBuffer);
	m_splashStack.top()->Draw(backBuffer);
}

void
MenuState::MenuReturn()
{
	delete m_menuStack.top();
	m_menuStack.pop();
}

void
MenuState::InitialiseControls()
{
	InputEventHandler::GetInstance().Register(InputState::GAME, InputCommand::QUIT, [this] { EscapeButtonPressed(); });
	InputEventHandler::GetInstance().Register(InputState::MENU, InputCommand::ACTIVATE, [this] { ActivateAction(); });
}

void
MenuState::UpButtonPressed()
{
	//m_menuStack.top()->DecrementSelected();
}

void
MenuState::DownButtonPressed()
{
	//m_menuStack.top()->IncrementSelected();
}

void
MenuState::ActivateAction()
{
	if (!m_splashStack.empty())
	{
		m_splashStack.top()->Setfinished();
	}
	else
	{
		Vector2f v2fMousePosition = Game::GetInstance().GetMouse().GetPosition();
		m_menuStack.top()->MouseClicked(v2fMousePosition);
	}
}

void
MenuState::EscapeButtonPressed()
{
	if (m_menuStack.size() > 1)
	{
		MenuReturn();
	}
	else
	{
		Game::GetInstance().Quit();
	}
}

void MenuState::MouseMoved(Vector2f pos)
{
	if (!m_menuStack.empty())
	{
		//m_menuStack.top()->MouseMoved(pos);
	}
}

std::stack<Menu*>
MenuState::GetMenuStack()
{
	return m_menuStack;
}

