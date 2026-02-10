//@author: LucaGoubelle 🦊
#pragma once
#include "rotateHelpers.h"
#include "../data/cube.h"


struct Cube moveU(struct Cube cube){
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

struct Cube moveUPrime(struct Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = moveU(cube);
    return cube;
}

struct Cube moveU2(struct Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = moveU(cube);
    return cube;
}

struct Cube moveD(struct Cube cube){
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

struct Cube moveDPrime(struct Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = moveD(cube);
    return cube;
}

struct Cube moveD2(struct Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = moveD(cube);
    return cube;
}
