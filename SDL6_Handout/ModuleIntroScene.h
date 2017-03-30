#ifndef __MODULEINTROSCENE__
#define __MODULEINTROSCENE__

#include "Module.h"
#include "Globals.h"
class SDL_Texture;

class ModuleIntroScreen : public Module
{
public:
	ModuleIntroScreen();
	~ModuleIntroScreen();

	bool Start();
	update_status Update();
	bool CleanUp();
public:

	SDL_Texture* intro = nullptr;
};








#endif //__MODULEINTROSCENE__

