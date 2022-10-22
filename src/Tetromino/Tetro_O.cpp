#include "Tetro_O.h"
#include "TetroOptions.h"

#include <iostream>

Tetro_O::Tetro_O() : Tetromino(TetroOptions::O) {
    std::cout << "Tetro_O Constructor has been called!" << std::endl;
};

int Tetro_O::rotate(RotateOptions rotateOption){
    std::cout << "Tetro_O rotate function has been called." << std::endl;
    return 1;
};

void Tetro_O::print() {
    std::cout << "Tetro_O print function has been called." << std::endl;
};

bool Tetro_O::canFit(Tetromino otherTetromino, RelativePosition RelativePosition) {
    return false;
}