//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    Cube cube = getCube(size);

    printCube(cube);

    char* moves[] = {
        "U'",
        "R'",
        NULL
    };

    cube = multiMoves(cube, moves);

    // cube = simpleMove(cube, "R");

    printf("\n\n");
    printCube(cube);

    destroyCube(cube);

    printf("End prog...\n");
    return 0;
}
