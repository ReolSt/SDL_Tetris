#ifndef __GAME_H
#define __GAME_H

#include "library.h"

typedef struct {
    int             x;
    int             y;
} __block;
typedef struct {
    __block         blocks[4];
    int             kind;
} __tetromino;

int             __createblock(__tetromino *, int, Uint8 *, int, int);
void            __movetetromino(__tetromino *, Uint8 *, int, int, int,
				int);
void            __rotatetetromino(__tetromino *, Uint8 *, int, int, int);
int             __xcollisioncheck(__tetromino *, Uint8 *, int, int, int);
int             __ycollisioncheck(__tetromino *, Uint8 *, int, int);
int             __linefilledcheck(__tetromino *,Uint8 *, int, int);
int             __gameovercheck(Uint8 *, int, int);

#endif
