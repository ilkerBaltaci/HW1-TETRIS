#ifndef BEST_FIT_OBJECT_H
#define BEST_FIT_OBJECT_H

#include "RelativePosition.h"
#include "Coordinate.h"
#include <vector>

class BestFitObject {
private:
    int bestFitScore;
    RelativePosition relativePosition;
    vector<Coordinate> objectCoordinates;
public:
    BestFitObject(int bestFitScore, RelativePosition relativePosition, vector<Coordinate> objectCoordinates);

    int getBestFitScore();
    void setBestFitScore(int bestFitScore);
    RelativePosition getRelativePosition();
    void setRelativePosition(RelativePosition relativePosition);
    vector<Coordinate> getObjectCoordinates();
    void setObjectCoordinates(vector<Coordinate> objectCoordinates);

    bool operator < (const BestFitObject& bfo) const{
        return this->bestFitScore < bfo.bestFitScore;
    };
};

#endif