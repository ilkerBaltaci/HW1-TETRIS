#include "Tetro_L.h"
#include "TetroOptions.h"

#include <iostream>
#include "PrintHandler.h"

using namespace std;

Tetro_L::Tetro_L() : Tetromino(TetroOptions::L) {
    //std::cout << "Tetro_L Constructor has been called!" << std::endl;
};

int Tetro_L::rotate(RotateOptions rotateOption){
    if(rotateOption == RotateOptions::LEFT){
        this->currentPosition  = static_cast<RelativePosition>((static_cast<int>(this->currentPosition) + 1) % 4);
    } else {
        this->currentPosition  = static_cast<RelativePosition>((static_cast<int>(this->currentPosition) - 1) % 4);
    }

    return 0;
};

void Tetro_L::print() {
    vector<Coordinate> currentCoordinates = this->getCoordinates(this->currentPosition);

    string currenStrObject = PrintHandler::convertCoordinatesToStringBuf(currentCoordinates);
    cout << currenStrObject << endl;

    //std::cout << "Tetro_L print function has been called." << std::endl;
};

bool Tetro_L::canFit(Tetromino otherTetromino, RelativePosition RelativePosition) {
    return false;
}

vector<Coordinate> Tetro_L::getCoordinates(RelativePosition relativePosition){
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

void Tetro_L::setEditedCoordinates(vector<Coordinate> editedCoordinates){
    this->editedCoordinates = editedCoordinates;
}

vector<Coordinate> Tetro_L::getEditedCoordinates() {
    return this->editedCoordinates;
}