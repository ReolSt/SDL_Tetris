#ifndef __INIT_H
#define __INIT_H
#include "library.h"

void            __initwindow(SDL_Window **, const char *restrict, int,
			     int);
void            __initrenderer(SDL_Renderer **, SDL_Window **);
#endif
