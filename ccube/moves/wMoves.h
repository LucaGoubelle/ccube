//@author: LucaGoubelle 🦊
#pragma once
#include "rotateHelpers.h"
#include "../data/cube.h"

typedef struct {
    Cube (*Uw)(Cube, int);
    Cube (*UwPrime)(Cube, int);
    Cube (*Uw2)(Cube, int);
    Cube (*Dw)(Cube, int);
    Cube (*DwPrime)(Cube, int);
    Cube (*Dw2)(Cube, int);
} WMOVES;

Cube _moveUw(Cube cube, int layers){
    int size = cube.size;
    cube.up = rotate(cube.up, size);

    char** newFront = genEmptyFace(size);
    char** newLeft = genEmptyFace(size);
    char** newRight = genEmptyFace(size);
    char** newBack = genEmptyFace(size);

    int j,i;
    for(j=0;j<layers;j++)
        for(i=0;i<size;i++){
            newFront[j][i] = cube.right[j][i];
            newRight[j][i] = cube.back[j][i];
            newLeft[j][i] = cube.front[j][i];
            newBack[j][i] = cube.left[j][i];
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

Cube _moveUwPrime(Cube cube, int layers){
    int i;
    for(i=0;i<3;i++)
        cube = _moveUw(cube, layers);
    return cube;
}

Cube _moveUw2(Cube cube, int layers){
    int i;
    for(i=0;i<2;i++)
        cube = _moveUw(cube, layers);
    return cube;
}

Cube _moveDw(Cube cube, int layers){
    int size = cube.size;
    cube.down = rotate(cube.down, size);

    char** newFront = genEmptyFace(size);
    char** newLeft = genEmptyFace(size);
    char** newRight = genEmptyFace(size);
    char** newBack = genEmptyFace(size);

    int j,i;
    for(j=0;j<layers;j++)
        for(i=0;i<size;i++){
            newFront[size-1-j][i] = cube.left[size-1-j][i];
            newLeft[size-1-j][i] = cube.back[size-1-j][i];
            newRight[size-1-j][i] = cube.front[size-1-j][i];
            newBack[size-1-j][i] = cube.right[size-1-j][i];
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

Cube _moveDwPrime(Cube cube, int layers){
    int i;
    for(i=0;i<3;i++)
        cube = _moveDw(cube, layers);
    return cube;
}

Cube _moveDw2(Cube cube, int layers){
    int i;
    for(i=0;i<2;i++)
        cube = _moveDw(cube, layers);
    return cube;
}

WMOVES WMoves(){
    WMOVES wm;
    wm.Uw = _moveUw;
    wm.UwPrime = _moveUwPrime;
    wm.Uw2 = _moveUw2;
    wm.Dw = _moveDw;
    wm.DwPrime = _moveDwPrime;
    wm.Dw2 = _moveDw2;
    return wm;
}
