#ifndef TETRO_I_H
#define TETRO_I_H

#include "Tetromino.h"

class Tetro_I : Tetromino {
public:
    Tetro_I();
    int rotate(RotateOptions rotateOption) override;
    void print() override;
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition) override;
};

#endif