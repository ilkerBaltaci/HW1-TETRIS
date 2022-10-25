#include "Tetro_T.h"
#include "TetroOptions.h"

#include <iostream>
#include "PrintHandler.h"
#include "Util.h"
#include "BestFitObject.h"
#include <algorithm>

Tetro_T::Tetro_T() : Tetromino(TetroOptions::T) {
    //std::cout << "Tetro_T Constructor has been called!" << std::endl;
    setEditedCoordinates(getCoordinates(this->currentPosition));
};

int Tetro_T::rotate(RotateOptions rotateOption){
    if(rotateOption == RotateOptions::LEFT){
        this->currentPosition  = static_cast<RelativePosition>((static_cast<int>(this->currentPosition) + 1) % 4);
    } else {
        this->currentPosition  = static_cast<RelativePosition>((static_cast<int>(this->currentPosition) - 1) % 4);
    }

    return 0;
};

void Tetro_T::print() {
    vector<Coordinate> currentCoordinates = this->getCoordinates(this->currentPosition);

    string currenStrObject = PrintHandler::convertCoordinatesToStringBuf(currentCoordinates);
    cout << currenStrObject << endl;

    //std::cout << "Tetro_T print function has been called." << std::endl;
};

bool Tetro_T::canFit(Tetromino otherTetromino, RelativePosition RelativePosition) {
    return false;
}

bool Tetro_T::setBestPosition(Tetromino *previousTetromino){
    if(previousTetromino == nullptr) {
        this->currentPosition = RelativePosition::LEFT;
        setEditedCoordinates(getCoordinates(this->currentPosition));
        return true;
    }

    vector<Coordinate> currentCoordinatesPosTop = getCoordinates(RelativePosition::TOP);
    vector<Coordinate> currentCoordinatesPosLeft = getCoordinates(RelativePosition::LEFT);
    vector<Coordinate> currentCoordinatesPosRight = getCoordinates(RelativePosition::RIGHT);
    vector<Coordinate> currentCoordinatesPosBottom = getCoordinates(RelativePosition::BOTTOM);

    vector<Coordinate> otherTetrominoCoordinates = previousTetromino->getEditedCoordinates();
    vector<BestFitObject> fittingObjects;

    int bestFitScoreTop = 0;
    int bestFitScoreLeft = 0;
    int bestFitScoreRight = 0;
    int bestFitScoreBottom = 0;

    while(Util::checkIntersection(otherTetrominoCoordinates, currentCoordinatesPosTop)){
        Util::shiftRight(currentCoordinatesPosTop);
    }
    bestFitScoreTop = Util::bestFitScore(otherTetrominoCoordinates, currentCoordinatesPosTop);
    BestFitObject fitObjectTop(bestFitScoreTop, RelativePosition::TOP, currentCoordinatesPosTop);
    fittingObjects.push_back(fitObjectTop);

    while(Util::checkIntersection(otherTetrominoCoordinates, currentCoordinatesPosLeft)){
        Util::shiftRight(currentCoordinatesPosLeft);
    }
    bestFitScoreLeft = Util::bestFitScore(otherTetrominoCoordinates, currentCoordinatesPosLeft);
    BestFitObject fitObjectLeft(bestFitScoreLeft, RelativePosition::LEFT, currentCoordinatesPosLeft);
    fittingObjects.push_back(fitObjectLeft);

    while(Util::checkIntersection(otherTetrominoCoordinates, currentCoordinatesPosRight)){
        Util::shiftRight(currentCoordinatesPosRight);
    }
    bestFitScoreRight = Util::bestFitScore(otherTetrominoCoordinates, currentCoordinatesPosRight);
    BestFitObject fitObjectRight(bestFitScoreRight, RelativePosition::RIGHT, currentCoordinatesPosRight);
    fittingObjects.push_back(fitObjectRight);

    while(Util::checkIntersection(otherTetrominoCoordinates, currentCoordinatesPosBottom)){
        Util::shiftRight(currentCoordinatesPosBottom);
    }
    bestFitScoreBottom = Util::bestFitScore(otherTetrominoCoordinates, currentCoordinatesPosBottom);
    BestFitObject fitObjectBottom(bestFitScoreBottom, RelativePosition::BOTTOM, currentCoordinatesPosBottom);
    fittingObjects.push_back(fitObjectBottom);

    stable_sort(fittingObjects.begin(), fittingObjects.end());

    BestFitObject bestFitObject = fittingObjects.back();

    this->setEditedCoordinates(bestFitObject.getObjectCoordinates());
    this->currentPosition = bestFitObject.getRelativePosition();

    return true;
}

vector<Coordinate> Tetro_T::getCoordinates(RelativePosition relativePosition){
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

void Tetro_T::setEditedCoordinates(vector<Coordinate> editedCoordinates){
    this->editedCoordinates = editedCoordinates;
}

vector<Coordinate> Tetro_T::getEditedCoordinates() {
    return this->editedCoordinates;
}