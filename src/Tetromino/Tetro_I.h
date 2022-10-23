#ifndef TETRO_I_H
#define TETRO_I_H

#include "Tetromino.h"

class Tetro_I : public Tetromino {
public:
    Tetro_I();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);
};

#endif