#ifndef PROGRAM_MANAGER_H
#define PROGRAM_MANAGER_H

#include <vector>
#include "Tetromino.h"

using namespace std;

class ProgramManager {
public:
    int numOfTetromino;
    vector<Tetromino*> tetrominos;
    ~ProgramManager();
    int askHowManyTetro();
    int askTetroTypes();
};

#endif