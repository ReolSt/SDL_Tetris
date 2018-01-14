#include "include/library.h"

int
__createblock(__tetromino * tetromino, int kind, Uint8 * map, int
	      __attribute__ ((unused)) size1, int size2) {
    int             center = size2 / 2 - 1;
    int             xs[4];
    int             ys[4];
    tetromino->kind = kind;
    if (kind == 0) {
	for (int i = 0; i < 4; i++) {
	    tetromino->blocks[i].x = i == 0
		|| i == 2 ? center + 1 : center + 2;
	    tetromino->blocks[i].y = i < 2 ? 0 : 1;
	}
    } else if (kind == 1) {
	for (int i = 0; i < 4; i++) {
	    tetromino->blocks[i].x = center + i;
	    tetromino->blocks[i].y = 0;
	}
    } else if (kind == 2) {
	for (int i = 0; i < 4; i++) {
	    tetromino->blocks[i].x =
		i < 2 ? center + 1 + i : center - 2 + i;
	    tetromino->blocks[i].y = i < 2 ? 0 : 1;
	}
    } else if (kind == 3) {
	for (int i = 0; i < 4; i++) {
	    tetromino->blocks[i].x = i < 2 ? center + i : center - 1 + i;
	    tetromino->blocks[i].y = i < 2 ? 0 : 1;
	}
    } else if (kind == 4) {
	for (int i = 0; i < 4; i++) {
	    tetromino->blocks[i].x = i < 1 ? center + 1 : center - 1 + i;
	    tetromino->blocks[i].y = i < 1 ? 0 : 1;
	}
    } else if (kind == 5) {
	for (int i = 0; i < 4; i++) {
	    tetromino->blocks[i].x = i < 1 ? center + 2 : center - 1 + i;
	    tetromino->blocks[i].y = i < 1 ? 0 : 1;
	}
    } else {
	for (int i = 0; i < 4; i++) {
	    tetromino->blocks[i].x = i < 3 ? center + i : center + 2;
	    tetromino->blocks[i].y = i < 3 ? 0 : 1;
	}
    }
    for (int i = 0; i < 4; i++) {
	xs[i] = tetromino->blocks[i].x;
	ys[i] = tetromino->blocks[i].y;
	// if(*((map + xs[i]) + ys[i] * size2) == 1) {
	// return 1;
	// }
	*((map + xs[i]) + ys[i] * size2) = 1;
    }
    return 0;
}

void
__movetetromino(__tetromino * tetromino, Uint8 * map, int size1, int size2,
		int xspeed, int yspeed) {
    int             xs[4];
    int             ys[4];
    for (int i = 0; i < 4; i++) {
	xs[i] = tetromino->blocks[i].x;
	ys[i] = tetromino->blocks[i].y;
	*((map + xs[i]) + ys[i] * size2) = 0;
    }
    for (int i = 0; i < 4; i++) {
	tetromino->blocks[i].x += xspeed;
	tetromino->blocks[i].y += yspeed;
    }
    for (int i = 0; i < 4; i++) {
	xs[i] = tetromino->blocks[i].x;
	ys[i] = tetromino->blocks[i].y;
	*((map + xs[i]) + ys[i] * size2) = 1;
    }
}

void
__rotatetetromino(__tetromino * tetromino, Uint8 * map, int size1,
		  int size2, int direction) {
    __tetromino     rotated;
    Uint8           tmpmap[size1][size2];
    int             xs[4];
    int             ys[4];
    int             centerx;
    int             centery;
    for (int i = 0; i < size1; i++) {
	for (int j = 0; j < size2; j++) {
	    tmpmap[i][j] = *((map + j) + i * size2);
	}
    }

    for (int i = 0; i < 4; i++) {
	xs[i] = tetromino->blocks[i].x;
	ys[i] = tetromino->blocks[i].y;
	tmpmap[xs[i]][ys[i]] = 0;
    }

    for (int i = 0; i < 4; i++) {

	centerx = tetromino->blocks[i].x;
	centery = tetromino->blocks[i].y;

	for (int j = 0; j < 4; j++) {
	    rotated.blocks[i].x = centerx;
	    rotated.blocks[i].y = centery;
	    if (j != i) {
		rotated.blocks[j].x = centerx + (centery - ys[j]);
		rotated.blocks[j].y = centery - (centerx - xs[j]);
	    }

	    if (tmpmap[rotated.blocks[j].x][rotated.blocks[j].y] == 1
		|| rotated.blocks[i].x < 0 || rotated.blocks[i].y < 0
		|| rotated.blocks[i].x >= size2
		|| rotated.blocks[i].y >= size1) {
		break;
	    }

	    if (i < 3 && j == 3) {
		for (int k = 0; k < 4; k++) {
		    *((map + tetromino->blocks[k].x) +
		      tetromino->blocks[k].y * size2) = 0;
		    tetromino->blocks[k].x = rotated.blocks[k].x;
		    tetromino->blocks[k].y = rotated.blocks[k].y;
		    *((map + tetromino->blocks[k].x) +
		      tetromino->blocks[k].y * size2) = 1;

		}
		printf("\n");
		return;

	    } else {
		if (i == 3 && j == 2) {
		    for (int k = 0; k < 4; k++) {
			printf("i = %d j = %d x%d = %d y%d = %d ", i, j, k,
			       rotated.blocks[k].x, k,
			       rotated.blocks[k].y);

			*((map + tetromino->blocks[k].x) +
			  tetromino->blocks[k].y * size2) = 0;
			tetromino->blocks[k].x = rotated.blocks[k].x;
			tetromino->blocks[k].y = rotated.blocks[k].y;
			*((map + tetromino->blocks[k].x) +
			  tetromino->blocks[k].y * size2) = 1;

		    }
		    printf("\n");
		    return;
		}
	    }

	}

    }

    return;
}

int
__xcollisioncheck(__tetromino * tetromino, Uint8 * map, int size1,
		  int size2, int direction) {
    int             xs[4];
    int             ys[4];
    int             flags[3];
    int             condition = direction == 1 ? size2 - 1 : 0;
    int             minmax = tetromino->blocks[0].x;
    for (int i = 0; i < 4; i++) {
	xs[i] = tetromino->blocks[i].x;
	ys[i] = tetromino->blocks[i].y;
	minmax =
	    direction == 1 ? (minmax > xs[i] ? minmax : xs[i]) : (minmax <
								  xs[i] ?
								  minmax :
								  xs[i]);
    }
    if (minmax == condition) {
	return 1;
    }
    for (int i = 0; i < 4; i++) {
	if (*((map + xs[i] + 1) + ys[i] * size2) == 1) {
	    flags[0] = 1;
	    for (int j = 0; j < 4; j++) {
		if (i != j && xs[i] + 1 == xs[j] && ys[i] == ys[j]) {
		    flags[1] = 1;
		}
	    }
	    if (flags[0] == 1 && flags[1] == 0) {
		return 1;
	    } else {
		flags[0] = 0;
		flags[1] = 0;
	    }
	}
	if (*((map + xs[i] - 1) + ys[i] * size2) == 1) {
	    flags[0] = 1;
	    for (int j = 0; j < 4; j++) {
		if (i != j && xs[i] - 1 == xs[j] && ys[i] == ys[j]) {
		    flags[1] = 1;
		}
	    }
	    if (flags[0] == 1 && flags[1] == 0) {
		return 1;
	    } else {
		flags[0] = 0;
		flags[1] = 0;
	    }
	}
    }
    return 0;
}


int
__ycollisioncheck(__tetromino * tetromino, Uint8 * map, int size1,
		  int size2) {
    int             xs[4];
    int             ys[4];
    int             flags[3] = { 0, 0, 0 };
    int             maxys = 0;
    for (int i = 0; i < 4; i++) {
	xs[i] = tetromino->blocks[i].x;
	ys[i] = tetromino->blocks[i].y;
    }
    for (int i = 0; i < 4; i++) {

	if (*((map + xs[i]) + (ys[i] + 1) * size2) == 1) {
	    flags[0] = 1;
	    for (int j = 0; j < 4; j++) {
		if (j != i && xs[i] == xs[j] && ys[i] + 1 == ys[j]) {
		    flags[1] = 1;
		}
	    }
	    if (flags[0] == 1 && flags[1] == 0) {
		return 1;
	    } else {
		flags[0] = 0;
		flags[1] = 0;
	    }
	}
	maxys = ys[i] > maxys ? ys[i] : maxys;
    }
    flags[2] = maxys == size1 - 1 ? 1 : 0;
    if (flags[2] == 1) {
	return 1;
    }
    return 0;
}

int
__linefilledcheck(__tetromino * tetromino, Uint8 * map, int size1,
		  int size2) {
    int             scoretoadd = 0;
    int             flag = 1;
    int             tmp = 0;
    Uint8           tmpmap[size1][size2];
    for (int i = 0; i < size1; i++) {
	for (int j = 0; j < size2; j++) {
	    if (*((map + j) + i * size2) == 0) {
		flag = 0;
		break;
	    }
	}
	if (flag == 1) {
	    scoretoadd++;
	    for (int j = 0; j < size2; j++) {
		*((map + j) + i * size2) = 0;
		tmp = i;
	    }
	} else {
	    flag = 1;
	}
    }
    if (scoretoadd > 0) {
	for (int i = tmp; i > 0; i--) {
	    for (int j = 0; j < size2; j++) {
		if (*((map + j) + (i) * size2) == 1) {
		    for (int k = 0; k < 4; k++) {
			if (j == tetromino->blocks[k].x
			    && i == tetromino->blocks[k].y) {
			    continue;
			}
		    }
		    *((map + j) + (i) * size2) = 0;
		    tmpmap[i + scoretoadd][j] = 1;
		}
	    }
	}
	for (int i = 0; i < size1; i++) {
	    for (int j = 0; j < size2; j++) {
		if (tmpmap[i][j] == 1) {
		    for (int k = 0; k < 4; k++) {
			if (j == tetromino->blocks[k].x
			    && i == tetromino->blocks[k].y) {
			    continue;
			}
		    }
		    *((map + j) + i * size2) = 1;
		}
	    }
	}
    }
    return scoretoadd;
}

int
__gameovercheck(Uint8 * map, int size1, int size2) {
    for (int i = 0; i < size2; i++) {
	if (*((map + i)) == 1) {
	    return 1;
	}
    }
    return 0;
}
