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
    else
        return cube;
}
