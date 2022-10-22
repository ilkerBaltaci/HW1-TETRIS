#include "Tetro_I.h"
#include "TetroOptions.h"

#include <iostream>

Tetro_I::Tetro_I() : Tetromino(TetroOptions::I) {
    std::cout << "Tetro_I Constructor has been called!" << std::endl;
};

int Tetro_I::rotate(RotateOptions rotateOption){
    std::cout << "Tetro_I rotate function has been called." << std::endl;
    return 1;
};

void Tetro_I::print() {
    std::cout << "Tetro_I print function has been called." << std::endl;
};

bool Tetro_I::canFit(Tetromino otherTetromino, RelativePosition RelativePosition) {
    return false;
}