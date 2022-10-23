#ifndef TETRO_O_H
#define TETRO_O_H

#include "Tetromino.h"

class Tetro_O : public Tetromino {

public:
    
    Tetro_O();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);
};

#endif