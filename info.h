#ifndef INFO_H
#define INFO_H
#include <iostream>
#include <cstddef>

enum class PieceType { Castle, Pawn, Knight, Bishop, Queen, King, NoPiece };
enum class Colour { White, Black, NoColour };

struct randInfo {
    int i;
    int j;
    PieceType p;
};

struct Info {
    int alp;
    int num;
    PieceType type;
    Colour colour;
};

#endif

