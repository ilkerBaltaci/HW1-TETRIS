#ifndef TETRO_S_H
#define TETRO_S_H

#include "Tetromino.h"

class Tetro_S : public Tetromino {
public:
    
    Tetro_S();
    int rotate(RotateOptions rotateOption);
    void print() ;
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);
};

#endif