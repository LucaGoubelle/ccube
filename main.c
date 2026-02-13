//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    Cube cube = getCube(size);
    CUBE_PRINTER printer = CubePrinter();
    SCRAMBLER scrambler = Scrambler();

    printer.print(cube);
    printf("\n\n");

    cube = scrambler.scrambling(cube);
    printer.print(cube);

    destroyCube(cube);

    printf("End prog...\n");
    return 0;
}
