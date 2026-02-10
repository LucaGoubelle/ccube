//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    Cube cube = getCube(size);
    MOVER mover = Mover();

    printCube(cube);

    char* moves[] = {"R'","y",NULL};

    cube = mover.moveMany(cube, moves);

    printf("\n\n");
    printCube(cube);

    destroyCube(cube);

    printf("End prog...\n");
    return 0;
}
