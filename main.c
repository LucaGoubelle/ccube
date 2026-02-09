//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    struct Cube cube = getCube(size);

    printCube(cube);

    cube = simpleMove(cube, "U2");

    printf("\n\n");
    printCube(cube);

    destroyCube(cube);

    printf("End prog...\n");
    return 0;
}
