#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight: public Piece {
    public:
        Knight(Colour colour, PieceType type);
        ~Knight();
};

#endif

