//@author: LucaGoubelle 🦊
#pragma once
#include <stdio.h>
#include <stdlib.h>

char** _initFace(int row, int col){
    char** face = (char**)malloc(sizeof(char *) * row);
    if (!face) return NULL;
    for (int i = 0; i < row; i++) {
        face[i] = (char*)malloc(col * sizeof(char));
        if (!face[i]) {
            // nettoyage en cas d'erreur
            for (int j = 0; j < i; j++)
                free(face[j]);
            free(face);
            return NULL;
        }
    }
    return face;
}

char** _fillFace(char** face, int row, int col, char elem){
    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++) 
            face[i][j] = elem;
    return face;
}


char** genFace(int size, char elem){
    int row = size;
    int col = size;
    char** face = _initFace(row, col);
    face = _fillFace(face, row, col, elem);
    return face;
}

char** genEmptyFace(int size){
    int row = size;
    int col = size;
    char** face = _initFace(row, col);
    face = _fillFace(face, row, col, ' ');
    return face;
}

void printFace(char** face, int row, int col){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) 
            printf("%c ", face[i][j]);
        printf("\n");
    }
}

void freeFace(char** face, int row){
    for (int i = 0; i < row; i++)
        free(face[i]);
    free(face);
}
