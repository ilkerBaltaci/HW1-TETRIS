#ifndef TETRO_T_H
#define TETRO_T_H

#include "Tetromino.h"

class Tetro_T : Tetromino {
public:
    
    Tetro_T();
    int rotate(RotateOptions rotateOption) override;
    void print() override;
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition) override;
};

#endif