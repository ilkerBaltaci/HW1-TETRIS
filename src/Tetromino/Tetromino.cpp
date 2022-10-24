#include "Tetromino.h"

Tetromino::Tetromino(TetroOptions tetroOption)
{
    this->tetroOption = tetroOption;
    //std::cout << "Tetromino Constructora girdi." << std::endl;
}

Tetromino::~Tetromino()
{
    //delete &this->tetroOption;
    //std::cout << "Tetromino Destructora girdi." << std::endl;
}