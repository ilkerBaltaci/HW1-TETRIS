#include <iostream>
#include "Tetromino.h"
#include "Tetro_J.h"
#include "TetroOptions.h"
#include "ProgramManager.h"
#include "Conversions.h"
#include "TetrominoFactory.h"
#include "Tetro_I.h"
#include "PrintHandler.h"

using namespace std;

int main() {
    ProgramManager programManager;

    programManager.askHowManyTetro();

    programManager.askTetroTypes();

    return 0;
}