#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )
// TODO 1: Create the declaration of ModuleWindow class

class ModuleWindow
{
public:

	virtual bool Init();
	virtual bool CleanUp();
private:
	SDL_Window*window;
};
#endif // __ModuleWindow_H__