#include <iostream>
#include "Tetromino.h"
#include "Tetro_J.h"
#include "TetroOptions.h"
#include "ProgramManager.h"
#include "Conversions.h"
#include "TetrominoFactory.h"
#include "Tetro_Z.h"
#include <sstream>
#include <curses.h>
#include "PrintHandler.h"

using namespace std;

int main() {
    //ProgramManager programManager;

    //programManager.askHowManyTetro();

    //programManager.askTetroTypes();
    //vector<vector<int>> cooardinates = {{0,0}, {0,1}, {0,2}, {0,3}};
    //Tetro_Z tetro_Z;

    //tetro_Z.print();
    
    // initscr();			/* Start curses mode 		  */
	// //printw("Hello World !!!");	/* Print Hello World		  */
    // wmove(stdscr, 0, 1);
    // printw("T");
    // wmove(stdscr, 0, 2);
    // printw("T");
    // wmove(stdscr, 1, 2);
    // printw("T");
    // wmove(stdscr, 2, 2);
    // printw("T");
	// refresh();			/* Print it on to the real screen */
	// getch();			/* Wait for user input */
	// endwin();			/* End curses mode		  */

    Tetro_Z tetro_Z;
    string result = PrintHandler::convertCoordinatesToStringBuf(tetro_Z.getCoordinates(RelativePosition::TOP));
    
    cout << endl << result << endl;


    return 0;
}