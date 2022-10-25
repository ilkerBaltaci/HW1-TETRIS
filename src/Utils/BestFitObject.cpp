#include "BestFitObject.h"


BestFitObject::BestFitObject(int bestFitScore, RelativePosition relativePosition, vector<Coordinate> objectCoordinates){
    this->bestFitScore = bestFitScore;
    this->relativePosition = relativePosition;
    this->objectCoordinates = objectCoordinates;
}

int BestFitObject::getBestFitScore(){
    return this->bestFitScore;
}

void BestFitObject::setBestFitScore(int bestFitScore){
    this->bestFitScore = bestFitScore;
}

RelativePosition BestFitObject::getRelativePosition() {
    return this->relativePosition;
}

void BestFitObject::setRelativePosition(RelativePosition relativePosition){
    this->relativePosition = relativePosition;
}
vector<Coordinate> BestFitObject::getObjectCoordinates() {
    return this->objectCoordinates;
}

void BestFitObject::setObjectCoordinates(vector<Coordinate> objectCoordinates) {
    this->objectCoordinates = objectCoordinates;
}