#ifndef TETROMINO_FACTORY_H
#define TETROMINO_FACTORY_H

#include <string>
#include "Tetromino.h"

using namespace std;

class TetrominoFactory {
public:
    static Tetromino* factory(string tetrominoType);
};

#endif