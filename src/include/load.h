#ifndef __LOAD_H
#define __LOAD_H

#include "library.h"

void            __loadttf(TTF_Font **, const char *, int);
void            __loadtext(SDL_Renderer *, SDL_Texture **, TTF_Font *,
			   const char *, SDL_Color, SDL_Color);
void            __loadtextblended(SDL_Renderer *, SDL_Texture **,
				  TTF_Font *, const char *, SDL_Color);
void            __loadtextblendedwrapped(SDL_Renderer *, SDL_Texture **,
					 TTF_Font *, const char *,
					 SDL_Color, Uint32);
void            __loadtextshaded(SDL_Renderer *, SDL_Texture **,
				 TTF_Font *, const char *, SDL_Color,
				 SDL_Color);
void            __loadtextsolid(SDL_Renderer *, SDL_Texture **, TTF_Font *,
				const char *, SDL_Color);

#endif
