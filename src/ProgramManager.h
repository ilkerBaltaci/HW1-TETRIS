#ifndef PROGRAM_MANAGER_H
#define PROGRAM_MANAGER_H

#include <vector>
#include "Tetromino.h"
#include "Coordinate.h"

using namespace std;

class ProgramManager {
private:
    void setBestPositionOfTetromino(Tetromino *previousTetromino, Tetromino *currentTetromino);
public:
    vector<Coordinate> allTetrominoCoordinates;
    int numOfTetromino;
    vector<Tetromino*> tetrominos;

    ~ProgramManager();

    int askHowManyTetro();
    int askTetroTypes();
    void performBestFitAndPrint();
};

#endif