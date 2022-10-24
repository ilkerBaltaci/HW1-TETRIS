#ifndef TETRO_T_H
#define TETRO_T_H

#include "Tetromino.h"
#include <vector>
#include "Coordinate.h"

using namespace std;

class Tetro_T : public Tetromino {
private:
    RelativePosition currentPosition = RelativePosition::TOP;

    vector<Coordinate> editedCoordinates;

    vector<Coordinate> coordinateTop = {
        Coordinate(0,0," "), 
        Coordinate(0,1,"T"), 
        Coordinate(1,0,"T"), 
        Coordinate(1,1,"T"),
        Coordinate(2,0," "),
        Coordinate(2,1,"T"),
    };

    vector<Coordinate> coordinateRight = {
        Coordinate(0,0," "), 
        Coordinate(0,1,"T"), 
        Coordinate(0,2," "), 
        Coordinate(1,0,"T"),
        Coordinate(1,1,"T"),
        Coordinate(1,2,"T"),
    };

    vector<Coordinate> coordinateBottom = {
        Coordinate(0,0,"T"), 
        Coordinate(0,1," "), 
        Coordinate(1,0,"T"), 
        Coordinate(1,1,"T"),
        Coordinate(2,0,"T"),
        Coordinate(2,1," "),
    };

    vector<Coordinate> coordinateLeft = {
        Coordinate(0,0,"T"), 
        Coordinate(0,1,"T"), 
        Coordinate(0,2,"T"), 
        Coordinate(1,0," "),
        Coordinate(1,1,"T"),
        Coordinate(1,2," "),
    };

public:
    
    Tetro_T();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);

    vector<Coordinate> getCoordinates(RelativePosition relativePosition);

    void setEditedCoordinates(vector<Coordinate> editedCoordinates);
    vector<Coordinate> getEditedCoordinates();
};

#endif