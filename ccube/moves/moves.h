//@author: LucaGoubelle 🦊
#pragma once
#include "stdMoves.h"
#include "axisMoves.h"

typedef struct {
    Cube (*moveOne)(Cube, char*);
    Cube (*moveMany)(Cube, char**);
} MOVER;

Cube _handleSTDMoves(Cube cube, char* mv){
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
    else if(mv=="L")
        return stdm.L(cube);
    else if(mv=="L'")
        return stdm.LPrime(cube);
    else if(mv=="L2")
        return stdm.L2(cube);
    else if(mv=="F")
        return stdm.F(cube);
    else if(mv=="F'")
        return stdm.FPrime(cube);
    else if(mv=="F2")
        return stdm.F2(cube);
    else
        return cube;
}

Cube _handleAxisMoves(Cube cube, char* mv){
    AXIS_MOVES axm = AxisMoves();
    if(mv=="y")
        return axm.Y(cube);
    else if(mv=="y'")
        return axm.YPrime(cube);
    else if(mv=="y2")
        return axm.Y2(cube);
    else if(mv=="x")
        return axm.X(cube);
    else if(mv=="x'")
        return axm.XPrime(cube);
    else if(mv=="x2")
        return axm.X2(cube);
    else if(mv=="z")
        return axm.Z(cube);
    else if(mv=="z'")
        return axm.ZPrime(cube);
    else if(mv=="z2")
        return axm.Z2(cube);
    else
        return cube;
}

Cube _simpleMove(Cube cube, char* mv){
    cube = _handleSTDMoves(cube, mv);
    cube = _handleAxisMoves(cube, mv);
    return cube;
}

int _count(char** mvs){
    int i = 0;
    while(mvs[i] != NULL)
        i++;
    return i;
}

Cube _multiMoves(Cube cube, char** mvs){
    int size = _count(mvs);
    int i;
    for(i=0;i<size;i++)
        cube = _simpleMove(cube, mvs[i]);
    return cube;
}

MOVER Mover(){
    MOVER mover;
    mover.moveOne = _simpleMove;
    mover.moveMany = _multiMoves;
    return mover;
}
