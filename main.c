//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    Cube cube = getCube(size);
    Mover mover = getMover();

    printCube(cube);

    char* moves[] = {
        "U'",
        "R'",
        NULL
    };

    cube = mover.moveMany(cube, moves);

    printf("\n\n");
    printCube(cube);

    destroyCube(cube);

    printf("End prog...\n");
    return 0;
}
