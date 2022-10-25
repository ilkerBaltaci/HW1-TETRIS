#ifndef TETRO_I_H
#define TETRO_I_H

#include "Tetromino.h"
#include <vector>
#include "Coordinate.h"

using namespace std;
class Tetro_I : public Tetromino {
private:
    RelativePosition currentPosition = RelativePosition::TOP;

    vector<Coordinate> editedCoordinates;

    vector<Coordinate> coordinateTop = {
        Coordinate(0,0,"I"), 
        Coordinate(1,0,"I"), 
        Coordinate(2,0,"I"), 
        Coordinate(3,0,"I"),
    };

    vector<Coordinate> coordinateRight = {
        Coordinate(0,0,"I"), 
        Coordinate(0,1,"I"), 
        Coordinate(0,2,"I"), 
        Coordinate(0,3,"I"),
    };

    vector<Coordinate> coordinateBottom = coordinateTop;

    vector<Coordinate> coordinateLeft = coordinateRight;
public:
    Tetro_I();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);

    bool setBestPosition(Tetromino *previousTetromino);
    
    vector<Coordinate> getCoordinates(RelativePosition relativePosition);

    void setEditedCoordinates(vector<Coordinate> editedCoordinates);
    vector<Coordinate> getEditedCoordinates();
};

#endif