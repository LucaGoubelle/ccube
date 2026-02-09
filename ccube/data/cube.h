//@author: LucaGoubelle 🦊
#pragma once
#include "face.h"

struct Cube {
    int size;
    char** back;
    char** up;
    char** front;
    char** left;
    char** right;
    char** down;
};

struct Cube getCube(int size){
    struct Cube cube;
    cube.size = size;
    cube.back = genFace(size, 'G');
    cube.up = genFace(size, 'Y');
    cube.front = genFace(size, 'B');
    cube.left = genFace(size, 'O');
    cube.right = genFace(size, 'R');
    cube.down = genFace(size, 'W');
    return cube;
}

void destroyCube(struct Cube cube){
    freeFace(cube.back, cube.size);
    freeFace(cube.up, cube.size);
    freeFace(cube.front, cube.size);
    freeFace(cube.left, cube.size);
    freeFace(cube.right, cube.size);
    freeFace(cube.down, cube.size);
}
