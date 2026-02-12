//@author: LucaGoubelle 🦊
#pragma once
#include "rotateHelpers.h"
#include "../data/cube.h"

typedef struct {
    Cube (*U)(Cube);
    Cube (*UPrime)(Cube);
    Cube (*U2)(Cube);
    Cube (*D)(Cube);
    Cube (*DPrime)(Cube);
    Cube (*D2)(Cube);
    Cube (*R)(Cube);
    Cube (*RPrime)(Cube);
    Cube (*R2)(Cube);
    Cube (*L)(Cube);
    Cube (*LPrime)(Cube);
    Cube (*L2)(Cube);
    Cube (*F)(Cube);
    Cube (*FPrime)(Cube);
    Cube (*F2)(Cube);
} STD_MOVES;

Cube _moveU(Cube cube){
    int size = cube.size;
    cube.up = rotate(cube.up, size);

    char** newFront = genEmptyFace(size);
    char** newLeft = genEmptyFace(size);
    char** newRight = genEmptyFace(size);
    char** newBack = genEmptyFace(size);

    int i;
    for(i=0;i<size;i++){
        newFront[0][i] = cube.right[0][i];
        newRight[0][i] = cube.back[0][i];
        newLeft[0][i] = cube.front[0][i];
        newBack[0][i] = cube.left[0][i];
    }

    cube.front = transfert(cube.front, newFront, size);
    cube.left = transfert(cube.left, newLeft, size);
    cube.right = transfert(cube.right, newRight, size);
    cube.back = transfert(cube.back, newBack, size);

    freeFace(newFront, size);
    freeFace(newLeft, size);
    freeFace(newRight, size);
    freeFace(newBack, size);
    
    return cube;
}

Cube _moveUPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = _moveU(cube);
    return cube;
}

Cube _moveU2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = _moveU(cube);
    return cube;
}

Cube _moveD(Cube cube){
    int size = cube.size;
    cube.down = rotate(cube.down, size);

    char** newFront = genEmptyFace(size);
    char** newLeft = genEmptyFace(size);
    char** newRight = genEmptyFace(size);
    char** newBack = genEmptyFace(size);

    int i;
    for(i=0;i<size;i++){
        newFront[size-1][i] = cube.left[size-1][i];
        newLeft[size-1][i] = cube.back[size-1][i];
        newRight[size-1][i] = cube.front[size-1][i];
        newBack[size-1][i] = cube.right[size-1][i];
    }

    cube.front = transfert(cube.front, newFront, size);
    cube.left = transfert(cube.left, newLeft, size);
    cube.right = transfert(cube.right, newRight, size);
    cube.back = transfert(cube.back, newBack, size);

    freeFace(newFront, size);
    freeFace(newLeft, size);
    freeFace(newRight, size);
    freeFace(newBack, size);
    
    return cube;
}

Cube _moveDPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = _moveD(cube);
    return cube;
}

Cube _moveD2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = _moveD(cube);
    return cube;
}

Cube _moveR(Cube cube){
    int size = cube.size;
    cube.right = rotate(cube.right, size);

    char** newFront = genEmptyFace(size);
    char** newUp = genEmptyFace(size);
    char** newBack = genEmptyFace(size);
    char** newDown = genEmptyFace(size);
    
    int i;
    for(i=0;i<size;i++){
        newFront[i][size-1] = cube.down[i][size-1];
        newUp[i][size-1] = cube.front[i][size-1];
        newBack[i][size-1] = cube.up[i][size-1];
        newDown[i][0] = cube.back[i][0];
    }

    cube.front = transfert(cube.front, newFront, size);
    cube.up = transfert(cube.up, newUp, size);
    cube.back = transfert(cube.back, rotateTwice(newBack, size), size);
    cube.down = transfert(cube.down, rotateTwice(newDown, size), size);

    freeFace(newFront, size);
    freeFace(newUp, size);
    freeFace(newBack, size);
    freeFace(newDown, size);

    return cube;
}

Cube _moveRPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = _moveR(cube);
    return cube;
}

Cube _moveR2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = _moveR(cube);
    return cube;
}

Cube _moveL(Cube cube){
    int size = cube.size;
    cube.left = rotate(cube.left, size);

    char** newUp = genEmptyFace(size);
    char** newFront = genEmptyFace(size);
    char** newDown = genEmptyFace(size);
    char** newBack = genEmptyFace(size);

    int i;
    for(i=0;i<size;i++){
        newFront[i][0] = cube.up[i][0];
        newDown[i][0] = cube.front[i][0];
        newBack[i][0] = cube.down[i][0];
        newUp[i][size-1] = cube.back[i][size-1];
    }

    cube.front = transfert(cube.front, newFront, size);
    cube.up = transfert(cube.up, rotateTwice(newUp, size), size);
    cube.down = transfert(cube.down, newDown, size);
    cube.back = transfert(cube.back, rotateTwice(newBack, size), size);

    freeFace(newUp, size);
    freeFace(newFront, size);
    freeFace(newDown, size);
    freeFace(newBack, size);
    
    return cube;
}

Cube _moveLPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = _moveL(cube);
    return cube;
}

Cube _moveL2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = _moveL(cube);
    return cube;
}

Cube _moveF(Cube cube){
    int size = cube.size;
    cube.front = rotate(cube.front, size);

    char** newUp = genEmptyFace(size);
    char** newLeft = genEmptyFace(size);
    char** newRight = genEmptyFace(size);
    char** newDown = genEmptyFace(size);

    int i;
    for(i=0;i<size;i++){
        newUp[i][size-1] = cube.left[i][size-1];
        newLeft[0][i] = cube.down[0][i];
        newRight[size-1][i] = cube.up[size-1][i];
        newDown[i][0] = cube.right[i][0];
    }

    cube.up = transfert(cube.up, rotate(newUp, size), size);
    cube.left = transfert(cube.left, rotate(newLeft, size), size);
    cube.right = transfert(cube.right, rotate(newRight, size), size);
    cube.down = transfert(cube.down, rotate(newDown, size), size);

    freeFace(newUp, size);
    freeFace(newLeft, size);
    freeFace(newRight, size);
    freeFace(newDown, size);

    return cube;
}

Cube _moveFPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = _moveF(cube);
    return cube;
}

Cube _moveF2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = _moveF(cube);
    return cube;
}

STD_MOVES STDMoves(){
    STD_MOVES stdMoves;

    stdMoves.U = _moveU;
    stdMoves.UPrime = _moveUPrime;
    stdMoves.U2 = _moveU2;
    stdMoves.D = _moveD;
    stdMoves.DPrime = _moveDPrime;
    stdMoves.D2 = _moveD2;
    stdMoves.R = _moveR;
    stdMoves.RPrime = _moveRPrime;
    stdMoves.R2 = _moveR2;
    stdMoves.L = _moveL;
    stdMoves.LPrime = _moveLPrime;
    stdMoves.L2 = _moveL2;
    stdMoves.F = _moveF;
    stdMoves.FPrime = _moveFPrime;
    stdMoves.F2 = _moveF2;
    
    return stdMoves;
}
