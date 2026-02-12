//@author: LucaGoubelle 🦊
#pragma once
#include "../data/cube.h"
#include "moves.h"
#include <time.h>

typedef struct {
    Cube (*scrambling)(Cube);
} SCRAMBLER;

const int NB_SCRAMBLES = 2;              

char* scramble1[] = {
    "F'","R'","F","L'","F2","D'","R2","U'","R'","L2","U","F2","D2","F2","D'","F2","D'","F2","R2","U'",
    NULL
};
char* scramble2[] = {
    "R'","D2","F","L","D", "U","F2","R'","F2","D", "F2","U'","F2","D2","F2", "L2","D","F2",
    NULL
};

char** scrambles[] = {
    scramble1, scramble2
};

Cube _scrambleCube(Cube cube){
    srand(time(NULL));
    int randint = rand() % NB_SCRAMBLES;
    char** scramble = scrambles[randint];
    MOVER mvr = Mover();
    cube = mvr.moveMany(cube, scramble);
    return cube;
}

SCRAMBLER Scrambler(){
    SCRAMBLER scrambler;
    scrambler.scrambling = _scrambleCube;
    return scrambler;
}
