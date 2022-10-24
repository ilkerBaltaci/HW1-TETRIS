#include "Tetro_Z.h"
#include "TetroOptions.h"

#include <iostream>
#include "PrintHandler.h"

using namespace std;

Tetro_Z::Tetro_Z() : Tetromino(TetroOptions::Z) {
    //std::cout << "Tetro_Z Constructor has been called!" << std::endl;
};

int Tetro_Z::rotate(RotateOptions rotateOption){
    if(rotateOption == RotateOptions::LEFT){
        this->currentPosition  = static_cast<RelativePosition>((static_cast<int>(this->currentPosition) + 1) % 4);
    } else {
        this->currentPosition  = static_cast<RelativePosition>((static_cast<int>(this->currentPosition) - 1) % 4);
    }

    return 0;
};

void Tetro_Z::print() {
    vector<Coordinate> currentCoordinates = this->getCoordinates(this->currentPosition);

    string currenStrObject = PrintHandler::convertCoordinatesToStringBuf(currentCoordinates);
    cout << currenStrObject << endl;

    //std::cout << "Tetro_Z print function has been called." << std::endl;
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