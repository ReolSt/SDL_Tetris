#include "include/library.h"

void
__initwindow(SDL_Window ** windowptr, const char *restrict text, int width,
	     int height) {
    *windowptr =
	SDL_CreateWindow(text, SDL_WINDOWPOS_UNDEFINED,
			 SDL_WINDOWPOS_UNDEFINED, width, height,
			 SDL_WINDOW_OPENGL);
    __errorcheck(*windowptr, "initwindow");
}

void
__initrenderer(SDL_Renderer ** rendererptr, SDL_Window ** windowptr) {
    *rendererptr = NULL;
    *rendererptr = SDL_CreateRenderer(*windowptr, -1,
				      SDL_RENDERER_ACCELERATED);
    __errorcheck(*rendererptr, "renderer");
}
