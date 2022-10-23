#include "Conversions.h"


string Conversions::ToString(TetroOptions tetroOptions) {

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
