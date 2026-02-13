//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    CUBE_PRINTER printer = CubePrinter();
    SCRAMBLER scrambler = Scrambler();
    SAVE_HANDLER sh = SaveHandler();

    // Cube cube = getCube(size);
    Cube cube = sh.load3x3("res/cube3x3.dsv", size);
    printer.print(cube);

    destroyCube(cube);
    printf("End prog...\n");
    return 0;
}
