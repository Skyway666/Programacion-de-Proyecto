#include <stdio.h>
#include<stdlib.h>
#include "SDL/include/SDL.h"
#include "SDL/include/SDL_image.h"

#pragma comment (lib, "SDL/lib/x86/SDL2.lib")
#pragma comment (lib, "SDL/lib/x86/SDL2main.lib")
#pragma comment (lib, "SDL/lib/x86/SDL2_image.lib")

int main(int argc, char*argv[])
{
	IMG_INIT_JPG;
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
	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;
	bool escape = false;
	bool bar = false;
	bool T = false;
	bool N = false;
	window = SDL_CreateWindow(
		"Pitufo desangrado",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		0
	);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	surface = IMG_Load("ryu.png");
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
    hadowken[counter] = IMG_Load("hadowken.png");
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
	surface->clip_rect.w = 150;
	surface->clip_rect.h = 150;
	counter = 0;
	while (counter != 50)
	{
		hadowken[counter]->clip_rect.w = 62;
		hadowken[counter]->clip_rect.h = 62;
		++counter;
	}
	counter = 0;

	SDL_Rect cabesa;
	cabesa.x = 518;
	cabesa.y = 22;
	cabesa.h = 169;
	cabesa.w = 168;


	

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
		guile->clip_rect.x-= 6;
		ryu->clip_rect.x-= 6;
		}
		if (ryu->clip_rect.x < -1)
		{
			guile->clip_rect.x = ryu->clip_rect.x + 1000;

		}
		if (guile->clip_rect.x < -1)
		{
			ryu->clip_rect.x =guile->clip_rect.x + 1000;
			 
		}
		
		
		
			counter = 0;
			while (counter != 50)
			{ 
		       SDL_RenderCopy(renderer, textura2, NULL, &hadowken[counter]->clip_rect);
			   counter++;
			}
		   if (once % 1 == 0)
		   {
			   counter = 0;
			   while (counter != 50)
			   { 
				   
		       hadowken[counter]->clip_rect.x+= 6;
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
		counter = 0;
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_KEYUP:
			{
				   switch (event.key.keysym.scancode)
				  { 
				case SDL_SCANCODE_UP: up = false; break;
				case SDL_SCANCODE_DOWN: down = false; break;
				case SDL_SCANCODE_RIGHT: right = false; break;
				case SDL_SCANCODE_LEFT: left = false; break;
				case SDL_SCANCODE_SPACE: bar = false; break;

				  }
				break;
			}
			case SDL_KEYDOWN:
			{
			       switch (event.key.keysym.scancode)
			     { 
			       case SDL_SCANCODE_UP: up = true; break;
			       case SDL_SCANCODE_DOWN: down = true; break;
			       case SDL_SCANCODE_RIGHT: right = true; break;
			       case SDL_SCANCODE_LEFT: left = true; break;
				   case SDL_SCANCODE_ESCAPE: escape = true; break;
				   case SDL_SCANCODE_SPACE: bar = true; break;
                   case SDL_SCANCODE_T: T = true; break;
				   case SDL_SCANCODE_N: N = true; break;
			     }
				   break;
			}
			}
        }
		
			 
			if (escape == true)
			{
				counter = 1;
			}
			if (up == true)
			{
				surface->clip_rect.y -= 6;
            }
			if (down == true )
			{
				surface->clip_rect.y += 6;
			}
			if (right == true )
			{
				surface->clip_rect.x += 6;
			}
			if (left == true)
			{
				surface->clip_rect.x -= 6;
			}
			if (bar == true)
			{
			
				if (counter2 == 50)
				{
					counter2 = 0;
				}
				hadowken[counter2]->clip_rect.x = surface->clip_rect.x+120 ;
				hadowken[counter2]->clip_rect.y = surface->clip_rect.y+ 15;
				++counter2;
				
				
			
				
			}
			if (T == true)
			{
				swich = 1;
			}
			if (N == true)
			{
				swich = 2;
			}

           
		


	}
	
	SDL_Quit();

	return (EXIT_SUCCESS);
}