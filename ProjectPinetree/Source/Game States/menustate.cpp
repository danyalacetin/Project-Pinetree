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

MenuState MenuState::menuState;

MenuState::MenuState()
	: State()
	, m_pMainMenu(0)
	, m_pOptionsMenu(0)
	, m_pCreditsMenu(0)
	, m_pTitleScreen(0)
	, m_pButtonSprite(0)
{

}

void MenuState::MouseClicked(Vector2f position)
{
	m_menuStack.top()->MouseClicked(position);
}

MenuState* MenuState::GetInstance()
{
	return &menuState;
}

bool
MenuState::Initialise()
{
	m_pTitleScreen = BackBuffer::CreateSprite("TitleScreen.png");
	m_pButtonSprite = BackBuffer::CreateSprite("Button.png");

	return (true);
}

void MenuState::Cleanup()
{
	while (!m_menuStack.empty())
	{
		delete m_menuStack.top();
		m_menuStack.pop();
	}

	delete m_pTitleScreen;
	m_pTitleScreen = 0;

	delete m_pButtonSprite;
	m_pButtonSprite = 0;
}

void MenuState::HandleEvents(Game& game, UserInput input)
{
	switch (input.type)
	{
	case InputType::MOUSE_MOTION:
		Game::GetInstance().GetMouse().SetPosition(input.mousePosition);
		m_menuStack.top()->MouseMoved(input.mousePosition);
		break;
	case InputType::BUTTON_DOWN:
		switch (input.command)
		{
		case InputCommand::CLICK:
			m_menuStack.top()->MouseClicked(input.mousePosition);
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
MenuState::Process(float deltaTime)
{
	if (!m_menuStack.empty())
	{
		m_menuStack.top()->Process(deltaTime);
		Game::GetInstance().GetMouse().Process(deltaTime);
	}
}

void
MenuState::Draw(BackBuffer& backBuffer)
{
	if (!m_menuStack.empty())
	{
		m_menuStack.top()->Draw(backBuffer);
		Game::GetInstance().GetMouse().Draw(backBuffer);
	}
}

void MenuState::ChangeState(Game& game, State* newState)
{
	game.PushState(newState);
}

void MenuState::Pause()
{
}

void MenuState::Resume()
{
}

void
MenuState::CreateMainMenu()
{
	Image* pImage;
	Button* pButton;

	m_pMainMenu = new Menu();
	m_pMainMenu->Initialise();

	pImage = new Image();
	pImage->Initialise(m_pTitleScreen);
	m_pMainMenu->AddChild(pImage);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "New Game");
	pButton->SetOnPress([&] {  });
	m_pMainMenu->AddChild(pButton);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Credits");
	pButton->SetOnPress([&] {CreateCreditsMenu(); });
	m_pMainMenu->AddChild(pButton);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Quit");
	pButton->SetOnPress([] { Game::GetInstance().Quit(); });
	m_pMainMenu->AddChild(pButton);

	m_pMainMenu->PositionElements(Game::screenDimensions);

	m_menuStack.push(m_pMainMenu);
}

void
MenuState::CreateOptionsMenu()
{
	Label* pLabel;
	Button* pButton;

	m_pOptionsMenu = new Menu();
	m_pOptionsMenu->Initialise();

	pLabel = new Label();
	pLabel->Initialise("Options");
	pLabel->SetAlignment(ALIGN_CENTRE);
	pLabel->SetColour(0x00, 0x00, 0x00);
	m_pOptionsMenu->AddChild(pLabel);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Back");
	pButton->SetSelected(true);
	pButton->SetOnPress([&] { PopMenu(); });
	m_pOptionsMenu->AddChild(pButton);

	m_pOptionsMenu->PositionElements(Game::screenDimensions);

	m_menuStack.push(m_pOptionsMenu);
}

void
MenuState::CreateCreditsMenu()
{
	Label* pLabel;
	Button* pButton;
	
	m_pCreditsMenu = new Menu();
	m_pCreditsMenu->Initialise();

	pLabel = new Label();
	pLabel->Initialise("Credits");
	pLabel->SetAlignment(ALIGN_CENTRE);
	pLabel->SetColour(0xFF, 0x00, 0x00);
	m_pCreditsMenu->AddChild(pLabel);

	pLabel = new Label();
	pLabel->Initialise("Aidan");
	pLabel->SetAlignment(ALIGN_CENTRE);
	pLabel->SetColour(0x00, 0x00, 0x00);
	m_pCreditsMenu->AddChild(pLabel);

	pLabel = new Label();
	pLabel->Initialise("Danyal");
	pLabel->SetAlignment(ALIGN_CENTRE);
	pLabel->SetColour(0x00, 0x00, 0x00);
	m_pCreditsMenu->AddChild(pLabel);

	pLabel = new Label();
	pLabel->Initialise("Tammika");
	pLabel->SetAlignment(ALIGN_CENTRE);
	pLabel->SetColour(0x00, 0x00, 0x00);
	m_pCreditsMenu->AddChild(pLabel);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Back");
	pButton->SetSelected(true);
	pButton->SetOnPress([&] { PopMenu(); });
	m_pCreditsMenu->AddChild(pButton);

	m_pCreditsMenu->PositionElements(Game::screenDimensions);

	m_menuStack.push(m_pCreditsMenu);
}

void MenuState::PushMenu(Menu* menu)
{
}

void
MenuState::PopMenu()
{
	delete m_menuStack.top();
	m_menuStack.pop();
}

