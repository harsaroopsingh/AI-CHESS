#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "info.h"

class Piece {
    public:
        Colour colour;
        PieceType pieceType;
        Piece(Colour colour, PieceType pieceType);
        ~Piece();
        //
        //virtual bool canMove() = 0;
};

#endif

