#include "chessboard.h"
#include "tile.h"
#include "pawn.h"
#include "castle.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "nopiece.h"

ChessBoard::ChessBoard() {

}

ChessBoard::~ChessBoard() {

}

void ChessBoard::init_empty() {
    // Create board 
    for (int height = 0; height < boardSize; ++height) {
        std::vector<Tile> temptile;
        for (int width = 0; width < boardSize; ++width) {
            Tile newTile = {width, height, Colour::NoColour, PieceType::NoPiece};
            temptile.emplace_back(newTile);
            } 
        chessBoard.emplace_back(temptile);
    }
}

void ChessBoard::init() {
    // Create board 
    for (int height = 0; height < boardSize; ++height) {
        std::vector<Tile> temptile;
        for (int width = 0; width < boardSize; ++width) {
            if (1 < height && height < 6) {
                Tile newTile = {width, height, Colour::NoColour, PieceType::NoPiece};
                temptile.emplace_back(newTile);
            } else if (height == 1) {
                Tile newTile = {width, height, Colour::Black, PieceType::Pawn};
                //gd->notify(height, width, Colour::Black, PieceType::Pawn);
                temptile.emplace_back(newTile);
            } else if (height == 6) {
                Tile newTile = {width, height, Colour::White, PieceType::Pawn};
                //gd->notify(height, width, Colour::White, PieceType::Pawn);
                temptile.emplace_back(newTile);
            } else if (height == 0){
                if (width == 0 || width == 7) {
                    Tile newTile = {width, height, Colour::Black, PieceType::Castle};
                    //gd->notify(height, width, Colour::Black, PieceType::Castle);
                    temptile.emplace_back(newTile);
                } else if (width == 1 || width == 6) {
                    Tile newTile = {width, height, Colour::Black, PieceType::Knight};
                    //gd->notify(height, width, Colour::Black, PieceType::Knight);
                    temptile.emplace_back(newTile);
                }  else  if (width == 2 || width == 5) {
                    Tile newTile = {width, height, Colour::Black, PieceType::Bishop};
                    //gd->notify(height, width, Colour::Black, PieceType::Bishop);
                    temptile.emplace_back(newTile);
                } else  if (width == 3) {
                    Tile newTile = {width, height, Colour::Black, PieceType::Queen};
                    //gd->notify(height, width, Colour::Black, PieceType::Queen);
                    temptile.emplace_back(newTile);
                } else  if (width == 4) {
                    Tile newTile = {width, height, Colour::Black, PieceType::King};
                    //gd->notify(height, width, Colour::Black, PieceType::King);
                    temptile.emplace_back(newTile);
                } 
            } else if (height == 7) {
                if (width == 0 || width == 7) {
                    Tile newTile = {width, height, Colour::White, PieceType::Castle};
                    //gd->notify(height, width, Colour::White, PieceType::Castle);
                    temptile.emplace_back(newTile);
                } else  if (width == 1 || width == 6) {
                    Tile newTile = {width, height, Colour::White, PieceType::Knight};
                    //gd->notify(height, width, Colour::White, PieceType::Knight);
                    temptile.emplace_back(newTile);
                } else  if (width == 2 || width == 5) {
                    Tile newTile = {width, height, Colour::White, PieceType::Bishop};
                    //gd->notify(height, width, Colour::White, PieceType::Bishop);
                    temptile.emplace_back(newTile);
                } else  if (width == 3) {
                    Tile newTile = {width, height, Colour::White, PieceType::Queen};
                    //gd->notify(height, width, Colour::White, PieceType::Queen);
                    temptile.emplace_back(newTile);
                } else  if (width == 4) {
                    Tile newTile = {width, height, Colour::White, PieceType::King};
                    //gd->notify(height, width, Colour::White, PieceType::King);
                    temptile.emplace_back(newTile);
                } 
            }
        }
        chessBoard.emplace_back(temptile);
    }
}

std::ostream &operator<<(std::ostream &out, const ChessBoard &cb) {
    for (int height = 0; height < 9; ++height) {
        for (int width = 0; width < 8; ++width) {
            // printing numbers left
            if (height == 0 && width == 0) {
                out << "8 ";
            } else if (height == 1 && width == 0) {
                out << "7 ";
            } else if (height == 2 && width == 0) {
                out << "6 ";
            } else if (height == 3 && width == 0) {
                out << "5 ";
            } else if (height == 4 && width == 0) {
                out << "4 ";
            } else if (height == 5 && width == 0) {
                out << "3 ";
            } else if (height == 6 && width == 0) {
                out << "2 ";
            } else if (height == 7 && width == 0) {
                out << "1 ";
            }
            // printing alphabets bottom
            if (height == 8 && width == 0) {
                out << "  a";
            } else if (height == 8 && width == 1) {
                out << "b";
            } else if (height == 8 && width == 2) {
                out << "c";
            } else if (height == 8 && width == 3) {
                out << "d";
            } else if (height == 8 && width == 4) {
                out << "e";
            } else if (height == 8 && width == 5) {
                out << "f";
            } else if (height == 8 && width == 6) {
                out << "g";
            } else if (height == 8 && width == 7) {
                out << "h";
            }
            // printing chess pieces
            if (height < 8) {
                if (cb.chessBoard[height][width].getInfo().colour == Colour::White) {
                    if (cb.chessBoard[height][width].getInfo().type == PieceType::Pawn) {
                        out << "P";
                    } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Castle) {
                        if (height == 7 && width == 7) {
                            out << "R";
                            std::cout << std::endl;
                        } else {
                            out << "R";
                        }
                    } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Knight) {
                        out << "N";
                    } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Bishop) {
                        out << "B";
                    } else if (cb.chessBoard[height][width].getInfo().type == PieceType::King) {
                        out << "K";
                    } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Queen) {
                        out << "Q";
                    } 
                } else if (cb.chessBoard[height][width].getInfo().colour == Colour::Black) {
                    if (cb.chessBoard[height][width].getInfo().type == PieceType::Pawn) {
                        out << "p";
                    } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Castle) {
                        out << "r";
                    } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Knight) {
                        out << "n";
                    } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Bishop) {
                        out << "b";
                    } else if (cb.chessBoard[height][width].getInfo().type == PieceType::King) {
                        out << "k";
                    } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Queen) {
                        out << "q";
                    }  
                } else {
                    if ((height % 2 != 0 && width % 2 == 0) || (height % 2 == 0 &&  width % 2 != 0)) {
                        out << "-";
                    } else {
                        out << " ";
                    }
                }
            }
        }
        std::cout << std::endl;
    }
    return out;
}

int ChessBoard::WhiteKingPosX(ChessBoard &cb) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (cb.chessBoard[i][j].p == PieceType::King && cb.chessBoard[i][j].c == Colour::White) {
                return j;
            }
        }
    }
}
int ChessBoard::WhiteKingPosY(ChessBoard &cb) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (cb.chessBoard[i][j].p == PieceType::King && cb.chessBoard[i][j].c == Colour::White) {
                return i;
            }
        }
    }
}

int ChessBoard::BlackKingPosX(ChessBoard &cb) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (cb.chessBoard[i][j].p == PieceType::King && cb.chessBoard[i][j].c == Colour::Black) {
                return j;
            }
        }
    }
}
int ChessBoard::BlackKingPosY(ChessBoard &cb) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (cb.chessBoard[i][j].p == PieceType::King && cb.chessBoard[i][j].c == Colour::Black) {
                return i;
            }
        }
    }
}

int ChessBoard::getX(char s) {
    if (s == 'a') {
        return 1;
    } else if (s == 'b') {
        return 2;
    } else if (s == 'c') {
        return 3;
    } else if (s == 'd') {
        return 4;
    } else if (s == 'e') {
        return 5;
    } else if (s == 'f') {
        return 6;
    } else if (s == 'g') {
        return 7;
    } else if (s == 'h') {
        return 8;
    }
}

int ChessBoard::getY(char s) {
    int row = s - '0';
    return row;
}
/*
bool ChessBoard::isWhiteStalemate(int i, int j, ChessBoard &cb, std::vector <std::string> inputVector) {
    std::cout << "in stalemate function" << std::endl;
    Tile original = cb.chessBoard[i][j];
    
    std::cout << i << " here c " << j << std::endl;
    if (i == 0) {
        if (j == 0) {
            if (cb.isWhiteCheck(cb, original, chessBoard[i][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j], inputVector)) {
                    return true;
                }
        } else if (j == 7) {
            if (cb.isWhiteCheck(cb, original, chessBoard[i][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j], inputVector)) {
                    return true;
                }
        } else {
            if (cb.isWhiteCheck(cb, original, chessBoard[i][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j], inputVector)) {
                    return true;
                }
        }
    } else if (i == 7) {
         std::cout << "i is 7" << std::endl;
        if (j == 0) {
             std::cout << cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) << std::endl;
             std::cout << cb.isWhiteCheck(cb, original, chessBoard[i-1][j+1], inputVector)  << std::endl;
             std::cout << cb.isWhiteCheck(cb, original, chessBoard[i][j+1], inputVector) << std::endl;
             std::cout << "j is 0" << std::endl;
            if (cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i][j+1], inputVector)) {
                    return true;
                }
        } else if (j == 7) {
            if  (cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i][j-1], inputVector)) {
                    return true;
                }
        } else {
            if (cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i][j-1], inputVector)) {
                    return true;
                }
        }
    } else if (j == 0) {
        if (i == 0) {
            if (cb.isWhiteCheck(cb, original, chessBoard[i][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j], inputVector)) {
                    return true;
                }
        } else if (i == 7) {
            if (cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i][j+1], inputVector)) {
                    return true;
                }
        } else {
            if (cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j], inputVector)) {
                    return true;
                }
        }
    } else if (j == 7) {
        if (i == 0) {
            if (cb.isWhiteCheck(cb, original, chessBoard[i][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j], inputVector)) {
                    return true;
                }
        } else if (i == 7) {
            if  (cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i][j-1], inputVector)) {
                    return true;
                }
        } else {
            if  (cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i+1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i][j-1], inputVector)) {
                    return true;
                }
        }
    } else {
        if  (cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i][j+1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j-1], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j], inputVector) &&
                cb.isWhiteCheck(cb, original, chessBoard[i-1][j+1], inputVector)) {
                    return true;
                }
    }
    return false;
} 

bool ChessBoard::isBlackStalemate(int i, int j, ChessBoard &cb, std::vector <std::string> inputVector) {
    
} */

bool ChessBoard::isWhiteCheck(ChessBoard &cb, Tile t1, Tile t2, std::vector <std::string> inputVector) {
    // Temporarily move piece
    int x1 = cb.getX(inputVector[1][0]);
    int y1 = cb.getY(inputVector[1][1]);
    int x2 = cb.getX(inputVector[2][0]);
    int y2 = cb.getY(inputVector[2][1]);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (t1.p == PieceType::King && t1.c == Colour::White) {
                cb.castlingWhiteAllowedLeft = false;
                cb.castlingWhiteAllowedRight = false;
            } else if (t1.p == PieceType::King && t1.c == Colour::Black) {
                cb.castlingBlackAllowedRight = false;
                cb.castlingBlackAllowedLeft = false;
            } else if (t1.p == PieceType::Castle && t1.c == Colour::White && t1.num == 1 && t1.alphabet == 1) {
                cb.castlingWhiteAllowedLeft = false;
            } else if (t1.p == PieceType::Castle && t1.c == Colour::White && t1.num == 1 && t1.alphabet == 8) {
                cb.castlingWhiteAllowedRight = false;
            } else if (t1.p == PieceType::Castle && t1.c == Colour::Black && t1.num == 8 && t1.alphabet == 1) {
                cb.castlingBlackAllowedLeft = false;
            } else if (t1.p == PieceType::Castle && t1.c == Colour::Black && t1.num == 8 && t1.alphabet == 8) {
                cb.castlingBlackAllowedRight = false;
            }
            if (i == 8 - y1 && j == x1 - 1) {
                 Tile newT = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                 cb.chessBoard[i][j] = newT;
            }
            if (i == 8 - y2 && j == x2 - 1) {
                Tile newT = {x2, y2, t1.c, t1.p};
                cb.chessBoard[i][j] = newT;
            } 
        }
    }
    // Scan vertically up
    for (int i = 0; i < WhiteKingPosY(cb); ++i) {
        if (cb.chessBoard[WhiteKingPosY(cb) - i - 1][WhiteKingPosX(cb)].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[WhiteKingPosY(cb) - i - 1][WhiteKingPosX(cb)].alphabet, cb.chessBoard[WhiteKingPosY(cb) - i - 1][WhiteKingPosX(cb)].num, cb.chessBoard[WhiteKingPosY(cb) - i - 1][WhiteKingPosX(cb)].c, cb.chessBoard[WhiteKingPosY(cb) - i - 1][WhiteKingPosX(cb)].p};
            Tile WhiteKing = {WhiteKingPosX(cb) + 1, 8 - WhiteKingPosY(cb), Colour::White, PieceType::King};
            if (IsLegal(Encounter, WhiteKing, cb) && IsValid(Encounter, WhiteKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan vertically down
    for (int i = 0; i < 8 - WhiteKingPosY(cb) - 1; ++i) {
        if (cb.chessBoard[WhiteKingPosY(cb) + i + 1][WhiteKingPosX(cb)].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[WhiteKingPosY(cb) + i + 1][WhiteKingPosX(cb)].alphabet, cb.chessBoard[WhiteKingPosY(cb) + i + 1][WhiteKingPosX(cb)].num, cb.chessBoard[WhiteKingPosY(cb) + i + 1][WhiteKingPosX(cb)].c, cb.chessBoard[WhiteKingPosY(cb) + i + 1][WhiteKingPosX(cb)].p};
            Tile WhiteKing = {WhiteKingPosX(cb) + 1, 8 - WhiteKingPosY(cb), Colour::White, PieceType::King};
            if (IsLegal(Encounter, WhiteKing, cb) && IsValid(Encounter, WhiteKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan horizontally right
    for (int i = 0; i < 8 - WhiteKingPosX(cb) - 1; ++i) {
        if (cb.chessBoard[WhiteKingPosY(cb)][WhiteKingPosX(cb)+i+1].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[WhiteKingPosY(cb)][WhiteKingPosX(cb)+i+1].alphabet, cb.chessBoard[WhiteKingPosY(cb)][WhiteKingPosX(cb)+i+1].num, cb.chessBoard[WhiteKingPosY(cb)][WhiteKingPosX(cb)+i+1].c, cb.chessBoard[WhiteKingPosY(cb)][WhiteKingPosX(cb)+i+1].p};
            Tile WhiteKing = {WhiteKingPosX(cb) + 1, 8 - WhiteKingPosY(cb), Colour::White, PieceType::King};
            if (IsLegal(Encounter, WhiteKing, cb) && IsValid(Encounter, WhiteKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan horizontally left
    for (int i = 0; i < WhiteKingPosX(cb); ++i) {
        if (cb.chessBoard[WhiteKingPosY(cb)][WhiteKingPosX(cb)-i-1].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[WhiteKingPosY(cb)][WhiteKingPosX(cb)-i-1].alphabet, cb.chessBoard[WhiteKingPosY(cb)][WhiteKingPosX(cb)-i-1].num, cb.chessBoard[WhiteKingPosY(cb)][WhiteKingPosX(cb)-i-1].c, cb.chessBoard[WhiteKingPosY(cb)][WhiteKingPosX(cb)-i-1].p};
            Tile WhiteKing = {WhiteKingPosX(cb) + 1, 8 - WhiteKingPosY(cb), Colour::White, PieceType::King};
            if (IsLegal(Encounter, WhiteKing, cb) && IsValid(Encounter, WhiteKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    } 
    // Scan Diagonal Path Up Right
    for (int i = 0; i < std::min(WhiteKingPosY(cb), 8 - WhiteKingPosX(cb) -1); ++i) {
        if (cb.chessBoard[WhiteKingPosY(cb)-i-1][WhiteKingPosX(cb)+i+1].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[WhiteKingPosY(cb)-i-1][WhiteKingPosX(cb)+i+1].alphabet, cb.chessBoard[WhiteKingPosY(cb)-i-1][WhiteKingPosX(cb)+i+1].num, cb.chessBoard[WhiteKingPosY(cb)-i-1][WhiteKingPosX(cb)+i+1].c, cb.chessBoard[WhiteKingPosY(cb)-i-1][WhiteKingPosX(cb)+i+1].p};
            Tile WhiteKing = {WhiteKingPosX(cb) + 1, 8 - WhiteKingPosY(cb), Colour::White, PieceType::King};
            if (IsLegal(Encounter, WhiteKing, cb) && IsValid(Encounter, WhiteKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan Diagonal Path Down Left
    for (int i = 0; i < std::min(WhiteKingPosX(cb), 8 - WhiteKingPosY(cb) - 1); ++i) {
        if (cb.chessBoard[WhiteKingPosY(cb)+i+1][WhiteKingPosX(cb)-i-1].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[WhiteKingPosY(cb)+i+1][WhiteKingPosX(cb)-i-1].alphabet, cb.chessBoard[WhiteKingPosY(cb)+i+1][WhiteKingPosX(cb)-i-1].num, cb.chessBoard[WhiteKingPosY(cb)+i+1][WhiteKingPosX(cb)-i-1].c, cb.chessBoard[WhiteKingPosY(cb)+i+1][WhiteKingPosX(cb)-i-1].p};
            Tile WhiteKing = {WhiteKingPosX(cb) + 1, 8 - WhiteKingPosY(cb), Colour::White, PieceType::King};
            if (IsLegal(Encounter, WhiteKing, cb) && IsValid(Encounter, WhiteKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan Diagonal Path Down Right
    for (int i = 0; i < std::min(8 - WhiteKingPosY(cb) - 1, 8 - WhiteKingPosX(cb) - 1) ; ++i) {
        if (cb.chessBoard[WhiteKingPosY(cb)+i+1][WhiteKingPosX(cb)+i+1].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[WhiteKingPosY(cb)+i+1][WhiteKingPosX(cb)+i+1].alphabet, cb.chessBoard[WhiteKingPosY(cb)+i+1][WhiteKingPosX(cb)+i+1].num, cb.chessBoard[WhiteKingPosY(cb)+i+1][WhiteKingPosX(cb)+i+1].c, cb.chessBoard[WhiteKingPosY(cb)+i+1][WhiteKingPosX(cb)+i+1].p};
            Tile WhiteKing = {WhiteKingPosX(cb) + 1, 8 - WhiteKingPosY(cb), Colour::White, PieceType::King};
            if (IsLegal(Encounter, WhiteKing, cb) && IsValid(Encounter, WhiteKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan Diagonal Path Up Left
    for (int i = 0; i < std::min(WhiteKingPosX(cb), WhiteKingPosY(cb)); ++i) {
        if (cb.chessBoard[WhiteKingPosY(cb)-i-1][WhiteKingPosX(cb)-i-1].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[WhiteKingPosY(cb)-i-1][WhiteKingPosX(cb)-i-1].alphabet, cb.chessBoard[WhiteKingPosY(cb)-i-1][WhiteKingPosX(cb)-i-1].num, cb.chessBoard[WhiteKingPosY(cb)-i-1][WhiteKingPosX(cb)-i-1].c, cb.chessBoard[WhiteKingPosY(cb)-i-1][WhiteKingPosX(cb)-i-1].p};
            Tile WhiteKing = {WhiteKingPosX(cb) + 1, 8 - WhiteKingPosY(cb), Colour::White, PieceType::King};
            if (IsLegal(Encounter, WhiteKing, cb) && IsValid(Encounter, WhiteKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    } 
    // Scan Knight Path
    if (WhiteKingPosX(cb) == 7) {
        // y alternating, x is 7
        if (WhiteKingPosY(cb) == 0) {
            if (cb.chessBoard[2][6].p == PieceType::Knight && cb.chessBoard[2][6].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[1][5].p == PieceType::Knight && cb.chessBoard[1][5].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
        else if (WhiteKingPosY(cb) == 1) {
            if (cb.chessBoard[0][5].p == PieceType::Knight && cb.chessBoard[0][5].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][5].p == PieceType::Knight && cb.chessBoard[2][5].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[3][6].p == PieceType::Knight && cb.chessBoard[3][6].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
        else if (WhiteKingPosY(cb) == 6) {
            if (cb.chessBoard[4][6].p == PieceType::Knight && cb.chessBoard[4][6].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][5].p == PieceType::Knight && cb.chessBoard[5][5].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[7][5].p == PieceType::Knight && cb.chessBoard[7][5].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
        else if (WhiteKingPosY(cb) == 7) {
            if (cb.chessBoard[5][6].p == PieceType::Knight && cb.chessBoard[5][6].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[6][5].p == PieceType::Knight && cb.chessBoard[6][5].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
        else {
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].p == PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].p == PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].p == PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].p == PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
    } else if (WhiteKingPosX(cb) == 6) {
        // y alternating, x is 6
        if (WhiteKingPosY(cb) == 0) {
            if (cb.chessBoard[1][4].p == PieceType::Knight && cb.chessBoard[1][4].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][5].p == PieceType::Knight && cb.chessBoard[2][5].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][7].p == PieceType::Knight && cb.chessBoard[2][7].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 1) {
            if (cb.chessBoard[0][4].p == PieceType::Knight && cb.chessBoard[0][4].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][4].p == PieceType::Knight && cb.chessBoard[2][4].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[3][5].p == PieceType::Knight && cb.chessBoard[3][5].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[3][7].p == PieceType::Knight && cb.chessBoard[3][7].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 6) {
            if (cb.chessBoard[4][7].p == PieceType::Knight && cb.chessBoard[4][7].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[4][5].p == PieceType::Knight && cb.chessBoard[4][5].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][4].p == PieceType::Knight && cb.chessBoard[5][4].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[7][4].p == PieceType::Knight && cb.chessBoard[7][4].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 7) {
            if (cb.chessBoard[5][7].p == PieceType::Knight && cb.chessBoard[5][7].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][5].p == PieceType::Knight && cb.chessBoard[5][5].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[6][4].p == PieceType::Knight && cb.chessBoard[6][4].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else {
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
    } else if (WhiteKingPosX(cb) == 1) {
        // y alternating, x is 1
        if (WhiteKingPosY(cb) == 0) {
            if (cb.chessBoard[2][0].p == PieceType::Knight && cb.chessBoard[2][0].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][2].p == PieceType::Knight && cb.chessBoard[2][2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[1][3].p == PieceType::Knight && cb.chessBoard[1][3].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 1) {
            if (cb.chessBoard[3][0].p == PieceType::Knight && cb.chessBoard[3][0].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[3][2].p == PieceType::Knight && cb.chessBoard[3][2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][3].p == PieceType::Knight && cb.chessBoard[2][3].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[0][3].p == PieceType::Knight && cb.chessBoard[0][3].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 6) {
            if (cb.chessBoard[4][0].p == PieceType::Knight && cb.chessBoard[4][0].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[4][2].p == PieceType::Knight && cb.chessBoard[4][2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][3].p == PieceType::Knight && cb.chessBoard[5][3].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[7][3].p == PieceType::Knight && cb.chessBoard[7][3].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 7) {
            if (cb.chessBoard[5][0].p == PieceType::Knight && cb.chessBoard[5][0].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][2].p == PieceType::Knight && cb.chessBoard[5][2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[6][3].p == PieceType::Knight && cb.chessBoard[6][3].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else {
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
    } else if (WhiteKingPosX(cb) == 0) {
        // y alternating, x is 0
        if (WhiteKingPosY(cb) == 0) {
            if (cb.chessBoard[1][2].p == PieceType::Knight && cb.chessBoard[1][2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][1].p == PieceType::Knight && cb.chessBoard[2][1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 1) {
            if (cb.chessBoard[0][2].p == PieceType::Knight && cb.chessBoard[0][2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][2].p == PieceType::Knight && cb.chessBoard[2][2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[3][1].p == PieceType::Knight && cb.chessBoard[3][1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 6) {
            if (cb.chessBoard[4][1].p == PieceType::Knight && cb.chessBoard[4][1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][2].p == PieceType::Knight && cb.chessBoard[5][2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[7][2].p == PieceType::Knight && cb.chessBoard[7][2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 7) {
            if (cb.chessBoard[5][1].p == PieceType::Knight && cb.chessBoard[5][1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[6][2].p == PieceType::Knight && cb.chessBoard[6][2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else {
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
    } else {
        if (WhiteKingPosY(cb) == 0) {
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 1) {
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 6) {
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (WhiteKingPosY(cb) == 7) {
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else {
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) - 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) - 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 1][WhiteKingPosX(cb) + 2].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) - 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[WhiteKingPosY(cb) + 2][WhiteKingPosX(cb) + 1].c == Colour::Black) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
    } 
    return false;
}

bool ChessBoard::isBlackCheck(ChessBoard &cb, Tile t1, Tile t2, std::vector <std::string> inputVector) {
    // Temporarily move piece
    int x1 = cb.getX(inputVector[1][0]);
    int y1 = cb.getY(inputVector[1][1]);
    int x2 = cb.getX(inputVector[2][0]);
    int y2 = cb.getY(inputVector[2][1]);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (t1.p == PieceType::King && t1.c == Colour::White) {
                cb.castlingWhiteAllowedLeft = false;
                cb.castlingWhiteAllowedRight = false;
            } else if (t1.p == PieceType::King && t1.c == Colour::Black) {
                cb.castlingBlackAllowedRight = false;
                cb.castlingBlackAllowedLeft = false;
            } else if (t1.p == PieceType::Castle && t1.c == Colour::White && t1.num == 1 && t1.alphabet == 1) {
                cb.castlingWhiteAllowedLeft = false;
            } else if (t1.p == PieceType::Castle && t1.c == Colour::White && t1.num == 1 && t1.alphabet == 8) {
                cb.castlingWhiteAllowedRight = false;
            } else if (t1.p == PieceType::Castle && t1.c == Colour::Black && t1.num == 8 && t1.alphabet == 1) {
                cb.castlingBlackAllowedLeft = false;
            } else if (t1.p == PieceType::Castle && t1.c == Colour::Black && t1.num == 8 && t1.alphabet == 8) {
                cb.castlingBlackAllowedRight = false;
            }
            if (i == 8 - y1 && j == x1 - 1) {
                 Tile newT = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                 cb.chessBoard[i][j] = newT;
            }
            if (i == 8 - y2 && j == x2 - 1) {
                Tile newT = {x2, y2, t1.c, t1.p};
                cb.chessBoard[i][j] = newT;
            } 
        }
    }
    // Scan vertically up
    for (int i = 0; i < BlackKingPosY(cb); ++i) {
        if (cb.chessBoard[BlackKingPosY(cb) - i - 1][BlackKingPosX(cb)].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[BlackKingPosY(cb) - i - 1][BlackKingPosX(cb)].alphabet, cb.chessBoard[BlackKingPosY(cb) - i - 1][BlackKingPosX(cb)].num, cb.chessBoard[BlackKingPosY(cb) - i - 1][BlackKingPosX(cb)].c, cb.chessBoard[BlackKingPosY(cb) - i - 1][BlackKingPosX(cb)].p};
            Tile BlackKing = {BlackKingPosX(cb) + 1, 8 - BlackKingPosY(cb), Colour::Black, PieceType::King};
            if (IsLegal(Encounter, BlackKing, cb) && IsValid(Encounter, BlackKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan vertically down
    for (int i = 0; i < 8 - BlackKingPosY(cb) - 1; ++i) {
        if (cb.chessBoard[BlackKingPosY(cb) + i + 1][BlackKingPosX(cb)].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[BlackKingPosY(cb) + i + 1][BlackKingPosX(cb)].alphabet, cb.chessBoard[BlackKingPosY(cb) + i + 1][BlackKingPosX(cb)].num, cb.chessBoard[BlackKingPosY(cb) + i + 1][BlackKingPosX(cb)].c, cb.chessBoard[BlackKingPosY(cb) + i + 1][BlackKingPosX(cb)].p};
            Tile BlackKing = {BlackKingPosX(cb) + 1, 8 - BlackKingPosY(cb), Colour::Black, PieceType::King};
            if (IsLegal(Encounter, BlackKing, cb) && IsValid(Encounter, BlackKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan horizontally right
    for (int i = 0; i < 8 - BlackKingPosX(cb) - 1; ++i) {
        if (cb.chessBoard[BlackKingPosY(cb)][BlackKingPosX(cb)+i+1].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[BlackKingPosY(cb)][BlackKingPosX(cb)+i+1].alphabet, cb.chessBoard[BlackKingPosY(cb)][BlackKingPosX(cb)+i+1].num, cb.chessBoard[BlackKingPosY(cb)][BlackKingPosX(cb)+i+1].c, cb.chessBoard[BlackKingPosY(cb)][BlackKingPosX(cb)+i+1].p};
            Tile BlackKing = {BlackKingPosX(cb) + 1, 8 - BlackKingPosY(cb), Colour::Black, PieceType::King};
            if (IsLegal(Encounter, BlackKing, cb) && IsValid(Encounter, BlackKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan horizontally left
    for (int i = 0; i < BlackKingPosX(cb); ++i) {
        if (cb.chessBoard[BlackKingPosY(cb)][BlackKingPosX(cb)-i-1].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[BlackKingPosY(cb)][BlackKingPosX(cb)-i-1].alphabet, cb.chessBoard[BlackKingPosY(cb)][BlackKingPosX(cb)-i-1].num, cb.chessBoard[BlackKingPosY(cb)][BlackKingPosX(cb)-i-1].c, cb.chessBoard[BlackKingPosY(cb)][BlackKingPosX(cb)-i-1].p};
            Tile BlackKing = {BlackKingPosX(cb) + 1, 8 - BlackKingPosY(cb), Colour::Black, PieceType::King};
            if (IsLegal(Encounter, BlackKing, cb) && IsValid(Encounter, BlackKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    } 
    // Scan Diagonal Path Up Right
    for (int i = 0; i < std::min(BlackKingPosY(cb), 8 - BlackKingPosX(cb) -1); ++i) {
        if (cb.chessBoard[BlackKingPosY(cb)-i-1][BlackKingPosX(cb)+i+1].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[BlackKingPosY(cb)-i-1][BlackKingPosX(cb)+i+1].alphabet, cb.chessBoard[BlackKingPosY(cb)-i-1][BlackKingPosX(cb)+i+1].num, cb.chessBoard[BlackKingPosY(cb)-i-1][BlackKingPosX(cb)+i+1].c, cb.chessBoard[BlackKingPosY(cb)-i-1][BlackKingPosX(cb)+i+1].p};
            Tile BlackKing = {BlackKingPosX(cb) + 1, 8 - BlackKingPosY(cb), Colour::Black, PieceType::King};
            if (IsLegal(Encounter, BlackKing, cb) && IsValid(Encounter, BlackKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan Diagonal Path Down Left
    for (int i = 0; i < std::min(BlackKingPosX(cb), 8 - BlackKingPosY(cb) - 1); ++i) {
        if (cb.chessBoard[BlackKingPosY(cb)+i+1][BlackKingPosX(cb)-i-1].p != PieceType::NoPiece) {
            Tile Encounter = {cb.chessBoard[BlackKingPosY(cb)+i+1][BlackKingPosX(cb)-i-1].alphabet, cb.chessBoard[BlackKingPosY(cb)+i+1][BlackKingPosX(cb)-i-1].num, cb.chessBoard[BlackKingPosY(cb)+i+1][BlackKingPosX(cb)-i-1].c, cb.chessBoard[BlackKingPosY(cb)+i+1][BlackKingPosX(cb)-i-1].p};
            Tile BlackKing = {BlackKingPosX(cb) + 1, 8 - BlackKingPosY(cb), Colour::Black, PieceType::King};
            if (IsLegal(Encounter, BlackKing, cb) && IsValid(Encounter, BlackKing, cb)) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan Diagonal Path Down Right
    for (int i = 0; i < std::min(8 - BlackKingPosY(cb) - 1, 8 - BlackKingPosX(cb) - 1) ; ++i) {
        
        if (cb.chessBoard[BlackKingPosY(cb)+i+1][BlackKingPosX(cb)+i+1].p != PieceType::NoPiece) {
            
            Tile Encounter = {cb.chessBoard[BlackKingPosY(cb)+i+1][BlackKingPosX(cb)+i+1].alphabet, cb.chessBoard[BlackKingPosY(cb)+i+1][BlackKingPosX(cb)+i+1].num, cb.chessBoard[BlackKingPosY(cb)+i+1][BlackKingPosX(cb)+i+1].c, cb.chessBoard[BlackKingPosY(cb)+i+1][BlackKingPosX(cb)+i+1].p};
            Tile BlackKing = {BlackKingPosX(cb) + 1, 8 - BlackKingPosY(cb), Colour::Black, PieceType::King};
            
            if (IsLegal(Encounter, BlackKing, cb) && IsValid(Encounter, BlackKing, cb)) {
                
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    }
    // Scan Diagonal Path Up Left
    for (int i = 0; i < std::min(BlackKingPosX(cb), BlackKingPosY(cb)); ++i) {
        
        if (cb.chessBoard[BlackKingPosY(cb)-i-1][BlackKingPosX(cb)-i-1].p != PieceType::NoPiece) {
            
            Tile Encounter = {cb.chessBoard[BlackKingPosY(cb)-i-1][BlackKingPosX(cb)-i-1].alphabet, cb.chessBoard[BlackKingPosY(cb)-i-1][BlackKingPosX(cb)-i-1].num, cb.chessBoard[BlackKingPosY(cb)-i-1][BlackKingPosX(cb)-i-1].c, cb.chessBoard[BlackKingPosY(cb)-i-1][BlackKingPosX(cb)-i-1].p};
            Tile BlackKing = {BlackKingPosX(cb) + 1, 8 - BlackKingPosY(cb), Colour::Black, PieceType::King};
            
            if (IsLegal(Encounter, BlackKing, cb) && IsValid(Encounter, BlackKing, cb)) {
                
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            break;
        }
    } 
    // Scan Knight Path 
    if (BlackKingPosX(cb) == 7) {
        // y alternating, x is 7
        if (BlackKingPosY(cb) == 0) {
            if (cb.chessBoard[2][6].p == PieceType::Knight && cb.chessBoard[2][6].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[1][5].p == PieceType::Knight && cb.chessBoard[1][5].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
        else if (BlackKingPosY(cb) == 1) {
            if (cb.chessBoard[0][5].p == PieceType::Knight && cb.chessBoard[0][5].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][5].p == PieceType::Knight && cb.chessBoard[2][5].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[3][6].p == PieceType::Knight && cb.chessBoard[3][6].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
        else if (BlackKingPosY(cb) == 6) {
            if (cb.chessBoard[4][6].p == PieceType::Knight && cb.chessBoard[4][6].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][5].p == PieceType::Knight && cb.chessBoard[5][5].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[7][5].p == PieceType::Knight && cb.chessBoard[7][5].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
        else if (BlackKingPosY(cb) == 7) {
            if (cb.chessBoard[5][6].p == PieceType::Knight && cb.chessBoard[5][6].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[6][5].p == PieceType::Knight && cb.chessBoard[6][5].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
        else {
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].p == PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].p == PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].p == PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].p == PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
    } else if (BlackKingPosX(cb) == 6) {
        // y alternating, x is 6
        if (BlackKingPosY(cb) == 0) {
            if (cb.chessBoard[1][4].p == PieceType::Knight && cb.chessBoard[1][4].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][5].p == PieceType::Knight && cb.chessBoard[2][5].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][7].p == PieceType::Knight && cb.chessBoard[2][7].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 1) {
            if (cb.chessBoard[0][4].p == PieceType::Knight && cb.chessBoard[0][4].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][4].p == PieceType::Knight && cb.chessBoard[2][4].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[3][5].p == PieceType::Knight && cb.chessBoard[3][5].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[3][7].p == PieceType::Knight && cb.chessBoard[3][7].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 6) {
            if (cb.chessBoard[4][7].p == PieceType::Knight && cb.chessBoard[4][7].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[4][5].p == PieceType::Knight && cb.chessBoard[4][5].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][4].p == PieceType::Knight && cb.chessBoard[5][4].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[7][4].p == PieceType::Knight && cb.chessBoard[7][4].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 7) {
            if (cb.chessBoard[5][7].p == PieceType::Knight && cb.chessBoard[5][7].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][5].p == PieceType::Knight && cb.chessBoard[5][5].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[6][4].p == PieceType::Knight && cb.chessBoard[6][4].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else {
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
    } else if (BlackKingPosX(cb) == 1) {
        // y alternating, x is 1
        if (BlackKingPosY(cb) == 0) {
            if (cb.chessBoard[2][0].p == PieceType::Knight && cb.chessBoard[2][0].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][2].p == PieceType::Knight && cb.chessBoard[2][2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[1][3].p == PieceType::Knight && cb.chessBoard[1][3].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 1) {
            if (cb.chessBoard[3][0].p == PieceType::Knight && cb.chessBoard[3][0].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[3][2].p == PieceType::Knight && cb.chessBoard[3][2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][3].p == PieceType::Knight && cb.chessBoard[2][3].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[0][3].p == PieceType::Knight && cb.chessBoard[0][3].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 6) {
            if (cb.chessBoard[4][0].p == PieceType::Knight && cb.chessBoard[4][0].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[4][2].p == PieceType::Knight && cb.chessBoard[4][2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][3].p == PieceType::Knight && cb.chessBoard[5][3].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[7][3].p == PieceType::Knight && cb.chessBoard[7][3].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 7) {
            if (cb.chessBoard[5][0].p == PieceType::Knight && cb.chessBoard[5][0].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][2].p == PieceType::Knight && cb.chessBoard[5][2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[6][3].p == PieceType::Knight && cb.chessBoard[6][3].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else {
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
    } else if (BlackKingPosX(cb) == 0) {
        // y alternating, x is 0
        if (BlackKingPosY(cb) == 0) {
            if (cb.chessBoard[1][2].p == PieceType::Knight && cb.chessBoard[1][2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][1].p == PieceType::Knight && cb.chessBoard[2][1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 1) {
            if (cb.chessBoard[0][2].p == PieceType::Knight && cb.chessBoard[0][2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[2][2].p == PieceType::Knight && cb.chessBoard[2][2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[3][1].p == PieceType::Knight && cb.chessBoard[3][1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 6) {
            if (cb.chessBoard[4][1].p == PieceType::Knight && cb.chessBoard[4][1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[5][2].p == PieceType::Knight && cb.chessBoard[5][2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[7][2].p == PieceType::Knight && cb.chessBoard[7][2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 7) {
            if (cb.chessBoard[5][1].p == PieceType::Knight && cb.chessBoard[5][1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[6][2].p == PieceType::Knight && cb.chessBoard[6][2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else {
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
    } else {
        if (BlackKingPosY(cb) == 0) {
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 1) {
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 6) {
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else if (BlackKingPosY(cb) == 7) {
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        } else {
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) - 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) - 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 1][BlackKingPosX(cb) + 2].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) - 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
            if (cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].p ==  PieceType::Knight && cb.chessBoard[BlackKingPosY(cb) + 2][BlackKingPosX(cb) + 1].c == Colour::White) {
                Tile temp1 = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                Tile temp2 = {x2, y2, t1.c, t1.p};
                cb.chessBoard[8 - y1][x1 - 1] = temp2;
                cb.chessBoard[8 - y2][x2 - 1] = temp1;
                return true;
            }
        }
    } 
    return false;
}

bool IsLegal(Tile t1, Tile t2, ChessBoard &cb) {
    if (t1.alphabet > 8 || t2.alphabet > 8 || t1.num > 8 || t2.num > 8 || t1.alphabet < 1 || t2.alphabet < 1 || t1.num < 1 || t2.num < 1) {
        return false;
    }
    if (t1.p == PieceType::King) {
        if ((abs(t1.alphabet - t2.alphabet) == 1 && abs(t1.num - t2.num) == 1) || 
            (abs(t1.alphabet - t2.alphabet) == 0 && abs(t1.num - t2.num) == 1) || 
            (abs(t1.alphabet - t2.alphabet) == 1 && abs(t1.num - t2.num) == 0)){
            return true;
        }
        return false;
    } else if (t1.p  == PieceType::Queen) {
        if (t1.num == t2.num || t1.alphabet == t2.alphabet || abs((t1.num - t2.num)/(t1.alphabet - t2.alphabet)) == 1) {
            return true;
        }
        return false;
    } else if (t1.p  == PieceType::Castle) {
        if (t1.num == t2.num || t1.alphabet == t2.alphabet) {
            return true;
        }
        return false;
    } else if (t1.p  == PieceType::Bishop) {
        if (abs(t1.alphabet - t2.alphabet) == 0) {
            return false;
        } else if (abs((t1.num - t2.num)/(t1.alphabet - t2.alphabet)) == 1) {
            return true;
        }
        return false;
    } else if (t1.p  == PieceType::Knight) {
        if (abs(t1.alphabet - t2.alphabet) == 1 && abs(t1.num - t2.num) == 2) {
            return true;
        } else if (abs(t1.alphabet - t2.alphabet) == 2 && abs(t1.num - t2.num) == 1) {
            return true;
        } else {
            return false;
        }
    } else if (t1.p  == PieceType::Pawn) { 
        if (t1.c == Colour::White) {
            bool isFirstTurn;
            if (t1.num == 2) {
                isFirstTurn = true;
            } else {
                isFirstTurn = false;
            }
            if (t1.num < t2.num) {
                if (abs(t1.alphabet - t2.alphabet) == 0) {
                    if (abs(t1.num - t2.num) == 1) {
                        if (t2.p == PieceType::NoPiece) {
                            return true;
                        }
                        return false;
                    } else if (abs(t1.num - t2.num) == 2) {
                        if (cb.chessBoard[8 - t1.num - 1][t1.alphabet - 1].p == PieceType::NoPiece &&
                            cb.chessBoard[8 - t1.num - 2][t1.alphabet - 1].p == PieceType::NoPiece) {
                                if (isFirstTurn) {
                                    cb.hasPawnMovedTwice = true;
                                    return true;
                                } 
                                return false; 
                        }
                        return false;
                    }
                } else if (abs(t1.alphabet - t2.alphabet) == 1) {
                    if (abs(t1.num - t2.num) == 1) {
                        if (t2.p == PieceType::NoPiece) {
                            if (cb.chessBoard[8-t2.num+1][t2.alphabet-1].p == PieceType::Pawn && 
                                cb.chessBoard[8-t2.num+1][t2.alphabet-1].c == Colour::Black) {
                                    if (cb.hasPawnMovedTwice == true) {
                                        cb.hasPawnMovedTwice = false;
                                        Tile newT = {8-t2.num+1, t2.alphabet-1, Colour::NoColour, PieceType::NoPiece};
                                        cb.chessBoard[8-t2.num+1][t2.alphabet-1] = newT;
                                        return true;
                                    }
                                    return false;
                                }
                        }
                        if (t2.p != PieceType::NoPiece && t2.c != Colour::White) {
                            return true;
                        }
                        return false;
                    }
                }
            } else {
                return false;
            }
        } else {
            bool isFirstTurn;
            if (t1.num == 7) {
                isFirstTurn = true;
            } else {
                isFirstTurn = false;
            }
            if (t1.num > t2.num) {
                if (abs(t1.alphabet - t2.alphabet) == 0) {
                    if (abs(t1.num - t2.num) == 1) {
                        if (t2.p == PieceType::NoPiece) {
                            return true;
                        }
                        return false;
                    } else if (abs(t1.num - t2.num) == 2) {
                        if (cb.chessBoard[8 - t1.num + 1][t1.alphabet - 1].p == PieceType::NoPiece &&
                            cb.chessBoard[8 - t1.num + 2][t1.alphabet - 1].p == PieceType::NoPiece) {
                                if (isFirstTurn) {
                                    cb.hasPawnMovedTwice = true;
                                    return true;
                                }
                                return false;
                        }
                        return false;
                    }
                } else if (abs(t1.alphabet - t2.alphabet) == 1) {
                    if (abs(t1.num - t2.num) == 1) {
                        if (t2.p == PieceType::NoPiece) {
                            if (cb.chessBoard[8-t2.num-1][t2.alphabet-1].p == PieceType::Pawn && 
                                cb.chessBoard[8-t2.num-1][t2.alphabet-1].c == Colour::White) {
                                    if (cb.hasPawnMovedTwice == true) {
                                        cb.hasPawnMovedTwice = false;
                                        Tile newT = {8-t2.num-1, t2.alphabet-1, Colour::NoColour, PieceType::NoPiece};
                                        cb.chessBoard[8-t2.num-1][t2.alphabet-1] = newT;
                                        return true;
                                    }
                                    return false;
                                }
                        }
                        if (t2.p != PieceType::NoPiece && t2.c != Colour::Black) {
                            return true;
                        }
                        return false;
                    }
                }
            } else {
                return false;
            }
        }
    } 
}

bool IsValid(Tile t1, Tile t2, ChessBoard &cb) {
    if (t1.p == PieceType::King) {
        if (t2.c != t1.c) {
            return true;
        }
        return false;
    } else if (t1.p == PieceType::Queen) {
        // diagnonal
        if (t1.num < t2.num && t1.alphabet < t2.alphabet) {
            for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                    if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1+i+1].c == t1.c) {
                        return false;
                    }
                    return true;
                }
                if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1+i+1].p != PieceType::NoPiece) {
                    return false;
                }
            }
        } else if (t1.num < t2.num && t1.alphabet > t2.alphabet) {
            for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                    if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1-i-1].c == t1.c) {
                        return false;
                    }
                    return true;
                }
                if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1-i-1].p != PieceType::NoPiece) {
                    return false;
                }
            }
        } else if (t1.num > t2.num && t1.alphabet < t2.alphabet) {
            for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                    if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1+i+1].c == t1.c) {
                        return false;
                    }
                    return true;
                }
                if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1+i+1].p != PieceType::NoPiece) {
                    return false;
                }
            }
        } else if (t1.num > t2.num && t1.alphabet > t2.alphabet) {
            for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                    if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1-i-1].c == t1.c) {
                        return false;
                    }
                    return true;
                }
                if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1-i-1].p != PieceType::NoPiece) {
                    return false;
                }
            }
        } 
        // vertical
        // horizontal
        if (t1.alphabet == t2.alphabet) {
            if (t1.num < t2.num) {
                for (int i = 0; i < abs(t2.num - t1.num); ++i) {
                    if (i == abs(t2.num - t1.num) - 1) {
                        if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1].c == t1.c) {
                            return false;
                        }
                        return true;
                    }
                    if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1].p != PieceType::NoPiece) {
                        return false;
                    }
                }
            } else if (t1.num > t2.num) {
                for (int i = 0; i < abs(t2.num - t1.num); ++i) {
                    if (i == abs(t2.num - t1.num) - 1) {
                        if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1].c == t1.c) {
                            return false;
                        }
                        return true;
                    }
                    if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1].p != PieceType::NoPiece) {
                        return false;
                    }
                }
            } 
        } else if (t1.num == t2.num) {
            if (t1.alphabet < t2.alphabet) {
                for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                    if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                        if (cb.chessBoard[8-t1.num][t1.alphabet-1+i+1].c == t1.c) {
                            return false;
                        }
                        return true;
                    }
                    if (cb.chessBoard[8-t1.num][t1.alphabet-1+i+1].p != PieceType::NoPiece) {
                        return false;
                    }
                }
            } else if (t1.alphabet > t2.alphabet) {
                for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                    if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                        if (cb.chessBoard[8-t1.num][t1.alphabet-1-i-1].c == t1.c) {
                            return false;
                        }
                        return true;
                    }
                    if (cb.chessBoard[8-t1.num][t1.alphabet-1-i-1].p != PieceType::NoPiece) {
                        return false;
                    }
                }
            } 
        }
    } else if (t1.p == PieceType::Bishop) {
        if (t1.num < t2.num && t1.alphabet < t2.alphabet) {
            for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                    if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1+i+1].c == t1.c) {
                        return false;
                    }
                    return true;
                }
                if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1+i+1].p != PieceType::NoPiece) {
                    return false;
                }
            }
        } else if (t1.num < t2.num && t1.alphabet > t2.alphabet) {
            for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                    if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1-i-1].c == t1.c) {
                        return false;
                    }
                    return true;
                }
                if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1-i-1].p != PieceType::NoPiece) {
                    return false;
                }
            }
        } else if (t1.num > t2.num && t1.alphabet < t2.alphabet) {
            for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                    if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1+i+1].c == t1.c) {
                        return false;
                    }
                    return true;
                }
                if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1+i+1].p != PieceType::NoPiece) {
                    return false;
                }
            }
        } else if (t1.num > t2.num && t1.alphabet > t2.alphabet) {
            for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                    if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1-i-1].c == t1.c) {
                        return false;
                    }
                    return true;
                }
                if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1-i-1].p != PieceType::NoPiece) {
                    return false;
                }
            }
        } 
    } else if (t1.p == PieceType::Knight) {
        if (t2.c != t1.c) {
            return true;
        }
        return false;
    } else if (t1.p == PieceType::Castle) {
        if (t1.alphabet == t2.alphabet) {
            if (t1.num < t2.num) {
                for (int i = 0; i < abs(t2.num - t1.num); ++i) {
                    if (i == abs(t2.num - t1.num) - 1) {
                        if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1].c == t1.c) {
                            return false;
                        }
                        return true;
                    }
                    if (cb.chessBoard[8-t1.num-i-1][t1.alphabet-1].p != PieceType::NoPiece) {
                        return false;
                    }
                }
            } else if (t1.num > t2.num) {
                for (int i = 0; i < abs(t2.num - t1.num); ++i) {
                    if (i == abs(t2.num - t1.num) - 1) {
                        if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1].c == t1.c) {
                            return false;
                        }
                        return true;
                    }
                    if (cb.chessBoard[8-t1.num+i+1][t1.alphabet-1].p != PieceType::NoPiece) {
                        return false;
                    }
                }
            } 
        } else if (t1.num == t2.num) {
            if (t1.alphabet < t2.alphabet) {
                for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                    if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                        if (cb.chessBoard[8-t1.num][t1.alphabet-1+i+1].c == t1.c) {
                            return false;
                        }
                        return true;
                    }
                    if (cb.chessBoard[8-t1.num][t1.alphabet-1+i+1].p != PieceType::NoPiece) {
                        return false;
                    }
                }
            } else if (t1.alphabet > t2.alphabet) {
                for (int i = 0; i < abs(t2.alphabet - t1.alphabet); ++i) {
                    if (i == abs(t2.alphabet - t1.alphabet) - 1) {
                        if (cb.chessBoard[8-t1.num][t1.alphabet-1-i-1].c == t1.c) {
                            return false;
                        }
                        return true;
                    }
                    if (cb.chessBoard[8-t1.num][t1.alphabet-1-i-1].p != PieceType::NoPiece) {
                        return false;
                    }
                }
            } 
        }
    } else if (t1.p == PieceType::Pawn) {
        if (t2.c != t1.c) {
            return true;
        }
        return false;
    }
}

