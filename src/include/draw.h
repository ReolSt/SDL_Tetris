#ifndef __DRAW_H
#define __DRAW_H

#include "library.h"

void            __drawblock(SDL_Renderer *, SDL_Texture *, int, int, int);
void            __drawshape(SDL_Renderer *, SDL_Texture *, SDL_Rect *,
			    int);
void __drawmap(SDL_Renderer *,SDL_Texture *,SDL_Texture *,SDL_Rect *,Uint8 (*)[23][13]);
#endif
