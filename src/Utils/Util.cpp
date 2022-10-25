#include "Util.h"


string Util::ToString(TetroOptions tetroOptions) {

    switch(tetroOptions)
    {
    case TetroOptions::I :      return "I";
    case TetroOptions::J :      return "J";
    case TetroOptions::L :      return "L";
    case TetroOptions::O :      return "O";
    case TetroOptions::S :      return "S";
    case TetroOptions::T :      return "T";
    case TetroOptions::Z :      return "Z";
    default:                    return "Unknown";
        
    }
};

void Util::shiftRight(vector<Coordinate>& coordinates) {
    vector<Coordinate>::iterator ptr;
    for(ptr = coordinates.begin(); ptr < coordinates.end(); ptr++){
        ptr->setX(ptr->getX()+1);
    }
}

bool Util::checkIntersection(vector<Coordinate> otherTetrominoCoordinates, vector<Coordinate> currentTetrominoCoordinates) {
    for(Coordinate otherCoordinate : otherTetrominoCoordinates){
        for(Coordinate currentTetCoordinate : currentTetrominoCoordinates){
            if(otherCoordinate.getX() == currentTetCoordinate.getX() &&
                otherCoordinate.getY() == currentTetCoordinate.getY() &&
                !otherCoordinate.getSymbol()._Equal(" ") &&
                !currentTetCoordinate.getSymbol()._Equal(" ")) 
            {
                return true;
            }
        }
    }

    bool isAdjacent = false;
    for(Coordinate otherCoordinate : otherTetrominoCoordinates){
        for(Coordinate currentTetCoordinate : currentTetrominoCoordinates){
            if((otherCoordinate.getX() + 1) == currentTetCoordinate.getX() &&
                otherCoordinate.getY() == currentTetCoordinate.getY() &&
                !otherCoordinate.getSymbol()._Equal(" ") &&
                !currentTetCoordinate.getSymbol()._Equal(" ")) 
            {
                isAdjacent = true;
            }
        }
    }

    if(isAdjacent){
        return false;
    } else {
        return true;
    }

    
}

int Util::bestFitScore(vector<Coordinate> otherTetrominoCoordinates, vector<Coordinate> currentTetrominoCoordinates){
    int bestFitScore = 0;

    if(Util::checkIntersection(otherTetrominoCoordinates, currentTetrominoCoordinates)){
        return -1;
    }

    for(Coordinate otherCoordinate : otherTetrominoCoordinates){
        for(Coordinate currentTetCoordinate : currentTetrominoCoordinates){

            //Yeni gelen parça bir boşluğu dolduruyorsa +2 puan
            if(otherCoordinate.getX() == currentTetCoordinate.getX() &&
                otherCoordinate.getY() == currentTetCoordinate.getY() && 
                otherCoordinate.getSymbol()._Equal(" ") &&
                !currentTetCoordinate.getSymbol()._Equal(" ")
            )
            {
                bestFitScore += 6;
                continue;
            }

            //Yeni gelen parça eskisiyle bitişik ise +1 puan
            if((otherCoordinate.getX() + 1) == currentTetCoordinate.getX() &&
                otherCoordinate.getY() == currentTetCoordinate.getY() &&
                !otherCoordinate.getSymbol()._Equal(" ") &&
                !currentTetCoordinate.getSymbol()._Equal(" ")
            )
            {
                bestFitScore += 4;
                continue;
            }
            
        }
    }
    // Yere değen parçalar +1 puan değerinde
    for(Coordinate currentTetCoordinate : currentTetrominoCoordinates){
        if(currentTetCoordinate.getY() == 0 &&
            !currentTetCoordinate.getSymbol()._Equal(" ")
        ) 
        {
            bestFitScore += 1;
        }
    }

    vector<Coordinate> concanatedCoords = concanateTwoBestFitObject(otherTetrominoCoordinates, currentTetrominoCoordinates);

    for(Coordinate coor : concanatedCoords){
        if(coor.getSymbol()._Equal(" ")){
            int allDirections = 0;

            if(coor.getX() == 0){
                //Aşağıdaya bitişik olduğundan alt taraf bitişik kabul edildi.
                allDirections += 1;
            } else {
                Coordinate bottomCoor =getCoordinate(concanatedCoords, coor.getX() - 1, coor.getY());
                if(bottomCoor.getX() > 0 && !bottomCoor.getSymbol()._Equal(" ")) {
                    allDirections += 1;
                }
            }

            if(coor.getY() == 0) {
                //Yana bitişik olduğundan yan taraf bitişik kabul edildi.
                allDirections += 1;
            } else {
                Coordinate leftCoor =getCoordinate(concanatedCoords, coor.getX(), coor.getY() - 1);
                if(leftCoor.getY() > 0 && !leftCoor.getSymbol()._Equal(" ")) {
                    allDirections += 1;
                }
            }

            Coordinate rightCoor = getCoordinate(concanatedCoords, coor.getX() + 1, coor.getY());
            if(rightCoor.getX() > 0 && !rightCoor.getSymbol()._Equal(" ")) {
                allDirections += 1;
            }

            Coordinate topCoor = getCoordinate(concanatedCoords, coor.getX(), coor.getY() + 1);
            if(topCoor.getX() > 0 && !topCoor.getSymbol()._Equal(" ")) {
                allDirections += 1;
            }

            if(allDirections == 4) {
                bestFitScore -= 6;
            }
        }
        
    }



    return bestFitScore;
}

Coordinate Util::getCoordinate(vector<Coordinate> coordinateList, const int x, const int y){
    for(Coordinate coord : coordinateList){
        if(coord.getX() == x && coord.getY() == y){
            return coord;
        }
    }

    return Coordinate(-1, -1 , "-");
}

vector<Coordinate> Util::concanateTwoBestFitObject(vector<Coordinate> otherTetrominoCoordinates, vector<Coordinate> currentTetrominoCoordinates){
    vector<Coordinate>::iterator otherTetCoorPtr;
    vector<Coordinate>::iterator currentTetCoorPtr;

    if(checkIntersection(otherTetrominoCoordinates, currentTetrominoCoordinates)){
        return {};
    }
    vector<int> toBeDeletedOtherObjIndexes;
    vector<int> toBeDeletedCurrentObjIndexes;

    int temp1 = 0;
    int temp2 = 0;
    for(otherTetCoorPtr = otherTetrominoCoordinates.begin(); otherTetCoorPtr < otherTetrominoCoordinates.end(); otherTetCoorPtr++){
        for(currentTetCoorPtr = currentTetrominoCoordinates.begin(); currentTetCoorPtr < currentTetrominoCoordinates.end(); currentTetCoorPtr++){
            if(otherTetCoorPtr->getX() == currentTetCoorPtr->getX() &&
                otherTetCoorPtr->getY() == currentTetCoorPtr->getY() &&
                otherTetCoorPtr->getSymbol()._Equal(" ") &&
                !currentTetCoorPtr->getSymbol()._Equal(" ")
            )
            {
                toBeDeletedOtherObjIndexes.push_back(temp1);
                //toBeDeletedOtherObjs.push_back(&(*otherTetCoorPtr));
                //otherTetrominoCoordinates.erase(otherTetCoorPtr);
                continue;
            }

            if(otherTetCoorPtr->getX() == currentTetCoorPtr->getX() &&
                otherTetCoorPtr->getY() == currentTetCoorPtr->getY() &&
                !otherTetCoorPtr->getSymbol()._Equal(" ") &&
                currentTetCoorPtr->getSymbol()._Equal(" ")
            )
            {
                toBeDeletedCurrentObjIndexes.push_back(temp2);
                //toBeDeletedCurrentObjs.push_back(&(*currentTetCoorPtr));
                //currentTetrominoCoordinates.erase(currentTetCoorPtr);
            }
            temp2++;
        }
        temp1++;
        temp2 = 0;
    }

    int temp3 = 0;
    for(int index : toBeDeletedOtherObjIndexes) {
        index -=temp3;
        otherTetrominoCoordinates[index] = otherTetrominoCoordinates.back();
        otherTetrominoCoordinates.pop_back();
        temp3++;
    }

    int temp4 = 0;
    for(int index : toBeDeletedCurrentObjIndexes){
        index -= temp4;
        currentTetrominoCoordinates[index] = currentTetrominoCoordinates.back();
        currentTetrominoCoordinates.pop_back();
        temp4++;
    }
    

    otherTetrominoCoordinates.insert(otherTetrominoCoordinates.end(), currentTetrominoCoordinates.begin(), currentTetrominoCoordinates.end());

    return otherTetrominoCoordinates;
}