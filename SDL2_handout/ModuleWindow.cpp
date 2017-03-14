#include "Globals.h" 
#include "Application.h"
#include "ModuleWindow.h"
#include "windows.h"




// TODO 2: Init the library and check for possible error
// using SDL_GetError()

// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors

// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)

bool ModuleWindow::Init()
{
	window = SDL_CreateWindow("ZORRO",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_RESIZABLE);

	if (window == NULL)
    {
		LOG("%s", SDL_GetError());
		return false;
	}
	else
	{
		return true;
	}
}

bool ModuleWindow::CleanUp()
{
	return true;
}