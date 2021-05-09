#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn: public Piece {
    public:
        Pawn(Colour colour, PieceType type);
        ~Pawn();
};

#endif 

