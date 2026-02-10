//@author: LucaGoubelle 🦊
#pragma once
#include "stdMoves.h"

typedef struct {
    Cube (*moveOne)(Cube, char*);
    Cube (*moveMany)(Cube, char**);
} Mover;

Cube simpleMove(Cube cube, char* mv){
    if(mv=="U")
        return moveU(cube);
    else if(mv=="U'")
        return moveUPrime(cube);
    else if(mv=="U2")
        return moveU2(cube);
    else if(mv=="D")
        return moveD(cube);
    else if(mv=="D'")
        return moveDPrime(cube);
    else if(mv=="D2")
        return moveD2(cube);
    else if(mv=="R")
        return moveR(cube);
    else if(mv=="R'")
        return moveRPrime(cube);
    else if(mv=="R2")
        return moveR2(cube);
    else
        return cube;
}

int count(char** mvs){
    int i = 0;
    while(mvs[i] != NULL)
        i++;
    return i;
}

Cube multiMoves(Cube cube, char** mvs){
    int size = count(mvs);
    printf("%d", size);
    int i;
    for(i=0;i<size;i++)
        cube = simpleMove(cube, mvs[i]);
    return cube;
}

Mover getMover(){
    Mover mover;
    mover.moveOne = simpleMove;
    mover.moveMany = multiMoves;
    return mover;
}
