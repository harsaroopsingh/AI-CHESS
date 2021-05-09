#ifndef CASTLE_H
#define CASTLE_H

#include "piece.h"

class Castle: public Piece {
    public:
        Castle(Colour colour, PieceType type);
        ~Castle();
};

#endif

