#ifndef TETRO_S_H
#define TETRO_S_H

#include "Tetromino.h"
#include <vector>
#include "Coordinate.h"

using namespace std;

class Tetro_S : public Tetromino {
private:
    RelativePosition currentPosition = RelativePosition::TOP;

    vector<Coordinate> editedCoordinates;

    vector<Coordinate> coordinateTop = {
        Coordinate(0,0,"S"), 
        Coordinate(0,1," "), 
        Coordinate(1,0,"S"), 
        Coordinate(1,1,"S"),
        Coordinate(2,0," "),
        Coordinate(2,1,"S"),
    };

    vector<Coordinate> coordinateRight = {
        Coordinate(0,0," "), 
        Coordinate(0,1,"S"), 
        Coordinate(0,2,"S"), 
        Coordinate(1,0,"S"),
        Coordinate(1,1,"S"),
        Coordinate(1,2," "),
    };

    vector<Coordinate> coordinateBottom = coordinateTop;

    vector<Coordinate> coordinateLeft = coordinateRight;

public:
    
    Tetro_S();
    int rotate(RotateOptions rotateOption);
    void print() ;
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);

    vector<Coordinate> getCoordinates(RelativePosition relativePosition);

    void setEditedCoordinates(vector<Coordinate> editedCoordinates);
    vector<Coordinate> getEditedCoordinates();
};

#endif