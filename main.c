//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    CUBE_PRINTER printer = CubePrinter();
    MOVER mover = Mover();
    SAVE_HANDLER sh = SaveHandler();

    // Cube cube = getCube(size);
    Cube cube = sh.load("res/saves/cube3x3.dsv", size);
    printer.print(cube);
    printf("\n\n");

    cube = mover.moveOne(cube, "Uw2");
    printer.print(cube);

    destroyCube(cube);
    printf("End prog...\n");
    return 0;
}
