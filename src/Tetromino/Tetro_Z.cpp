#include "Tetro_Z.h"
#include "TetroOptions.h"

#include <iostream>
#include <cstdio>
#include "PrintHandler.h"

Tetro_Z::Tetro_Z() : Tetromino(TetroOptions::Z) {
    std::cout << "Tetro_Z Constructor has been called!" << std::endl;
};

int Tetro_Z::rotate(RotateOptions rotateOption){
    std::cout << "Tetro_Z rotate function has been called." << std::endl;
    return 1;
};

void Tetro_Z::print() {
    vector<Coordinate> currentCoordinates = this->getCoordinates(this->currentPosition);

    PrintHandler::printCoordinates(currentCoordinates);

    std::cout << "Tetro_Z print function has been called." << std::endl;
};

bool Tetro_Z::canFit(Tetromino otherTetromino, RelativePosition relativePosition) {
    return false;
}

vector<Coordinate> Tetro_Z::getCoordinates(RelativePosition relativePosition){
    if(relativePosition == RelativePosition::TOP){
        return this->coordinateTop;
    }
    else if(relativePosition == RelativePosition::RIGHT){
        return this->coordinateRight;
    }
    else if(relativePosition == RelativePosition::LEFT){
        return this->coordinateLeft;
    }
    else if(relativePosition == RelativePosition::BOTTOM){
        return this->coordinateBottom;
    }
    else {
        return this->coordinateTop;
    }
}

void Tetro_Z::setEditedCoordinates(vector<Coordinate> editedCoordinates){
    this->editedCoordinates = editedCoordinates;
}

vector<Coordinate> Tetro_Z::getEditedCoordinates() {
    return this->editedCoordinates;
}