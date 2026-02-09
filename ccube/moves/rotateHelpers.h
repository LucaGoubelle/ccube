//@author: LucaGoubelle 🦊
#pragma once
#include "../data/face.h"


char** rotate(char** face, int size){
    char** newFace = genEmptyFace(size);
    int i, j;
    for(i=0;i<size;i++){
        int cnt = size-1;
        for(j=0;j<size;j++){
            newFace[i][j] = face[cnt][i];
            cnt--;
        }
    }
    return newFace;
}

char** rotateAsync(char** face, int size){
    int i;
    for(i=0;i<3;i++)
        face = rotate(face, size);
    return face;
}

char** rotateTwice(char** face, int size){
    int i;
    for(i=0;i<2;i++)
        face = rotate(face, size);
    return face;
}

char** transfert(char** face, char** newFace, int size){
    int i, j;
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            face[i][j] = (newFace[i][j]!=' ') ? newFace[i][j] : face[i][j];
    return face;
}
