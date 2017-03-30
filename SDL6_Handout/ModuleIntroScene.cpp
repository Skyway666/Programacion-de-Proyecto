#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleIntroScene.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneSpace.h"
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleIntroScreen::ModuleIntroScreen()
{}

ModuleIntroScreen::~ModuleIntroScreen()
{}

// Load assets
bool ModuleIntroScreen::Start()
{
	LOG("Loading space scene");
	App->scene_space->Disable();
	intro = App->textures->Load("rtype/intro.png");
	return true;
}

// UnLoad assets
bool ModuleIntroScreen::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(intro);
	return true;
}

// Update: draw background
update_status ModuleIntroScreen::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
 		App->fade->FadeToBlack(this, App->scene_space, 2.0f);
	}
	// Draw everything --------------------------------------
	App->render->Blit(intro, 0, 0, NULL);

	return UPDATE_CONTINUE;
}