#include "Application.h"
#include "ModuleWindow.h"

Application::Application()
{
	win = new ModuleWindow();
	modules[0] = new Module();
}	

bool Application::Init()
{
	bool ret = true;

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = win->Init();

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->PreUpdate();

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->Update();

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->PostUpdate();

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = win->CleanUp();

	return ret;
}