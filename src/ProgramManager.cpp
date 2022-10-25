#include "ProgramManager.h"

#include <iostream>
#include <list>
#include "TetrominoFactory.h"
#include "Util.h"
#include "PrintHandler.h"

using namespace std;

ProgramManager::~ProgramManager(){
    if(!this->tetrominos.empty()){
        for(Tetromino* tetromino: this->tetrominos){
            delete tetromino;
        }
    }
}

int ProgramManager::askHowManyTetro() {
    cout << "How many tetrominos?" << endl;
    int numOfTetrominos = 0;
    cin >> numOfTetrominos;
    this->numOfTetromino = numOfTetrominos;
    return numOfTetrominos;
}

int ProgramManager::askTetroTypes() {
    list<string> tetroTypes;
    
    cout << "What are the types?" << endl;

    string tetroType;
    for(int i=0; i < this->numOfTetromino; i++){
        cin >> tetroType;
        tetroTypes.push_back(tetroType);
    }

    for(string tetroType : tetroTypes) {
        Tetromino* tetromino = TetrominoFactory::factory(tetroType);
        if(tetromino == nullptr){
            return -1;
        }
        this->tetrominos.push_back(tetromino);
    }

    cout << "Your tetrominos" << endl;

    for(Tetromino* tetromino : this->tetrominos){
        tetromino->print();
        cout << endl;
    }


    return 0;
}

void ProgramManager::performBestFitAndPrint() {
    Tetromino* tmpTetro= {};
    int index = 0;
    for(Tetromino* tetromino : this->tetrominos){
        if(index == 0) {
            tetromino->setBestPosition(nullptr);
        } else {
            tetromino->setBestPosition(tmpTetro);
        }
        
        tmpTetro = tetromino;
        index++;
    }

    vector<Coordinate> allObjects;
    index = 0;
    for(Tetromino* tetromino : this->tetrominos){
        vector<Coordinate> addedCoordinates;
        if(index == 0){
            allObjects = tetromino->getEditedCoordinates();
            index++;
            continue;
        }
        addedCoordinates = Util::concanateTwoBestFitObject(allObjects, tetromino->getEditedCoordinates());
        allObjects = addedCoordinates;
    }

    string buffer = PrintHandler::convertCoordinatesToStringBuf(allObjects);

    cout << "Horizotally best-fit tetrominos" << endl;
    cout << buffer << endl;
}
