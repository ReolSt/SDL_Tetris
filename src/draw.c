#include "include/library.h"


void
__drawblock(SDL_Renderer * renderer, SDL_Texture * block, int size, int x,
	    int y) {
    SDL_Rect        blockrect = { x, y, size, size };
    SDL_RenderCopy(renderer, block, NULL, &blockrect);
}

void
__drawshape(SDL_Renderer * renderer, SDL_Texture * block, SDL_Rect * rect,
	    int shape) {
    SDL_Rect        dummy = { rect->x, rect->y, rect->w, rect->h };
    if (shape == 0) {
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.y += dummy.h;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x -= dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
    }
    if (shape == 1) {
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
    }
    if (shape == 2) {
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x -= dummy.w;
	dummy.y += dummy.h;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x -= dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
    }
    if (shape == 3) {
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.y += dummy.h;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
    }
    if (shape == 4) {
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x -= dummy.w;
	dummy.y += dummy.h;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
    }
    if (shape == 5) {
	dummy.x += dummy.w * 2;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.y += dummy.h;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x -= dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x -= dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
    }
    if (shape == 6) {
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.x += dummy.w;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
	dummy.y += dummy.h;
	SDL_RenderCopy(renderer, block, NULL, &dummy);
    }
}
