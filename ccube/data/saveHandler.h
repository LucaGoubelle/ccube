#pragma once
#include "cube.h"
#include <stdbool.h>

typedef struct {
    Cube (*load3x3)(char*);
    char* (*dump3x3)(char*,Cube);
} SAVE_HANDLER;

int nbLines = 6;
int nbCol3x3 = 12;

Cube _load3x3(char* filepath){
    Cube cube = getEmptyCube(3);
    FILE* f = fopen(filepath, "r");
    
    char ligne[nbCol3x3];
    int i = 1;
    while(fgets(ligne, sizeof(ligne), f) != NULL){
        printf(ligne);
        //todo: find a solution to prevent incrementing twice
        printf("%d", i);
        i++;
    }
    fclose(f);
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
