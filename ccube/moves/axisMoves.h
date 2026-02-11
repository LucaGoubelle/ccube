//@author: LucaGoubelle 🦊
#pragma once
#include "rotateHelpers.h"
#include "../data/cube.h"

typedef struct {
    Cube (*Y)(Cube);
    Cube (*YPrime)(Cube);
    Cube (*Y2)(Cube);
    Cube (*X)(Cube);
    Cube (*XPrime)(Cube);
    Cube (*X2)(Cube);
    Cube (*Z)(Cube);
    Cube (*ZPrime)(Cube);
    Cube (*Z2)(Cube);
} AXIS_MOVES;

Cube _moveY(Cube cube){
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

Cube _moveYPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = _moveY(cube);
    return cube;
}

Cube _moveY2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = _moveY(cube);
    return cube;
}

Cube _moveX(Cube cube){
    //todo: implement this
    int size = cube.size;
    cube.right = rotate(cube.right, size);
    cube.left=  rotateAsync(cube.left, size);

    char** newFront = copyMatrix(cube.down, size);
    char** newUp = copyMatrix(cube.front, size);
    char** newBack = rotateTwice(copyMatrix(cube.up, size), size);
    char** newDown = rotateTwice(copyMatrix(cube.back, size), size);

    cube.front = transfert(cube.front, newFront, size);
    cube.up = transfert(cube.up, newUp, size);
    cube.back = transfert(cube.back, newBack, size);
    cube.down = transfert(cube.down, newDown, size);

    freeFace(newFront, size);
    freeFace(newUp, size);
    freeFace(newBack, size);
    freeFace(newDown, size);

    return cube;
}

Cube _moveXPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = _moveX(cube);
    return cube;
}

Cube _moveX2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = _moveX(cube);
    return cube;
}

Cube _moveZ(Cube cube){
    int size = cube.size;
    cube.front = rotate(cube.front, size);
    cube.back = rotateAsync(cube.back, size);

    char** newUp = rotate(copyMatrix(cube.left, size), size);
    char** newRight = rotate(copyMatrix(cube.up, size), size);
    char** newLeft = rotate(copyMatrix(cube.down, size), size);
    char** newDown = rotate(copyMatrix(cube.right, size), size);

    cube.up = transfert(cube.up, newUp, size);
    cube.right = transfert(cube.right, newRight, size);
    cube.left = transfert(cube.left, newLeft, size);
    cube.down = transfert(cube.down, newDown, size);

    freeFace(newUp, size);
    freeFace(newRight, size);
    freeFace(newLeft, size);
    freeFace(newDown, size);
    
    return cube;
}

Cube _moveZPrime(Cube cube){
    int i;
    for(i=0;i<3;i++)
        cube = _moveZ(cube);
    return cube;
}

Cube _moveZ2(Cube cube){
    int i;
    for(i=0;i<2;i++)
        cube = _moveZ(cube);
    return cube;
}

AXIS_MOVES AxisMoves(){
    AXIS_MOVES am;
    am.Y = _moveY;
    am.YPrime = _moveYPrime;
    am.Y2 = _moveY2;
    am.X = _moveX;
    am.XPrime = _moveXPrime;
    am.X2 = _moveX2;
    am.Z = _moveZ;
    am.ZPrime = _moveZPrime;
    am.Z2 = _moveZ2;
    return am;
}
