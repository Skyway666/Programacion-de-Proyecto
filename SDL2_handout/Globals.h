#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <windows.h>
#include <stdio.h>

#define LOG(txt) OutputDebugString(txt)

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Configuration -----------
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define FULLSCREEN 0
#define FULL SDL_WINDOW_FULLSCREEN

#define FULLDESK SDL_WINDOW_FULLSCREEN_DESKTOP

#define OPGL SDL_WINDOW_OPENGL

#define WINHID SDL_WINDOW_HIDDEN

#define NOBORDSDL_WINDOW_BORDERLESS

#define RESIZ SDL_WINDOW_RESIZABLE

#define MINIM SDL_WINDOW_MINIMIZED

#define MAX SDL_WINDOW_MAXIMIZED

#define IMGRA SDL_WINDOW_INPUT_GRABBED

#define HIDPI SDL_WINDOW_ALLOW_HIGHDPI



#endif // __GLOBALS_H__
