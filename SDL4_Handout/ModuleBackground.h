#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();

	bool Start();
	update_status Update();

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
<<<<<<< HEAD
	SDL_Rect background;
	SDL_Rect ship;
	Animation flag;
	Animation girl;
	float var = 0;
	bool up = true;
=======
	SDL_Rect ship;
	SDL_Rect background;
	Animation flag;
	Animation cheer_leader;

	float ship_movy = 0;
	int sense = 0;
>>>>>>> origin/master

};

#endif