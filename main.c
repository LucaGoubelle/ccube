//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    CUBE_PRINTER printer = CubePrinter();
    SCRAMBLER scrambler = Scrambler();

    Cube cube = getCube(size);
    printer.print(cube);

    destroyCube(cube);
    printf("End prog...\n");
    return 0;
}
