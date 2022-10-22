#include "Tetro_Z.h"
#include "TetroOptions.h"

#include <iostream>

Tetro_Z::Tetro_Z() : Tetromino(TetroOptions::Z) {
    std::cout << "Tetro_Z Constructor has been called!" << std::endl;
};

int Tetro_Z::rotate(RotateOptions rotateOption){
    std::cout << "Tetro_Z rotate function has been called." << std::endl;
    return 1;
};

void Tetro_Z::print() {
    std::cout << "Tetro_Z print function has been called." << std::endl;
};

bool Tetro_Z::canFit(Tetromino otherTetromino, RelativePosition RelativePosition) {
    return false;
}