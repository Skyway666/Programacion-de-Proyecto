#include <stdio.h>
#include<stdlib.h>
#include "SDL/include/SDL.h"

#pragma comment (lib, "SDL/lib/x86/SDL2.lib")
#pragma comment (lib, "SDL/lib/x86/SDL2main.lib")
int main(int argc, char*argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window;  
	SDL_Renderer* renderer;
	SDL_Event event;

         

										   
	window = SDL_CreateWindow(
		"Pitufo desangrado",                 
		SDL_WINDOWPOS_CENTERED,       
		SDL_WINDOWPOS_CENTERED,       
		640,                              
		480,                               
		0                
	);
	renderer = SDL_CreateRenderer(window, -1, 0);

   
	
    


	
	
	SDL_Rect rectangle;
    rectangle.x = 270;
	rectangle.y = 200;
	rectangle.w = 80;
	rectangle.h = 80;

	SDL_Keysym escape;
	escape.scancode = SDL_SCANCODE_ESCAPE;
	escape.sym = SDL_SCANCODE_ESCAPE;
	escape.mod = KMOD_NONE;
	
    
	


	
   
	int counter = 0;
	while (counter != 1)
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
		SDL_RenderFillRect(renderer, &rectangle);
		SDL_RenderPresent(renderer);




		if (SDL_PollEvent(&event))
		{
			if (event.key.keysym.scancode == escape.scancode)
			{
				counter = 1;
			}


		}


	}

	SDL_Quit();

	return (EXIT_SUCCESS);
}