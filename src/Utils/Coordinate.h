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
    const int getX();
    const int getY();
    string getSymbol();
    void setX(int x);
    void setY(int y);
    void setSymbol(string symbol);
    bool operator < (const Coordinate& str) const{
        if(this->y == str.y){
            return this->x < str.x;
        }
        return this->y > str.y;
    };
};

#endif