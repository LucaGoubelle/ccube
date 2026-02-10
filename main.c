//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    Cube cube = getCube(size);

    printCube(cube);

    char* moves[] = {
        "U'",
        "D'",
        "U",
        NULL
    };

    cube = multiMoves(cube, moves);

    printf("\n\n");
    printCube(cube);

    destroyCube(cube);

    printf("End prog...\n");
    return 0;
}
