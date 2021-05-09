#ifndef NOPIECE_H
#define NOPIECE_H

#include "piece.h"

class NoPiece: public Piece {
    public:
        NoPiece(Colour colour, PieceType type);
        ~NoPiece();
};

#endif

