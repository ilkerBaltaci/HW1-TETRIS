#ifndef UTIL_H
#define UTIL_H

#include <string>
#include "TetroOptions.h"
#include <vector>
#include "Coordinate.h"

using namespace std;

class Util {
public:
    static string ToString(TetroOptions tetroOptions);
    static void shiftRight(vector<Coordinate>& coordinates);
    static bool checkIntersection(vector<Coordinate> otherTetrominoCoordinates, vector<Coordinate> currentTetrominoCoordinates);
    static int bestFitScore(vector<Coordinate> otherTetrominoCoordinates, vector<Coordinate> currentTetrominoCoordinates);
    static vector<Coordinate> concanateTwoBestFitObject(vector<Coordinate> otherTetrominoCoordinates, vector<Coordinate> currentTetrominoCoordinates);
};

#endif