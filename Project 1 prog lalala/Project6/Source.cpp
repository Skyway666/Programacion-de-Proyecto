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
	SDL_Surface * guile;
	SDL_Surface * ryu;
	SDL_Texture * textura;
	SDL_Texture * textura2;
	SDL_Texture * textura3;
	SDL_Texture * textura4;
	SDL_Texture * textura5;
	
	
	int swich = 0;
	int once = 0;
	int shot = 0;
	int counter = 0;
	int counter2 = 0;
	bool up = 0;
	bool down = 0;
	bool right = 0;
	bool left = 0;

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
	guile = SDL_LoadBMP("Guile_Stage.bmp");
	if (guile == NULL)
	{
		printf("%s\n", SDL_GetError());
	}
	ryu = SDL_LoadBMP("Ryu_Stage.bmp");
	if (ryu == NULL)
	{
		printf("%s\n", SDL_GetError());
	}
	counter = 0;
	ryu->clip_rect.w = 1000;
	ryu->clip_rect.h = 480;
	ryu->clip_rect.x = 0;
	guile->clip_rect.w = 1000;
	guile->clip_rect.h = 480;
	guile->clip_rect.x = ryu->clip_rect.x + 1000;
	surface->clip_rect.y = 300;
	

	

	textura = SDL_CreateTextureFromSurface(renderer, surface);
	textura2 = SDL_CreateTextureFromSurface(renderer, hadowken[0]);
	textura3 = SDL_CreateTextureFromSurface(renderer, STRONCO);
	textura4 = SDL_CreateTextureFromSurface(renderer, guile);
	textura5 = SDL_CreateTextureFromSurface(renderer, ryu);
		
		
	
	while (counter != 1)
	{   SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	    SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, textura4, NULL, &guile->clip_rect);
		SDL_RenderCopy(renderer, textura5, NULL, &ryu->clip_rect);
		
		if (once % 10 == 0)
		{ 
		guile->clip_rect.x--;
		ryu->clip_rect.x--;
		}
		if (ryu->clip_rect.x == -1)
		{
			guile->clip_rect.x = ryu->clip_rect.x + 1000;

		}
		if (guile->clip_rect.x == -1)
		{
			ryu->clip_rect.x =guile->clip_rect.x + 1000;
			 
		}
		
		
		
			counter = 0;
			while (counter != 50)
			{ 
		       SDL_RenderCopy(renderer, textura2, NULL, &hadowken[counter]->clip_rect);
			   counter++;
			}
		   if (once % 5 == 0)
		   {
			   counter = 0;
			   while (counter != 50)
			   { 
				   
		       hadowken[counter]->clip_rect.x++;
			   counter++;
			   }
		   }
	    if (swich %2 == 0 )
		{
		SDL_RenderCopy(renderer, textura, NULL, &surface->clip_rect);
		}
		if (swich % 2 != 0)
		{
			SDL_RenderCopy(renderer, textura3, NULL, &surface->clip_rect);
		}
		
		SDL_RenderPresent(renderer);
		once++;


		if (SDL_PollEvent(&event))
		{
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				counter = 1;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_UP )
			{
				surface->clip_rect.y -= 6;
            }
			if (event.key.keysym.scancode == SDL_SCANCODE_DOWN )
			{
				surface->clip_rect.y += 6;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT )
			{
				surface->clip_rect.x += 6;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_LEFT )
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