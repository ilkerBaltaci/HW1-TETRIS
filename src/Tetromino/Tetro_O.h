#ifndef TETRO_O_H
#define TETRO_O_H

#include "Tetromino.h"

class Tetro_O : Tetromino {

public:
    
    Tetro_O();
    int rotate(RotateOptions rotateOption) override;
    void print() override;
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition) override;
};

#endif