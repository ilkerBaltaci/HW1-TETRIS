#ifndef TETRO_Z_H
#define TETRO_Z_H

#include "Tetromino.h"
#include <vector>
#include "Coordinate.h"

using namespace std;

class Tetro_Z : public Tetromino {

private:
    RelativePosition currentPosition = RelativePosition::TOP;

    vector<Coordinate> editedCoordinates;

    vector<Coordinate> coordinateTop = {
        Coordinate(0,0," "), 
        Coordinate(0,1,"Z"), 
        Coordinate(1,0,"Z"), 
        Coordinate(1,1,"Z"),
        Coordinate(2,0,"Z"),
        Coordinate(2,1," "),
    };

    vector<Coordinate> coordinateRight = {
        Coordinate(0,0,"Z"), 
        Coordinate(0,1,"Z"), 
        Coordinate(0,2," "), 
        Coordinate(1,0," "),
        Coordinate(1,1,"Z"),
        Coordinate(1,2,"Z"),
    };

    vector<Coordinate> coordinateBottom = coordinateTop;

    vector<Coordinate> coordinateLeft = coordinateRight;

public:
    

    Tetro_Z();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition relativePosition);

    vector<Coordinate> getCoordinates(RelativePosition relativePosition);

    void setEditedCoordinates(vector<Coordinate> editedCoordinates);
    vector<Coordinate> getEditedCoordinates();
};

#endif