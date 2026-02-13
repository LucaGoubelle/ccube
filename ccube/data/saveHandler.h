//@author: LucaGoubelle 🦊
#pragma once
#include "cube.h"
#include "utils/fileHandler.h"
#include "utils/stringUtils.h"

typedef struct {
    Cube (*load3x3)(char*, int);
    char* (*dump3x3)(char*,Cube);
} SAVE_HANDLER;

char** _setFace(char** face, char* line, int size){
    int count;
    STRING_UTILS su = StringUtils();
    char** caracs = su.split(line, ";", &count);
    int i,j;
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            face[i][j] = caracs[i][j];
    su.freeSplit(caracs, count);
    return face;
}

Cube _load3x3(char* filepath, int size){
    Cube cube = getEmptyCube(size);
    FILE_HANDLER fh = FileHandler();
    STRING_UTILS su = StringUtils();
    char* result = fh.read(filepath);
    int count;
    char** lines = su.split(result, "\n", &count);
    // set faces
    cube.back = _setFace(cube.back, lines[0], size);
    cube.up = _setFace(cube.up, lines[1], size);
    cube.front = _setFace(cube.front, lines[2], size);
    cube.left = _setFace(cube.left, lines[3], size);
    cube.right = _setFace(cube.right, lines[4], size);
    cube.down = _setFace(cube.down, lines[5], size);
    //free memory
    su.freeSplit(lines, count);
    free(result);
    return cube;
}

char* _dump3x3(char* filepath, Cube cube){
    //todo: implement this
    return "???";
}

SAVE_HANDLER SaveHandler(){
    SAVE_HANDLER sh;
    sh.load3x3 = _load3x3;
    sh.dump3x3 = _dump3x3;
    return sh;
}
