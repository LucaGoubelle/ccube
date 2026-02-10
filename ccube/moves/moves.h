//@author: LucaGoubelle 🦊
#pragma once
#include "stdMoves.h"

struct Cube simpleMove(struct Cube cube, char* mv){
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
    else
        return cube;
}

int count(char** mvs){
    int i = 0;
    while(mvs[i] != NULL)
        i++;
    return i;
}

struct Cube multiMoves(struct Cube cube, char** mvs){
    int size = count(mvs);
    printf("%d", size);
    int i;
    for(i=0;i<size;i++)
        cube = simpleMove(cube, mvs[i]);
    return cube;
}
