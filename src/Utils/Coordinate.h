#ifndef COORDINATE_H
#define COORDINATE_H

#include <string>

using namespace std;

class Coordinate {
private:
    int x;
    int y;
    string symbol;
public:
    Coordinate(int x, int y, string symbol);
    int getX();
    int getY();
    string getSymbol();
    void setX(int x);
    void setY(int y);
    void setSymbol(string symbol);
};

#endif