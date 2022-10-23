#ifndef TETRO_Z_H
#define TETRO_Z_H

#include "Tetromino.h"
#include <vector>
#include "Coordinate.h"

using namespace std;

class Tetro_Z : public Tetromino {

public:

    vector<Coordinate> coordinates = {Coordinate(0,1,"Z"), Coordinate(1,1,"Z"), Coordinate(1,0,"Z"), Coordinate(2,0,"Z")};

    Tetro_Z();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);
};

#endif