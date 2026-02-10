//@author: LucaGoubelle 🦊
#pragma once
#include "rotateHelpers.h"
#include "../data/cube.h"

typedef struct {
    Cube (*Y)(Cube);
    Cube (*YPrime)(Cube);
    Cube (*Y2)(Cube);
} AXIS_MOVES;

Cube moveY(Cube cube){
    int size = cube.size;
    cube.up = rotate(cube.up, size);
    cube.down = rotateAsync(cube.down, size);

    char** newFront = copyMatrix(cube.right, size);
    char** newBack = copyMatrix(cube.left, size);
    char** newRight = copyMatrix(cube.back, size);
    char** newLeft = copyMatrix(cube.front, size);

    cube.front = transfert(cube.front, newFront, size);
    cube.right = transfert(cube.right, newRight, size);
    cube.back = transfert(cube.back, newBack, size);
    cube.left = transfert(cube.left, newLeft, size);

    freeFace(newFront, size);
    freeFace(newBack, size);
    freeFace(newRight, size);
    freeFace(newLeft, size);

    return cube;
}

Cube moveYPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = moveY(cube);
    return cube;
}

Cube moveY2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = moveY(cube);
    return cube;
}

AXIS_MOVES AxisMoves(){
    AXIS_MOVES am;
    am.Y = moveY;
    am.YPrime = moveYPrime;
    am.Y2 = moveY2;
    return am;
}
