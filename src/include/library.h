#ifndef __LIBRARY_H
#define __LIBRARY_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#if defined(__LINUX__) || defined(__UNIX__)
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "init.h"
#include "destroy.h"
#include "error.h"
#include "draw.h"
#include "load.h"
#include "game.h"
#endif
