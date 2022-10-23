#ifndef TETRO_J_H
#define TETRO_J_H

#include "Tetromino.h"
#include "TetroOptions.h"
#include <map>

using namespace std;
class Tetro_J : public Tetromino
{
private:
    map<int, int> coordinateTOP = {{-1,0},{0,0},{1,0},{1,-1}};
    map<int, int> coordinateLEFT = {{0,0},{0,1},{0,-1},{-1,-1}};
    map<int, int> coordinateBOTTOM = {{0,0},{0,1},{0,-1},{-1,-1}};
    map<int, int> coordinateRIGHT = {{0,0},{0,1},{0,-1},{-1,-1}};
public:
    
    Tetro_J();
    int rotate(RotateOptions rotateOption);
    void print();
    bool canFit(Tetromino otherTetromino, RelativePosition RelativePosition);
};

#endif
