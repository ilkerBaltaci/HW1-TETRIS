#include "Tetro_S.h"
#include "TetroOptions.h"

#include <iostream>

Tetro_S::Tetro_S() : Tetromino(TetroOptions::S) {
    std::cout << "Tetro_S Constructor has been called!" << std::endl;
};

int Tetro_S::rotate(RotateOptions rotateOption){
    std::cout << "Tetro_S rotate function has been called." << std::endl;
    return 1;
};

void Tetro_S::print() {
    std::cout << "Tetro_S print function has been called." << std::endl;
};

bool Tetro_S::canFit(Tetromino otherTetromino, RelativePosition RelativePosition) {
    return false;
}