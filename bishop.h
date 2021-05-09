#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "piece.h"

class Bishop: public Piece {
    public:
        Bishop(Colour colour, PieceType type);
        ~Bishop();
};

#endif

