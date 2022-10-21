#include <iostream>
#include "Tetromino.h"
#include "Tetro_J.h"
#include "TetroOptions.h"

using namespace std;

int main() {

    Tetromino* tetromino = (Tetromino*) new Tetro_J(TetroOptions::J);

    delete tetromino;

    cout << "Hello World!" << endl;

    return 0;
}