#ifndef TETROMINO_H
#define TETROMINO_H

#include "TetroOptions.h"
#include "RotateOptions.h"
#include "RelativePosition.h"
#include <vector>
#include "Coordinate.h"

#include <iostream>

class Tetromino
{
private:
    /* data */
public:
    TetroOptions tetroOption;
    Tetromino(TetroOptions tetroOption);
    ~Tetromino();

    virtual int rotate(RotateOptions rotateOption){return 0;};
    virtual void print(){};
    virtual bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition){return false;};
    virtual bool setBestPosition(Tetromino *previousTetromino){return false;};

    virtual vector<Coordinate> getCoordinates(RelativePosition relativePosition){return vector<Coordinate>();};

    virtual void setEditedCoordinates(vector<Coordinate> editedCoordinates){};
    virtual vector<Coordinate> getEditedCoordinates(){return vector<Coordinate>();};
};

#endif
