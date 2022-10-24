#include "PrintHandler.h"

#ifdef __linux__
#include <curses.h>
#endif

#include <sstream>
#include <iostream>
#include <algorithm>


void PrintHandler::printCoordinates(vector<Coordinate> coordinates) {
    vector<Coordinate>::iterator ptr;
    initscr();	
    //SCREEN* term = newterm(NULL, stdout, stdin);
    //set_term(term);
    refresh();
    WINDOW *my_window;
    streampos stDeneme;
    
    for(ptr = coordinates.begin(); ptr < coordinates.end(); ptr++){
        /* Start curses mode 		  */
        //printw("Hello World !!!");	/* Print Hello World		  */
        wmove(stdscr, ptr->getX(), ptr->getY());
        //refresh();
        printw(ptr->getSymbol().c_str());
    }
    printw("\n");
    refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
}

string PrintHandler::convertCoordinatesToStringBuf(vector<Coordinate> coordinates) {
    vector<pair<int, int>> coordinatePairs;
    vector<pair<int, int>>::iterator ptrPairs;
    
    vector<string> strMatrix;

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
            //continue;
        }
        else if (tempX < ptr->getX()) {
            for(tempX; tempX == ptr->getX(); tempX++){
                bufOfCoordinates.append(" ");
            }
        }
        
        coordinatePairs.push_back({ptr->getX(), ptr->getY()});
    }

    for(ptrPairs = coordinatePairs.begin(); ptrPairs < coordinatePairs.end(); ptrPairs++){
        cout << ptrPairs->first << "," << ptrPairs->second << endl;
    }

    return bufOfCoordinates;
}


// bool PrintHandler::sortByDescCoordinates(const Coordinate& coor1, const Coordinate& coor2) {

//     if(coor1.getX() == coor2.getX()) {
//         return coor2.getY() < coor2.getY();
//     }
//     return coor1.getX() > coor2.getX();
// }
