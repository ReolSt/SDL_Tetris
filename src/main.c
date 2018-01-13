#include "include/library.h"

int             width = 1280;
int             height = 720;

SDL_Window     *mainwindow;
SDL_Renderer   *renderer;
SDL_Event       event;

SDL_KeyboardEvent *keyboardevent;
SDL_MouseMotionEvent *motionevent;
SDL_MouseButtonEvent *buttonevent;

Mix_Chunk      *bgm;
int             channel;

SDL_Texture    *menu1;
SDL_Texture    *menu2;

SDL_Texture    *startimgtexture;
SDL_Texture    *blocktexture;
SDL_Texture    *darkblocktexture;

TTF_Font       *menuttf;

SDL_Rect        blockrect = { 32, 32, 28, 28 };
SDL_Rect        gameplaterect = { 60, 60, 28, 28 };
SDL_Rect        currentblock = { 0, 0, 0, 0 };

__flags         mainflags = { 0, 0 };

int             currentshape = 0;
int             speed = 0;
int             speedcount = 1;

Uint8           map[23][13] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

Uint8           gamemap[21][11] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

__tetromino     tetromino;

int
main(int __attribute__ ((unused)) argc, char **
     __attribute__ ((unused)) argv) {
  mainloop:
    while (mainflags.running) {

	while (SDL_PollEvent(&event)) {
	    switch (event.type) {
	    case SDL_KEYDOWN:

		if (event.key.keysym.sym == SDLK_RIGHT) {
		    if (__xcollisioncheck(&tetromino, *gamemap, 21, 11, 1)
			== 0) {
			__movetetromino(&tetromino, *gamemap, 21, 11, 1,
					0);
		    }

		}

		if (event.key.keysym.sym == SDLK_LEFT) {
		    if (__xcollisioncheck(&tetromino, *gamemap, 21, 11, 0)
			== 0) {
			__movetetromino(&tetromino, *gamemap, 21, 11, -1,
					0);
		    }
		}

		if (event.key.keysym.sym == SDLK_UP) {
		    __rotatetetromino(&tetromino, *gamemap, 21, 11, 0);
		}

		if (event.key.keysym.sym == SDLK_DOWN) {
		    speed++;
		}

		if (event.key.keysym.sym == SDLK_ESCAPE) {
		    __handlequit(&event, &mainflags);
		}

		break;
	    case SDL_MOUSEBUTTONDOWN:
		break;
	    case SDL_MOUSEMOTION:
		break;
	    case SDL_QUIT:
		__handlequit(&event, &mainflags);
		break;
	    default:
		break;
	    }
	}

	if (__ycollisioncheck(&tetromino, *gamemap, 21, 11) == 0) {
	    __movetetromino(&tetromino, *gamemap, 21, 11, 0, 1);
	} else {
	    if(__createblock(&tetromino, rand() % 7, *map, 21, 11) == 1) {
		__handlequit(&event, &mainflags);
	    }
	    else {
		__linefilledcheck(&tetromino, *gamemap, 21, 11);
	    }
	}
	

	if (Mix_Playing(channel) != 0) {
	}

	

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, startimgtexture, NULL, NULL);

	__drawmap(renderer, blocktexture, darkblocktexture, &blockrect,
		  *map, 23, 13);

	__drawmap(renderer, blocktexture, darkblocktexture, &gameplaterect,
		  *gamemap, 21, 11);


	SDL_RenderPresent(renderer);



	SDL_Delay(200);
    }

    if (!mainflags.init) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_JPG);

	__initwindow(&mainwindow, "debug", width, height);
	__initrenderer(&renderer, &mainwindow);
	__inithandler(&mainflags);
	__initprinter();

	keyboardevent = &event.key;
	buttonevent = &event.button;
	motionevent = &event.motion;

	__loadttf(&menuttf, "font/LM-Regular.ttf", 20);


	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
	bgm = Mix_LoadWAV("sound/bgm.wav");

	channel = Mix_PlayChannel(-1, bgm, 0);

	startimgtexture = IMG_LoadTexture(renderer, "img/white2.png");
	blocktexture = IMG_LoadTexture(renderer, "img/block.png");
	darkblocktexture = IMG_LoadTexture(renderer, "img/darkblock.png");

	srand(time(NULL));

	__createblock(&tetromino, 0, *gamemap, 21, 11);

	mainflags.init = 1;
	goto mainloop;
    }
    __destroyttf(&menuttf);
    __destroywindow(&mainwindow);
    __destroyrenderer(&renderer);
    __destroyprinter();
    Mix_FreeChunk(bgm);
    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
