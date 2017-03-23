<<<<<<< HEAD
#include "Globals.h" 
#include "Application.h"
#include "ModuleWindow.h"
#include "windows.h"




=======
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
>>>>>>> origin/master
// TODO 2: Init the library and check for possible error
// using SDL_GetError()

// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors

// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)

bool ModuleWindow::Init()
{
<<<<<<< HEAD
	window = SDL_CreateWindow("ZORRO",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_RESIZABLE);

	if (window == NULL)
    {
		LOG("%s", SDL_GetError());
=======
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		LOG("An error has ocurred when initializing SDL : %s", SDL_GetError());
>>>>>>> origin/master
		return false;
	}
	else
	{
<<<<<<< HEAD
=======
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
>>>>>>> origin/master
		return true;
	}
}

<<<<<<< HEAD
bool ModuleWindow::CleanUp()
{
	return true;
}
=======
bool ModuleWindow :: CleanUp()
{
	SDL_Quit();
	return true;
}
>>>>>>> origin/master
