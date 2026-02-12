//@author: LucaGoubelle 🦊
#pragma once
#include "data/cube.h"

const char* RED = "\033[41m \033[0m";
const char* GREEN = "\033[42m \033[0m";
const char* YELLOW = "\033[43m \033[0m";
const char* BLUE = "\033[44m \033[0m";
const char* MAGENTA = "\033[45m \033[0m";
const char* WHITE = "\033[47m \033[0m";

typedef struct {
    void (*print)(Cube);
} CUBE_PRINTER;

const char* _getColorString(char elem){
    if(elem=='G')
        return GREEN;
    else if(elem=='R')
        return RED;
    else if(elem=='Y')
        return YELLOW;
    else if(elem=='B')
        return BLUE;
    else if(elem=='O')
        return MAGENTA;
    else if(elem=='W')
        return WHITE;
    else
        return " ";
}

void _printRowUpDown(char* row, int size){
    int i, j;
    for(i=0;i<size;i++)
        printf(" ");
    for(j=0;j<size;j++)
        printf(_getColorString(row[j]));
    printf("\n");
}

void _printRowLFRB(int size, char* rowL, char* rowF, char* rowR, char* rowB){
    int i, j, k, l;
    for(i=0;i<size;i++)
        printf(_getColorString(rowL[i]));
    for(j=0;j<size;j++)
        printf(_getColorString(rowF[j]));
    for(k=0;k<size;k++)
        printf(_getColorString(rowR[k]));
    for(l=0;l<size;l++)
        printf(_getColorString(rowB[l]));
    printf("\n");
}

void _printCube(Cube cube){
    int i, j, k;
    for(i=0;i<cube.size;i++)
        _printRowUpDown(cube.up[i], cube.size);
    for(j=0;j<cube.size;j++)
        _printRowLFRB(cube.size, cube.left[j], cube.front[j], cube.right[j], cube.back[j]);
    for(k=0;k<cube.size;k++)
        _printRowUpDown(cube.down[k], cube.size);
    printf("\n");
}

CUBE_PRINTER CubePrinter(){
    CUBE_PRINTER printer;
    printer.print = _printCube;
    return printer;
}
