#ifndef PRINT_HANDLER_H
#define PRINT_HANDLER_H

#include <vector>

#include <Coordinate.h>

using namespace std;

class PrintHandler {
public:
    static string convertCoordinatesToStringBuf(vector<Coordinate> coordinates);
};

#endif