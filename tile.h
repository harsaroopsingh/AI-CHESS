#ifndef TILE_H
#define TILE_H

#include "info.h"
#include "piece.h"

class Tile {
    public:
        Colour c;
        PieceType p;
        int alphabet;
        int num;
        Tile();
        Tile(int alphabet, int number, Colour colour, PieceType pieceType);
        ~Tile();
        void placePiece(Piece * piece);
        Info getInfo() const;

};

#endif

