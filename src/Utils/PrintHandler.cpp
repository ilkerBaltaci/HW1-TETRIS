#include "PrintHandler.h"

#include <iostream>
#include <algorithm>


string PrintHandler::convertCoordinatesToStringBuf(vector<Coordinate> coordinates) {
    // vector<pair<int, int>> coordinatePairs;
    // vector<pair<int, int>>::iterator ptrPairs;

    stable_sort(coordinates.begin(), coordinates.end());

    vector<Coordinate>::iterator ptr;
    string bufOfCoordinates;
    int mostIntPtr = -1;
    int tempX = 0;
    for(ptr = coordinates.begin(); ptr < coordinates.end(); ptr++){
        if(mostIntPtr == -1) {
            mostIntPtr = ptr->getY();
        }
        else if (mostIntPtr > ptr->getY()) {
            bufOfCoordinates.append("\n");
            mostIntPtr = ptr->getY();
            tempX = 0;
        }

        if(tempX == ptr->getX()){
            bufOfCoordinates.append(ptr->getSymbol());
            tempX++;
        }
        else if (tempX < ptr->getX()) {
            for(tempX; tempX == ptr->getX(); tempX++){
                bufOfCoordinates.append(" ");
            }
        }
        
        // coordinatePairs.push_back({ptr->getX(), ptr->getY()});
    }

    // for(ptrPairs = coordinatePairs.begin(); ptrPairs < coordinatePairs.end(); ptrPairs++){
    //     cout << ptrPairs->first << "," << ptrPairs->second << endl;
    // }

    return bufOfCoordinates;
}
