#include <iostream>
#include "Tetromino.h"
#include "Tetro_J.h"
#include "TetroOptions.h"
#include "ProgramManager.h"
#include "TetrominoFactory.h"
#include "Tetro_Z.h"
#include "PrintHandler.h"
#include "Util.h"

using namespace std;

int main() {
    //ProgramManager programManager;

    //programManager.askHowManyTetro();

    //programManager.askTetroTypes();

    Tetro_Z tetro_Z;
    vector<Coordinate> coor1 = tetro_Z.getCoordinates(RelativePosition::TOP);
    vector<Coordinate> coor2 = tetro_Z.getCoordinates(RelativePosition::LEFT);

    bool result = Util::checkIntersection(coor1, coor2);
    cout << "Result :" << result << endl;
    
    Util::shiftRight(coor2);
    result = Util::checkIntersection(coor1, coor2);
    cout << "Result :" << result << endl;

    Util::shiftRight(coor2);
    result = Util::checkIntersection(coor1, coor2);
    cout << "Result :" << result << endl;

    Util::shiftRight(coor2);
    result = Util::checkIntersection(coor1, coor2);
    cout << "Result :" << result << endl;

    int bestFitScore = Util::bestFitScore(coor1, coor2);

    cout << "Best fit score: " << bestFitScore << endl;
    vector<Coordinate> concanateObjects = Util::concanateTwoBestFitObject(coor1, coor2);
    string buffer = PrintHandler::convertCoordinatesToStringBuf(concanateObjects);

    cout << buffer << endl;
    return 0;
}