// COMP710 GP 2D Framework 2019

// This include:
#include "inputhandler.h"

// Local includes:
#include "../game.h"
#include "../logmanager.h"
#include "keyboardbindings.h"
#include "inputeventhandler.h"

// Library includes:
#include <cassert>

InputHandler::InputHandler()
: m_pKeyboardBindings(0)
{
	
}

InputHandler::~InputHandler()
{
	delete m_pKeyboardBindings;
	m_pKeyboardBindings = nullptr;

	InputEventHandler::DestroyInstance();
}

bool 
InputHandler::Initialise()
{
	m_pKeyboardBindings = new KeyboardBindings();
	m_pKeyboardBindings->Initialise();

	return (true);
}

void 
InputHandler::ProcessInput(Game& game, InputStateType state)
{
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Quit(state);
			break;
		case SDL_KEYDOWN:
			KeyDown(event.key.keysym.sym, state);
			break;
		case SDL_KEYUP:
			KeyUp(event.key.keysym.sym, state);
			break;
		case SDL_MOUSEBUTTONDOWN:
			MouseClick(event, state);
			break;
		default:
			break;
		}
	}
}



void InputHandler::RunCommand(InputStateType state, InputCommand command)
{
	RunCommand(state, command, 1.0f);
}

void InputHandler::RunCommand(InputStateType state, InputCommand command, float fAmmount)
{
	InputEventHandler::GetInstance().Call(state, command, fAmmount);
}

void InputHandler::KeyDown(SDL_Keycode keycode, InputStateType state)
{
	if (keycode == SDLK_ESCAPE)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "escape");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_a)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "a");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_d)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "d");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_SPACE)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "space");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_w)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "w");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_s)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "s");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_RETURN)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "enter");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_UP)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "up");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_DOWN)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "down");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_RIGHT)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "right");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_LEFT)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "left");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_r)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "test");
		RunCommand(state, command);
	}
}

void InputHandler::KeyUp(SDL_Keycode keycode, InputStateType state)
{
	if (keycode == SDLK_LEFT)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "stop");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_RIGHT)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "stop");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_a)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "stop");
		RunCommand(state, command);
	}
	else if (keycode == SDLK_d)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "stop");
		RunCommand(state, command);
	}
}

void InputHandler::MouseClick(SDL_Event & event, InputStateType state)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		InputCommand command = m_pKeyboardBindings->GetCommand(state, "leftclick");
		RunCommand(state, command);
	}
}

void InputHandler::Quit(InputStateType state)
{
	RunCommand(state, InputCommand::QUIT);
}
