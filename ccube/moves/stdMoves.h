//@author: LucaGoubelle 🦊
#pragma once
#include "rotateHelpers.h"
#include "../data/cube.h"


Cube moveU(Cube cube){
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

Cube moveUPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = moveU(cube);
    return cube;
}

Cube moveU2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = moveU(cube);
    return cube;
}

Cube moveD(Cube cube){
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

Cube moveDPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = moveD(cube);
    return cube;
}

Cube moveD2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = moveD(cube);
    return cube;
}

Cube moveR(Cube cube){
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

Cube moveRPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = moveR(cube);
    return cube;
}

Cube moveR2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = moveR(cube);
    return cube;
}
