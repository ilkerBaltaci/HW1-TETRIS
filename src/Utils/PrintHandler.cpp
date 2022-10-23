#include "PrintHandler.h"

#ifdef __linux__
#include <curses.h>
#endif


void PrintHandler::printCoordinates(vector<Coordinate> coordinates) {
    vector<Coordinate>::iterator ptr;
    //initscr();	
    //SCREEN* term = newterm(NULL, stdout, stdin);
    //set_term(term);
    refresh();
    WINDOW *my_window;
    for(ptr = coordinates.begin(); ptr < coordinates.end(); ptr++){
        /* Start curses mode 		  */
        //printw("Hello World !!!");	/* Print Hello World		  */
        wmove(my_window, ptr->getX(), ptr->getY());
        refresh();
        printw(ptr->getSymbol().c_str());
    }
    refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	//endwin();			/* End curses mode		  */
}