#ifndef TETRO_J_H
#define TETRO_J_H

#include "Tetromino.h"
#include <vector>
#include "Coordinate.h"

using namespace std;
class Tetro_J : public Tetromino
{
private:
    RelativePosition currentPosition = RelativePosition::TOP;

    vector<Coordinate> editedCoordinates;

    vector<Coordinate> coordinateTop = {
        Coordinate(0,0,"J"), 
        Coordinate(0,1," "), 
        Coordinate(0,2," "), 
        Coordinate(1,0,"J"),
        Coordinate(1,1,"J"),
        Coordinate(1,2,"J"),
    };

    vector<Coordinate> coordinateRight = {
        Coordinate(0,0,"J"), 
        Coordinate(0,1,"J"), 
        Coordinate(1,0,"J"), 
        Coordinate(1,1," "),
        Coordinate(2,0,"J"),
        Coordinate(2,1," "),
    };

    vector<Coordinate> coordinateBottom = {
        Coordinate(0,0,"J"), 
        Coordinate(0,1,"J"), 
        Coordinate(0,2,"J"), 
        Coordinate(1,0," "),
        Coordinate(1,1," "),
        Coordinate(1,2,"J"),
    };

    vector<Coordinate> coordinateLeft = {
        Coordinate(0,0," "), 
        Coordinate(0,1,"J"), 
        Coordinate(1,0," "), 
        Coordinate(1,1,"J"),
        Coordinate(2,0,"J"),
        Coordinate(2,1,"J"),
    };
public:
    
    Tetro_J();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);

    vector<Coordinate> getCoordinates(RelativePosition relativePosition);

    void setEditedCoordinates(vector<Coordinate> editedCoordinates);
    vector<Coordinate> getEditedCoordinates();
};

#endif
