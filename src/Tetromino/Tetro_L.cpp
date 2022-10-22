#include "Tetro_L.h"
#include "TetroOptions.h"

#include <iostream>

Tetro_L::Tetro_L() : Tetromino(TetroOptions::L) {
    std::cout << "Tetro_L Constructor has been called!" << std::endl;
};

int Tetro_L::rotate(RotateOptions rotateOption){
    std::cout << "Tetro_L rotate function has been called." << std::endl;
    return 1;
};

void Tetro_L::print() {
    std::cout << "Tetro_L print function has been called." << std::endl;
};

bool Tetro_L::canFit(Tetromino otherTetromino, RelativePosition RelativePosition) {
    return false;
}