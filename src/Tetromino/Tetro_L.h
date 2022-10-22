#ifndef TETRO_L_H
#define TETRO_L_H

#include "Tetromino.h"

class Tetro_L : Tetromino {
public:
    
    Tetro_L();
    int rotate(RotateOptions rotateOption) override;
    void print() override;
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition) override;
};

#endif