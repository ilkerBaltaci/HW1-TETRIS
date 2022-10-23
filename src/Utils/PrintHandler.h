#ifndef PRINT_HANDLER_H
#define PRINT_HANDLER_H

#include <vector>

#include <Coordinate.h>

using namespace std;

class PrintHandler {
public:
    static void printCoordinates(vector<Coordinate> coordinates);
};

#endif