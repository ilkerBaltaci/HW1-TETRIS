#ifndef TETRO_S_H
#define TETRO_S_H

#include "Tetromino.h"

class Tetro_S : Tetromino {
public:
    
    Tetro_S();
    int rotate(RotateOptions rotateOption) override;
    void print() override;
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition) override;
};

#endif