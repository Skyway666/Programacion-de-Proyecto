#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

#include "SDL/include/SDL.h"
<<<<<<< HEAD

// TODO 1: Create the declaration of ModuleWindow class
class ModuleWindow
=======
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )
// TODO 1: Create the declaration of ModuleWindow class

class ModuleWindow: public Module
>>>>>>> origin/master
{
public:

	virtual bool Init();
	virtual bool CleanUp();
private:
<<<<<<< HEAD

	SDL_Window * window;
  
};


=======
	SDL_Window*window;
};
>>>>>>> origin/master
#endif // __ModuleWindow_H__