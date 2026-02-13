#pragma once
#include "cube.h"

typedef struct {
    Cube (*load3x3)(char*);
    char* (*dump3x3)(char*,Cube);
} SAVE_HANDLER;

int nbLines = 6;
int nbCol3x3 = 11;

Cube _load3x3(char* filepath){
    //todo: implement this
    return getCube(3);
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
