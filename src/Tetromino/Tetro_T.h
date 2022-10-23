#ifndef TETRO_T_H
#define TETRO_T_H

#include "Tetromino.h"

class Tetro_T : public Tetromino {
public:
    
    Tetro_T();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);
};

#endif