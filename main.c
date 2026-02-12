//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    Cube cube = getCube(size);
    MOVER mover = Mover();
    CUBE_PRINTER printer = CubePrinter();

    printCube(cube);
    printf("\n\n");

    SCRAMBLER scrambler = Scrambler();
    cube = scrambler.scrambling(cube);
    // char* moves[] = {"R'","y",NULL};
    // cube = mover.moveMany(cube, moves);

    printCube(cube);

    destroyCube(cube);

    printf("End prog...\n");
    return 0;
}
