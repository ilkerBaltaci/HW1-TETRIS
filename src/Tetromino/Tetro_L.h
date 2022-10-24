#ifndef TETRO_L_H
#define TETRO_L_H

#include "Tetromino.h"
#include <vector>
#include "Coordinate.h"

using namespace std;

class Tetro_L : public Tetromino {
private:
    RelativePosition currentPosition = RelativePosition::TOP;

    vector<Coordinate> editedCoordinates;

    vector<Coordinate> coordinateTop = {
        Coordinate(0,0,"L"), 
        Coordinate(0,1,"L"), 
        Coordinate(0,2,"L"), 
        Coordinate(1,0,"L"),
        Coordinate(1,1," "),
        Coordinate(1,2," "),
    };

    vector<Coordinate> coordinateRight = {
        Coordinate(0,0,"L"), 
        Coordinate(0,1,"L"), 
        Coordinate(1,0," "), 
        Coordinate(1,1,"L"),
        Coordinate(2,0," "),
        Coordinate(2,1,"L"),
    };

    vector<Coordinate> coordinateBottom = {
        Coordinate(0,0," "), 
        Coordinate(0,1," "), 
        Coordinate(0,2,"L"), 
        Coordinate(1,0,"L"),
        Coordinate(1,1,"L"),
        Coordinate(1,2,"L"),
    };

    vector<Coordinate> coordinateLeft = {
        Coordinate(0,0,"L"), 
        Coordinate(0,1," "), 
        Coordinate(1,0,"L"), 
        Coordinate(1,1," "),
        Coordinate(2,0,"L"),
        Coordinate(2,1,"L"),
    };

public:
    
    Tetro_L();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);

    vector<Coordinate> getCoordinates(RelativePosition relativePosition);

    void setEditedCoordinates(vector<Coordinate> editedCoordinates);
    vector<Coordinate> getEditedCoordinates();
};

#endif