#include "Tetro_J.h"
#include "TetroOptions.h"

#include <iostream>

Tetro_J::Tetro_J() : Tetromino(TetroOptions::J) {
    std::cout << "Tetro_J Constructor has been called!" << std::endl;
};

int Tetro_J::rotate(RotateOptions rotateOption){
    std::cout << "Tetro_J rotate function has been called." << std::endl;
    return 1;
};

void Tetro_J::print() {
    std::cout << "Tetro_J print function has been called." << std::endl;
};

bool Tetro_J::canFit(Tetromino otherTetromino, RelativePosition RelativePosition) {
    return false;
}