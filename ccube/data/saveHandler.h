//@author: LucaGoubelle 🦊
#pragma once
#include "cube.h"
#include "utils/fileHandler.h"
#include "utils/stringUtils.h"

typedef struct {
    Cube (*load)(const char*, int);
    char* (*dump3x3)(const char*,Cube);
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

Cube _load(const char* filepath, int size){
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

char* _face3x3ToString(char** face){
    int size = 3;
    int nbStickers = size * size;
    int nbDelim = size-1;
    int jump = 1;
    int totalSize = nbStickers + nbDelim + jump;
    char* result = (char*)malloc(sizeof(char)*totalSize + 1);
    result[0] = face[0][0];
    result[1] = face[0][1];
    result[2] = face[0][2];
    result[3] = ';';
    result[4] = face[1][0];
    result[5] = face[1][1];
    result[6] = face[1][2];
    result[7] = ';';
    result[8] = face[2][0];
    result[9] = face[2][1];
    result[10] = face[2][2];
    result[11] = '\n';
    result[12] = '\0';
    return result;
}

char* _dump3x3(const char* filepath, Cube cube){
    int size = cube.size;
    FILE_HANDLER fh = FileHandler();
    STRING_UTILS su = StringUtils();
    char* result = fh.write(filepath, "");
    char* faceBack = _face3x3ToString(cube.back);
    char* faceUp = _face3x3ToString(cube.up);
    char* faceFront = _face3x3ToString(cube.front);
    char* faceLeft = _face3x3ToString(cube.left);
    char* faceRight = _face3x3ToString(cube.right);
    char* faceDown = _face3x3ToString(cube.down);
    result = fh.append(filepath, faceBack);
    result = fh.append(filepath, faceUp);
    result = fh.append(filepath, faceFront);
    result = fh.append(filepath, faceLeft);
    result = fh.append(filepath, faceRight);
    result = fh.append(filepath, faceDown);
    free(faceBack);
    free(faceUp);
    free(faceFront);
    free(faceLeft);
    free(faceRight);
    free(faceDown);
    return result;
}

SAVE_HANDLER SaveHandler(){
    SAVE_HANDLER sh;
    sh.load = _load;
    sh.dump3x3 = _dump3x3;
    return sh;
}
