#ifndef TETRO_L_H
#define TETRO_L_H

#include "Tetromino.h"

class Tetro_L : public Tetromino {
public:
    
    Tetro_L();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);
};

#endif