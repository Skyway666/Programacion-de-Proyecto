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
	SDL_Texture * textura;
	int swich = 0;



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
		printf("%s", SDL_GetError());
	}
	




	SDL_Rect rectangle;
	rectangle.x = 270;
	rectangle.y = 200;
	rectangle.w = 80;
	rectangle.h = 80;




	




	int counter = 0;
	while (counter != 1)
	{
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderClear(renderer);
		if (swich %2 == 0)
		{
		textura = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_RenderCopy(renderer, textura, NULL, &surface->clip_rect);
		}
		else
		{
			textura = SDL_CreateTextureFromSurface(renderer, STRONCO);
			SDL_RenderCopy(renderer, textura, NULL, &surface->clip_rect);
		}
		SDL_RenderPresent(renderer);
	



		if (SDL_PollEvent(&event))
		{
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				counter = 1;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_UP)
			{
				surface->clip_rect.y -= 6;
            }
			if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
			{
				surface->clip_rect.y += 6;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				surface->clip_rect.x += 6;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
			{
				surface->clip_rect.x -= 6;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_T )
			{
				swich = 1;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_N)
			{
				swich = 2;
			}


		}


	}
	SDL_FreeSurface(surface);
	SDL_Quit();

	return (EXIT_SUCCESS);
}