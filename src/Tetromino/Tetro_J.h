#ifndef TETRO_J_H
#define TETRO_J_H

#include "Tetromino.h"
#include "TetroOptions.h"

class Tetro_J : Tetromino
{
private:
public:
    Tetro_J();
    int rotate(RotateOptions rotateOption) override;
    void print() override;
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition) override;
};

#endif
