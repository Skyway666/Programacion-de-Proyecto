#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
// TODO 2: Init the library and check for possible error
// using SDL_GetError()

// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors

// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)

bool ModuleWindow::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		LOG("An error has ocurred when initializing SDL : %s", SDL_GetError());
		return false;
	}
	else
	{
		window = SDL_CreateWindow("NANDATO",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640,
			480,
			0
		);
		if (window == 0)
		{
			LOG("An error has ocurred when creating the window: %s", SDL_GetError());

		}
		return true;
	}
}

bool ModuleWindow :: CleanUp()
{
	SDL_Quit();
	return true;
}
