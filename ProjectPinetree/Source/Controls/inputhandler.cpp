// COMP710 GP 2D Framework 2019

// This include:
#include "inputhandler.h"

// Local includes:
#include "../game.h"
#include "../logmanager.h"
#include "../SDL Render/backbuffer.h"
#include "mouse.h"

// Library includes:
#include <cassert>

InputHandler::InputHandler()
	: m_pMouseInstance(0)
	, m_pMouseSprite(0)
{
	
}

InputHandler::~InputHandler()
{
	m_pMouseInstance->Cleanup();
	m_pMouseInstance = nullptr;

	delete m_pMouseSprite;
	m_pMouseSprite = nullptr;
}

bool 
InputHandler::Initialise()
{
	m_pMouseSprite = BackBuffer::CreateSprite("mouse_pointer.png");
	m_pMouseInstance = MousePointer::GetInstance();
	m_pMouseInstance->Initialise(m_pMouseSprite);
	return (true);
}

void
InputHandler::ProcessInput(Game& game)
{
	SDL_Event event;
	UserInput input;

	while (SDL_PollEvent(&event) != 0)
	{
		input.mousePosition.x = static_cast<float>(event.motion.x);
		input.mousePosition.y = static_cast<float>(event.motion.y);

		switch (event.type)
		{
		case SDL_KEYDOWN:
			input.type = InputType::BUTTON_DOWN;
			input.command = GetKeyCommand(event);
			break;
		case SDL_KEYUP:
			input.type = InputType::BUTTON_UP;
			input.command = GetKeyCommand(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			input.type = InputType::BUTTON_DOWN;
			input.command = InputCommand::CLICK;
			break;
		case SDL_MOUSEMOTION:
			input.type = InputType::MOUSE_MOTION; // TODO: is this needed now?
			input.command = InputCommand::NONE;
			m_pMouseInstance->SetPosition(input.mousePosition);
			break;
		default:
			break;
		}

		game.HandleInput(input);
		input.Clean();
	}

	game.HandleInput(input); // TODO: messy
}

InputCommand InputHandler::GetKeyCommand(SDL_Event event)
{
	InputCommand command = InputCommand::NONE;

	switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
		command = InputCommand::ESCAPE;
		break;
	case SDLK_RETURN:
		command = InputCommand::ENTER;
		break;
	default:
		break;
	}

	return command;
}
