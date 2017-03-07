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
	SDL_Surface * surface;
	SDL_Surface * STRONCO;
	SDL_Surface * hadowken[50];
	SDL_Texture * textura;
	SDL_Texture * textura2;
	SDL_Texture * textura3;
	
	int swich = 0;
	int once = 0;
	int shot = 0;
	int counter = 0;
	int counter2 = 0;

	window = SDL_CreateWindow(
		"Pitufo desangrado",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		0
	);
	renderer = SDL_CreateRenderer(window, -1, 0);
	surface = SDL_LoadBMP("hello.bmp");
	if (surface == NULL )
	{
		printf("%s\n", SDL_GetError());
	}

	STRONCO = SDL_LoadBMP("goodbye.bmp");
	if (STRONCO == NULL)
	{
		printf("%s\n", SDL_GetError());
	}
	while (counter != 50)
	{
    hadowken[counter] = SDL_LoadBMP("hadowken.bmp");
	hadowken[counter]->clip_rect.y = 98749;
	   if (hadowken == NULL)
	    {
		printf("%s", SDL_GetError());
	   }
	   ++counter;
	}
	counter = 0;
	

	textura = SDL_CreateTextureFromSurface(renderer, surface);
	textura2 = SDL_CreateTextureFromSurface(renderer, hadowken[0]);
	textura3 = SDL_CreateTextureFromSurface(renderer, STRONCO);
	
	while (counter != 1)
	{
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderClear(renderer);
		if (swich %2 == 0 )
		{
		SDL_RenderCopy(renderer, textura, NULL, &surface->clip_rect);
		}
		if (swich % 2 != 0)
		{
			SDL_RenderCopy(renderer, textura3, NULL, &surface->clip_rect);
		}
		
			counter = 0;
			while (counter != 50)
			{ 
		       SDL_RenderCopy(renderer, textura2, NULL, &hadowken[counter]->clip_rect);
			   counter++;
			}
		   if (once % 10 == 0)
		   {
			   counter = 0;
			   while (counter != 50)
			   { 
				   
		       hadowken[counter]->clip_rect.x++;
			   counter++;
			   }
		   }
	     
		

		SDL_RenderPresent(renderer);
		once++;



		if (SDL_PollEvent(&event))
		{
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE && event.type == SDL_KEYDOWN)
			{
				counter = 1;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_UP && event.type == SDL_KEYDOWN)
			{
				surface->clip_rect.y -= 6;
            }
			if (event.key.keysym.scancode == SDL_SCANCODE_DOWN && event.type == SDL_KEYDOWN)
			{
				surface->clip_rect.y += 6;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT && event.type == SDL_KEYDOWN)
			{
				surface->clip_rect.x += 6;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_LEFT && event.type == SDL_KEYDOWN)
			{
				surface->clip_rect.x -= 6;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && event.type == SDL_KEYDOWN)
			{
			
				if (counter2 == 50)
				{
					counter2 = 0;
				}
				hadowken[counter2]->clip_rect.x = surface->clip_rect.x;
				hadowken[counter2]->clip_rect.y = surface->clip_rect.y;
				++counter2;
				
				
			
				
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_T && event.type == SDL_KEYDOWN)
			{
				swich = 1;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_N && event.type == SDL_KEYDOWN)
			{
				swich = 2;
			}


		}


	}
	
	SDL_Quit();

	return (EXIT_SUCCESS);
}