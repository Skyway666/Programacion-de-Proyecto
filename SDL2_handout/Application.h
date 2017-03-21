#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"
#include "Module.h"

#define NUM_MODULES 1

<<<<<<< HEAD

=======
class ModuleWindow;
>>>>>>> origin/master

class Application
{
public:

	Module* modules[NUM_MODULES];
<<<<<<< HEAD
	//ModuleWindow* win;
=======
	ModuleWindow* win;
>>>>>>> origin/master

public:

	Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

#endif // __APPLICATION_H__