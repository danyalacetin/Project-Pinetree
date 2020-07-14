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
#include "gamestate.h"
#include "../Controls/mouse.h"

// Library includes:
#include <cassert>
#include <cstdio>

MenuState MenuState::menuState;

MenuState::MenuState()
	: State()
	, m_pTitleScreen(0)
	, m_pButtonSprite(0)
	, m_pMouseInstance(0)
{

}

void MenuState::MouseClicked(Vector2f position, Game& game)
{
	m_menuStack.top()->MouseClicked(position, game);
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

	CreateMainMenu();
	m_pMouseInstance = MousePointer::GetInstance();

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

	m_pMouseInstance = nullptr;
}

void MenuState::HandleEvents(Game& game, UserInput input)
{
	switch (input.type)
	{
	case InputType::MOUSE_MOTION:
		if (!m_menuStack.empty())
		{
			m_menuStack.top()->MouseMoved(input.mousePosition);
		}

		break;
	case InputType::BUTTON_DOWN:
		switch (input.key)
		{
		case InputKey::CLICK:
			if (!m_menuStack.empty())
			{
				m_menuStack.top()->MouseClicked(input.mousePosition, game);
			}
			break;
		case InputKey::ESCAPE:
			game.Quit();
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
	}

	m_pMouseInstance->Process(deltaTime);
}

void
MenuState::Draw(BackBuffer& backBuffer)
{
	if (!m_menuStack.empty())
	{
		m_menuStack.top()->Draw(backBuffer);
	}

	m_pMouseInstance->Draw(backBuffer);
}

void MenuState::ChangeState(Game& game, State* newState)
{
	game.ChangeState(newState);
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
	Menu* pMenu;

	pMenu = new Menu();
	pMenu->Initialise();

	pImage = new Image();
	pImage->Initialise(m_pTitleScreen);
	pMenu->AddChild(pImage);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "New Game");
	pButton->SetOnPress([&](Game& game) { ChangeState(game, GameState::GetInstance()); });
	pMenu->AddChild(pButton);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Options");
	pButton->SetOnPress([&] { CreateOptionsMenu(); });
	pMenu->AddChild(pButton);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Credits");
	pButton->SetOnPress([&] {CreateCreditsMenu(); });
	pMenu->AddChild(pButton);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Quit");
	pButton->SetOnPress([&] (Game& game){ Quit(game); });
	pMenu->AddChild(pButton);

	pMenu->PositionElements(Game::screenDimensions);

	m_menuStack.push(pMenu);
}

void
MenuState::CreateOptionsMenu()
{
	Label* pLabel;
	Button* pButton;
	Menu* pMenu;

	pMenu = new Menu();
	pMenu->Initialise();

	pLabel = new Label();
	pLabel->Initialise("Options");
	pLabel->SetAlignment(ALIGN_CENTRE);
	pLabel->SetColour(0x00, 0x00, 0x00);
	pMenu->AddChild(pLabel);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Back");
	pButton->SetSelected(true);
	pButton->SetOnPress([&] { PopMenu(); });
	pMenu->AddChild(pButton);

	pMenu->PositionElements(Game::screenDimensions);

	m_menuStack.push(pMenu);
}

void
MenuState::CreateCreditsMenu()
{
	Label* pLabel;
	Button* pButton;
	Menu* pMenu;
	
	pMenu = new Menu();
	pMenu->Initialise();

	pLabel = new Label();
	pLabel->Initialise("Credits");
	pLabel->SetAlignment(ALIGN_CENTRE);
	pLabel->SetColour(0xFF, 0x00, 0x00);
	pMenu->AddChild(pLabel);

	pLabel = new Label();
	pLabel->Initialise("Aidan");
	pLabel->SetAlignment(ALIGN_CENTRE);
	pLabel->SetColour(0x00, 0x00, 0x00);
	pMenu->AddChild(pLabel);

	pLabel = new Label();
	pLabel->Initialise("Danyal");
	pLabel->SetAlignment(ALIGN_CENTRE);
	pLabel->SetColour(0x00, 0x00, 0x00);
	pMenu->AddChild(pLabel);

	pLabel = new Label();
	pLabel->Initialise("Tammika");
	pLabel->SetAlignment(ALIGN_CENTRE);
	pLabel->SetColour(0x00, 0x00, 0x00);
	pMenu->AddChild(pLabel);

	pButton = new Button();
	pButton->Initialise(m_pButtonSprite, "Back");
	pButton->SetOnPress([&] { PopMenu(); });
	pMenu->AddChild(pButton);

	pMenu->PositionElements(Game::screenDimensions);

	m_menuStack.push(pMenu);
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

void MenuState::Quit(Game& game)
{
	game.Quit();
}

