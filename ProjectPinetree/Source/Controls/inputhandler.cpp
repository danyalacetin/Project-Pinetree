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
	UserInput input;

	while (SDL_PollEvent(&event) != 0)
	{
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
			input.type = InputType::MOUSE_MOTION;
			input.command = InputCommand::NONE;
			break;
		default:
			break;
		}

		input.mousePosition.x = static_cast<float>(event.motion.x);
		input.mousePosition.y = static_cast<float>(event.motion.y);

		game.HandleInput(input);
	}

	game.HandleInput(input);
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
