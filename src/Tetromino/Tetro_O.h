#ifndef TETRO_O_H
#define TETRO_O_H

#include "Tetromino.h"
#include <vector>
#include "Coordinate.h"

using namespace std;
class Tetro_O : public Tetromino {
private:
    RelativePosition currentPosition = RelativePosition::TOP;

    vector<Coordinate> editedCoordinates;

    vector<Coordinate> coordinateTop = {
        Coordinate(0,0,"O"), 
        Coordinate(0,1,"O"), 
        Coordinate(1,0,"O"), 
        Coordinate(1,1,"O"),
    };

    vector<Coordinate> coordinateRight = coordinateTop;

    vector<Coordinate> coordinateBottom = coordinateTop;

    vector<Coordinate> coordinateLeft = coordinateTop;

public:
    
    Tetro_O();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);

    bool setBestPosition(Tetromino *previousTetromino);

    vector<Coordinate> getCoordinates(RelativePosition relativePosition);

    void setEditedCoordinates(vector<Coordinate> editedCoordinates);
    vector<Coordinate> getEditedCoordinates();
};

#endif