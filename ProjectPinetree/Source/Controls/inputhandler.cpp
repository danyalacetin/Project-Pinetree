// COMP710 GP 2D Framework 2019

// This include:
#include "inputhandler.h"

// Local includes:
#include "../game.h"
#include "../logmanager.h"

// Library includes:
#include <cassert>

InputHandler::InputHandler()
{
	
}

InputHandler::~InputHandler()
{
}

bool 
InputHandler::Initialise()
{
	return (true);
}

void
InputHandler::ProcessInput(Game& game)
{
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		InputType type = InputType::NONE;
		InputCommand command = InputCommand::NONE;
		Vector2f mousePosition = Vector2f();

		switch (event.type)
		{
		case SDL_KEYDOWN:
			type = InputType::BUTTON_DOWN;
			command = GetKeyCommand(event);
			break;
		case SDL_KEYUP:
			type = InputType::BUTTON_UP;
			command = GetKeyCommand(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			type = InputType::BUTTON_DOWN;
			command = InputCommand::CLICK;
			break;
		case SDL_MOUSEMOTION:
			type = InputType::MOUSE_MOTION;
			command = InputCommand::NONE;
			mousePosition.x = static_cast<float>(event.motion.x);
			mousePosition.y = static_cast<float>(event.motion.y);
			break;
		default:
			break;
		}

		game.HandleInput(UserInput{ command, type, mousePosition });
	}
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
