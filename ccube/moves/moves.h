//@author: LucaGoubelle 🦊
#pragma once
#include "stdMoves.h"
#include "axisMoves.h"

typedef struct {
    Cube (*moveOne)(Cube, char*);
    Cube (*moveMany)(Cube, char**);
} MOVER;

Cube simpleMove(Cube cube, char* mv){
    AXIS_MOVES axm = AxisMoves();
    STD_MOVES stdm = STDMoves();
    if(mv=="U")
        return stdm.U(cube);
    else if(mv=="U'")
        return stdm.UPrime(cube);
    else if(mv=="U2")
        return stdm.U2(cube);
    else if(mv=="D")
        return stdm.D(cube);
    else if(mv=="D'")
        return stdm.DPrime(cube);
    else if(mv=="D2")
        return stdm.D2(cube);
    else if(mv=="R")
        return stdm.R(cube);
    else if(mv=="R'")
        return stdm.RPrime(cube);
    else if(mv=="R2")
        return stdm.R2(cube);
    else if(mv=="y")
        return axm.Y(cube);
    else if(mv=="y'")
        return axm.YPrime(cube);
    else if(mv=="y2")
        return axm.Y2(cube);
    else
        return cube;
}

int _count(char** mvs){
    int i = 0;
    while(mvs[i] != NULL)
        i++;
    return i;
}

Cube multiMoves(Cube cube, char** mvs){
    int size = _count(mvs);
    printf("%d", size);
    int i;
    for(i=0;i<size;i++)
        cube = simpleMove(cube, mvs[i]);
    return cube;
}

MOVER Mover(){
    MOVER mover;
    mover.moveOne = simpleMove;
    mover.moveMany = multiMoves;
    return mover;
}
