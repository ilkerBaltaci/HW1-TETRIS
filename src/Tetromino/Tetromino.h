#ifndef TETROMINO_H
#define TETROMINO_H

#include "TetroOptions.h"
#include "RotateOptions.h"
#include "RelativePosition.h"

#include <iostream>

class Tetromino
{
private:
    /* data */
public:
    Tetromino(TetroOptions tetroOption);
    ~Tetromino();

    virtual int rotate(RotateOptions rotateOption);
    virtual void print();
    virtual bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);
};

#endif
