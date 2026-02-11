//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    Cube cube = getCube(size);
    MOVER mover = Mover();
    CUBE_PRINTER printer = CubePrinter();

    printer.print(cube);

    char* moves[] = {"y","x'",NULL};

    cube = mover.moveMany(cube, moves);

    printf("\n\n");
    printer.print(cube);

    destroyCube(cube);

    printf("End prog...\n");
    return 0;
}
