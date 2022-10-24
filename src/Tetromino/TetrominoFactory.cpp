#include "TetrominoFactory.h"

#include "TetroOptions.h"
#include "Tetro_I.h"
#include "Tetro_J.h"
#include "Tetro_L.h"
#include "Tetro_O.h"
#include "Tetro_S.h"
#include "Tetro_T.h"
#include "Tetro_Z.h"
#include "Util.h"

Tetromino* TetrominoFactory::factory(string tetrominoType) {
    if(tetrominoType.compare(Util::ToString(TetroOptions::I)) == 0){
        return new Tetro_I();
    }
    else if (tetrominoType.compare(Util::ToString(TetroOptions::J)) == 0){
        return new Tetro_J();
    }
    else if (tetrominoType.compare(Util::ToString(TetroOptions::L)) == 0){
        return new Tetro_L();
    }
    else if (tetrominoType.compare(Util::ToString(TetroOptions::O)) == 0){
        return new Tetro_O();
    }
    else if (tetrominoType.compare(Util::ToString(TetroOptions::S)) == 0){
        return new Tetro_S();
    }
    else if (tetrominoType.compare(Util::ToString(TetroOptions::T)) == 0){
        return new Tetro_T();
    }
    else if (tetrominoType.compare(Util::ToString(TetroOptions::Z)) == 0){
        return new Tetro_Z();
    }
    else {
        return nullptr;
    }
}