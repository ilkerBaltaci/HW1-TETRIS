#ifndef TETRO_Z_H
#define TETRO_Z_H

#include "Tetromino.h"

class Tetro_Z : Tetromino {

public:    
    Tetro_Z();
    int rotate(RotateOptions rotateOption) override;
    void print() override;
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition) override;
};

#endif