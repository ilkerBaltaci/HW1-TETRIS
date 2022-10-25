#include <iostream>
#include "Tetromino.h"
#include "Tetro_J.h"
#include "TetroOptions.h"
#include "ProgramManager.h"
#include "TetrominoFactory.h"
#include "Tetro_Z.h"
#include "PrintHandler.h"
#include "Util.h"
#include "BestFitObject.h"
#include <algorithm>

using namespace std;

int main() {
    ProgramManager programManager;

    programManager.printStartMenu();

    programManager.askHowManyTetro();

    programManager.askTetroTypes();

    programManager.performBestFitAndPrint();
    
    return 0;
}