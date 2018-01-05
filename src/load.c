#include "include/library.h"

void
__loadttf(TTF_Font ** fontptr, const char *restrict filename, int size) {
    *fontptr = NULL;
    *fontptr = TTF_OpenFont(filename, size);
    __errorcheck(*fontptr, "loadttf");
}

void
__loadtext(SDL_Renderer * renderer, SDL_Texture ** texture,
	   TTF_Font * font, const char *restrict text, SDL_Color fg,
	   SDL_Color bg) {
    SDL_Surface    *dummysurface = TTF_RenderText(font, text, fg, bg);
    *texture = SDL_CreateTextureFromSurface(renderer, dummysurface);
}

void
__loadtextblended(SDL_Renderer * renderer, SDL_Texture ** texture,
		  TTF_Font * font, const char *restrict text,
		  SDL_Color fg) {
    SDL_Surface    *dummysurface = TTF_RenderText_Solid(font, text, fg);
    *texture = SDL_CreateTextureFromSurface(renderer, dummysurface);
}

void
__loadtextblendedwrapped(SDL_Renderer * renderer, SDL_Texture ** texture,
			 TTF_Font * font, const char *restrict text,
			 SDL_Color fg, Uint32 wraplength) {
    SDL_Surface    *dummysurface =
	TTF_RenderText_Blended_Wrapped(font, text, fg, wraplength);

    *texture = SDL_CreateTextureFromSurface(renderer, dummysurface);
}

void
__loadtextshaded(SDL_Renderer * renderer, SDL_Texture ** texture,
		 TTF_Font * font, const char *restrict text, SDL_Color fg,
		 SDL_Color bg) {
    SDL_Surface    *dummysurface =
	TTF_RenderText_Shaded(font, text, fg, bg);
    *texture = SDL_CreateTextureFromSurface(renderer, dummysurface);
}


void
__loadtextsolid(SDL_Renderer * renderer, SDL_Texture ** texture,
		TTF_Font * font, const char *restrict text, SDL_Color fg) {
    SDL_Surface    *dummysurface = TTF_RenderText_Solid(font, text, fg);
    *texture = SDL_CreateTextureFromSurface(renderer, dummysurface);
}
