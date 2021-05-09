#include "tile.h"

Tile::Tile() {}

Tile::Tile(int alphabet, int number, Colour colour, PieceType pieceType):  c{colour}, p{pieceType}, alphabet{alphabet}, num{number}{}

Tile::~Tile() {

}

void Tile::placePiece(Piece * piece) {
    Info i;
    i.alp = alphabet;
    i.num = num;
    i.type = piece->pieceType;
    i.colour = piece->colour;
}

Info Tile::getInfo() const {
    return Info{alphabet, num, p, c};
}

