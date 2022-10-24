#include "Coordinate.h"

Coordinate::Coordinate(int x, int y, string symbol) {
    this->x = x;
    this->y = y;
    this->symbol = symbol;
}

const int Coordinate::getX() {
    return this->x;
}
const int Coordinate::getY() {
    return this->y;
}
string Coordinate::getSymbol() {
    return this->symbol;
}
void Coordinate::setX(int x) {
    this->x = x;
}
void Coordinate::setY(int y) {
    this->y = y;
}
void Coordinate::setSymbol(string symbol) {
    this->symbol = symbol;
}