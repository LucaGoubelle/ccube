//@author: LucaGoubelle 🦊
#include "ccube/ccube.h"

int main(int argc, char** argv){
    printf("Begin prog...\n");

    int size = 3;
    CUBE_PRINTER printer = CubePrinter();
    SCRAMBLER scrambler = Scrambler();
    SAVE_HANDLER sh = SaveHandler();

    // Cube cube = getCube(size);
    Cube cube = sh.load3x3("res/saves/cube3x3.dsv", size);
    printer.print(cube);
    // int i,j;
    // for(i=0;i<size;i++){
    //     for(j=0;j<size;j++)
    //         printf("%c", cube.back[i][j]);
    //     printf("\n");
    // }

    char* result = sh.dump3x3("res/test.dsv",cube);
    printf(result);
    free(result);

    destroyCube(cube);
    printf("End prog...\n");
    return 0;
}
