// This include:
#include "splashstate.h"

// Local includes:
#include "../SDL Render/sprite.h"
#include "../game.h"
#include "../Menus/splashscreen.h"
#include "../SDL Render/backbuffer.h"
#include "../logmanager.h"
#include "../Utilities/gameutils.h"
#include "../mouse.h"
#include "menustate.h"

// Library includes:
#include <cassert>
#include <cstdio>

SplashState SplashState::m_splashState;

SplashState::SplashState()
	: m_pFMODSprite(0)
	, m_pBox2DSprite(0)
	, m_bIsFinished(false)
{

}

bool SplashState::Initialise()
{
	SplashScreen* pSplashScreen = 0;

	m_pFMODSprite = BackBuffer::CreateSprite("FMOD.png");
	pSplashScreen = new SplashScreen();
	pSplashScreen->Initialise(m_pFMODSprite);
	m_splashStack.push(pSplashScreen);

	m_pBox2DSprite = BackBuffer::CreateSprite("Box2D.png");
	pSplashScreen = new SplashScreen();
	pSplashScreen->Initialise(m_pBox2DSprite);
	m_splashStack.push(pSplashScreen);

	return true;
}

void SplashState::Cleanup()
{
	while (!m_splashStack.empty())
	{
		delete m_splashStack.top();
		m_splashStack.pop();
	}

	delete m_pBox2DSprite;
	m_pBox2DSprite = 0;

	delete m_pFMODSprite;
	m_pFMODSprite = 0;
}

void SplashState::HandleEvents(Game& game, UserInput input)
{
	if (m_bIsFinished)
	{
		ChangeState(game, MenuState::GetInstance());
	}
	else
	{
		if (input.type == InputType::BUTTON_DOWN)
		{
			switch (input.command)
			{
			case InputCommand::ENTER:
				m_splashStack.top()->Setfinished();
				break;
			case InputCommand::CLICK:
				m_splashStack.top()->Setfinished();
				break;
			case InputCommand::ESCAPE:
				game.Quit();
				break;
			default:
				break;
			}
		}
	}
}

void
SplashState::Process(float deltaTime)
{
	if (!m_splashStack.empty())
	{
		if (m_splashStack.top()->Isfinished())
		{
			delete m_splashStack.top();
			m_splashStack.pop();

			if (m_splashStack.empty())
			{
				m_bIsFinished = true;
			}
		}
		else
		{
			m_splashStack.top()->Process(deltaTime);
		}
	}
}

void
SplashState::Draw(BackBuffer& backBuffer)
{

	if (!m_splashStack.empty())
	{
		m_splashStack.top()->Draw(backBuffer);
	}
}

void SplashState::ChangeState(Game& game, State* newState)
{
	game.ChangeState(newState);
}

void SplashState::Pause()
{
}

void SplashState::Resume()
{
}

SplashState* SplashState::GetInstance()
{
	return &m_splashState;
}
