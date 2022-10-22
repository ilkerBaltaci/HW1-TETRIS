#include "Tetro_T.h"
#include "TetroOptions.h"

#include <iostream>

Tetro_T::Tetro_T() : Tetromino(TetroOptions::T) {
    std::cout << "Tetro_T Constructor has been called!" << std::endl;
};

int Tetro_T::rotate(RotateOptions rotateOption){
    std::cout << "Tetro_T rotate function has been called." << std::endl;
    return 1;
};

void Tetro_T::print() {
    std::cout << "Tetro_T print function has been called." << std::endl;
};

bool Tetro_T::canFit(Tetromino otherTetromino, RelativePosition RelativePosition) {
    return false;
}