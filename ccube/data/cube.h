//@author: LucaGoubelle 🦊
#pragma once
#include "face.h"

typedef struct {
    int size;
    char** back;
    char** up;
    char** front;
    char** left;
    char** right;
    char** down;
} Cube;

Cube getCube(int size){
    Cube cube;
    cube.size = size;
    cube.back = genFace(size, 'G');
    cube.up = genFace(size, 'Y');
    cube.front = genFace(size, 'B');
    cube.left = genFace(size, 'O');
    cube.right = genFace(size, 'R');
    cube.down = genFace(size, 'W');
    return cube;
}

Cube getEmptyCube(int size){
    Cube cube;
    cube.size = size;
    cube.back = genEmptyFace(size);
    cube.up = genEmptyFace(size);
    cube.front = genEmptyFace(size);
    cube.left = genEmptyFace(size);
    cube.right = genEmptyFace(size);
    cube.down = genEmptyFace(size);
    return cube;
}

void destroyCube(Cube cube){
    freeFace(cube.back, cube.size);
    freeFace(cube.up, cube.size);
    freeFace(cube.front, cube.size);
    freeFace(cube.left, cube.size);
    freeFace(cube.right, cube.size);
    freeFace(cube.down, cube.size);
}
