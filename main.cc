#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
#include <exception>
#include "human.h"
#include "computer.h"
#include "chessboard.h"

using namespace std;

PieceType whichPiece(string s) {
    if (s == "K") {
        return PieceType::King;
    } else if (s == "Q") {
        return PieceType::Queen;
    } else if (s == "P") {
        return PieceType::Pawn;
    } else if (s == "R") {
        return PieceType::Castle;
    } else if (s == "N") {
        return PieceType::Knight;
    } else if (s == "B") {
        return PieceType::Bishop;
    } else if (s == "k") {
        return PieceType::King;
    } else if (s == "q") {
        return PieceType::Queen;
    } else if (s == "p") {
        return PieceType::Pawn;
    } else if (s == "r") {
        return PieceType::Castle;
    } else if (s == "n") {
        return PieceType::Knight;
    } else if (s == "b") {
        return PieceType::Bishop;
    } else {
        return PieceType::NoPiece;
    }
}

Colour whichColour(string s) {
    if (s == "K") {
        return Colour::White;
    } else if (s == "Q") {
        return Colour::White;
    } else if (s == "P") {
        return Colour::White;
    } else if (s == "R") {
        return Colour::White;
    } else if (s == "N") {
        return Colour::White;
    } else if (s == "B") {
        return Colour::White;
    } else if (s == "k") {
        return Colour::Black;
    } else if (s == "q") {
        return Colour::Black;
    } else if (s == "p") {
        return Colour::Black;
    } else if (s == "r") {
        return Colour::Black;
    } else if (s == "n") {
        return Colour::Black;
    } else if (s == "b") {
        return Colour::Black;
    } else {
        return Colour::NoColour;
    }
}

Colour whichTurn(int alphabet, int num, ChessBoard &cb) {
    if (cb.chessBoard[8-num][alphabet-1].c == Colour::White) {
        return Colour::White;
    }
    return Colour::Black;
}

string isCastling(string s1, string s2, ChessBoard &cb) {
    if (cb.getX(s1[0]) == 5 && cb.getY(s1[1]) == 1 && cb.getX(s2[0]) == 7 && cb.getY(s2[1]) == 1) { // White right
        if (cb.castlingWhiteAllowedRight) {
                return "wr";
        }
        return "no";   
    } else if (cb.getX(s1[0]) == 5 && cb.getY(s1[1]) == 1 && cb.getX(s2[0]) == 3 && cb.getY(s2[1]) == 1) { // White left
        if (cb.castlingWhiteAllowedLeft) {
            return "wl";
        }
        return "no";
    } else if (cb.getX(s1[0]) == 5 && cb.getY(s1[1]) == 8 && cb.getX(s2[0]) == 7 && cb.getY(s2[1]) == 8) { // Black right
        if (cb.castlingBlackAllowedRight) {
            return "br";
        }
        return "no";
    } else if (cb.getX(s1[0]) == 5 && cb.getY(s1[1]) == 8 && cb.getX(s2[0]) == 3 && cb.getY(s2[1]) == 8) { // Black left
        if (cb.castlingBlackAllowedLeft) {
            return "bl";
        }
        return "no";
    } else {
        return "no";
    }
}

bool isCastlingLegal(string s, ChessBoard &cb) {
    if (s == "wr") {
        if (cb.chessBoard[7][4].p == PieceType::King && cb.chessBoard[7][4].c == Colour::White &&
            cb.chessBoard[7][5].p == PieceType::NoPiece && cb.chessBoard[7][6].p == PieceType::NoPiece &&
            cb.chessBoard[7][7].p == PieceType::Castle && cb.chessBoard[7][7].c == Colour::White) {
                return true;
            }
            return false;
    } else if (s == "wl") {
        if (cb.chessBoard[7][4].p == PieceType::King && cb.chessBoard[7][4].c == Colour::White &&
            cb.chessBoard[7][3].p == PieceType::NoPiece && cb.chessBoard[7][2].p == PieceType::NoPiece && cb.chessBoard[7][1].p == PieceType::NoPiece &&
            cb.chessBoard[7][0].p == PieceType::Castle && cb.chessBoard[7][0].c == Colour::White) {
                return true;
            }
            return false;
    } else if (s == "br") {
        if (cb.chessBoard[0][4].p == PieceType::King && cb.chessBoard[0][4].c == Colour::Black &&
            cb.chessBoard[0][5].p == PieceType::NoPiece && cb.chessBoard[0][6].p == PieceType::NoPiece &&
            cb.chessBoard[0][7].p == PieceType::Castle && cb.chessBoard[0][7].c == Colour::Black) {
                return true;
            }
            return false;
    } else if (s == "bl") {
        if (cb.chessBoard[0][4].p == PieceType::King && cb.chessBoard[0][4].c == Colour::Black &&
            cb.chessBoard[0][3].p == PieceType::NoPiece && cb.chessBoard[0][2].p == PieceType::NoPiece && cb.chessBoard[7][1].p == PieceType::NoPiece &&
            cb.chessBoard[0][0].p == PieceType::Castle && cb.chessBoard[0][0].c == Colour::Black) {
                return true;
            }
            return false;
    } else {
        return false;
    }
}

void move(ChessBoard &cb, int x1, int y1, int x2, int y2, Colour wT, Tile tile1, Tile tile2, bool &isWhiteTurn, vector <string> &inputVector, bool isCompPlaying) {
    string castTest = isCastling(inputVector[1], inputVector[2], cb);
                if (isCastlingLegal(castTest, cb)) {
                    // change chessboard
                    if (isWhiteTurn && cb.isWhiteCheck(cb, tile1, tile2, inputVector)) {
                        cout << "Invalid move! White will be in check!" << endl;
                        cout << cb;;
                        inputVector.clear();
                        if (isCompPlaying) {
                            throw std::exception();
                        }
                        return;
                    } else if (!isWhiteTurn && cb.isBlackCheck(cb, tile1, tile2, inputVector)) {
                        cout << "Invalid move! Black will be in check!" << endl;
                        cout << cb;;
                        inputVector.clear();
                        if (isCompPlaying) {
                            throw std::exception();
                        }
                        return;
                    }
                    Tile t1;
                    Tile t2;
                    Tile t3;
                    Tile t4;
                    if (castTest == "wr") {
                        t1 = {5, 1, Colour::NoColour, PieceType::NoPiece};
                        t2 = {8, 1, Colour::NoColour, PieceType::NoPiece};
                        t3 = {6, 1, Colour::White, PieceType::Castle};
                        t4 = {7, 1, Colour::White, PieceType::King};
                        cb.chessBoard[7][4] = t1;
                        cb.chessBoard[7][7] = t2;
                        cb.chessBoard[7][5] = t3;
                        cb.chessBoard[7][6] = t4;
                        cb.castlingWhiteAllowedRight = false;
                    } else if (castTest == "wl") {
                        t1 = {5, 1, Colour::NoColour, PieceType::NoPiece};
                        t2 = {1, 1, Colour::NoColour, PieceType::NoPiece};
                        t3 = {4, 1, Colour::White, PieceType::Castle};
                        t4 = {3, 1, Colour::White, PieceType::King};
                        cb.chessBoard[7][4] = t1;
                        cb.chessBoard[7][0] = t2;
                        cb.chessBoard[7][3] = t3;
                        cb.chessBoard[7][2] = t4;
                        cb.castlingWhiteAllowedLeft = false;
                    } else if (castTest == "br") {
                        t1 = {5, 8, Colour::NoColour, PieceType::NoPiece};
                        t2 = {8, 8, Colour::NoColour, PieceType::NoPiece};
                        t3 = {6, 8, Colour::Black, PieceType::Castle};
                        t4 = {7, 8, Colour::Black, PieceType::King};
                        cb.chessBoard[0][4] = t1;
                        cb.chessBoard[0][7] = t2;
                        cb.chessBoard[0][5] = t3;
                        cb.chessBoard[0][6] = t4;
                        cb.castlingBlackAllowedRight = false;
                    } else if (castTest == "bl") {
                        t1 = {5, 8, Colour::NoColour, PieceType::NoPiece};
                        t2 = {1, 8, Colour::NoColour, PieceType::NoPiece};
                        t3 = {4, 8, Colour::Black, PieceType::Castle};
                        t4 = {3, 8, Colour::Black, PieceType::King};
                        cb.chessBoard[0][4] = t1;
                        cb.chessBoard[0][0] = t2;
                        cb.chessBoard[0][3] = t3;
                        cb.chessBoard[0][2] = t4;
                        cb.castlingBlackAllowedLeft = false;;
                    }
                    if (!isCompPlaying) {
                        if (isWhiteTurn == true) {
                            isWhiteTurn = false;
                        } else if (isWhiteTurn == false) {
                            isWhiteTurn = true;
                        }
                    }
                    cout << cb;
                    inputVector.clear();
                    return;
                } 
                if (IsLegal(tile1, tile2, cb)) {
                    if (IsValid(tile1, tile2, cb)) {
                        if (isWhiteTurn && cb.isWhiteCheck(cb, tile1, tile2, inputVector)) {
                            cout << "Invalid move! White will be in check!" << endl;
                            cout << cb;;
                            inputVector.clear();
                            if (isCompPlaying) {
                            throw std::exception();
                            }
                            return;
                        } else if (!isWhiteTurn && cb.isBlackCheck(cb, tile1, tile2, inputVector)) {
                            cout << "Invalid move! Black will be in check!" << endl;
                            cout << cb;;
                            inputVector.clear();
                            if (isCompPlaying) {
                            throw std::exception();
                            }
                            return;
                        }
                        for (int i = 0; i < 8; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                // Check for castling condition
                                if (tile1.p == PieceType::King && tile1.c == Colour::White) {
                                    cb.castlingWhiteAllowedLeft = false;
                                    cb.castlingWhiteAllowedRight = false;
                                } else if (tile1.p == PieceType::King && tile1.c == Colour::Black) {
                                    cb.castlingBlackAllowedRight = false;
                                    cb.castlingBlackAllowedLeft = false;
                                } else if (tile1.p == PieceType::Castle && tile1.c == Colour::White && tile1.num == 1 && tile1.alphabet == 1) {
                                    cb.castlingWhiteAllowedLeft = false;
                                } else if (tile1.p == PieceType::Castle && tile1.c == Colour::White && tile1.num == 1 && tile1.alphabet == 8) {
                                    cb.castlingWhiteAllowedRight = false;
                                } else if (tile1.p == PieceType::Castle && tile1.c == Colour::Black && tile1.num == 8 && tile1.alphabet == 1) {
                                    cb.castlingBlackAllowedLeft = false;
                                } else if (tile1.p == PieceType::Castle && tile1.c == Colour::Black && tile1.num == 8 && tile1.alphabet == 8) {
                                    cb.castlingBlackAllowedRight = false;
                                }
                                if (i == 8 - y1 && j == x1 - 1) {
                                    Tile newT = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                                    cb.chessBoard[i][j] = newT;
                                }
                                if (i == 8 - y2 && j == x2 - 1) {
                                    Tile newT = {x2, y2, tile1.c, tile1.p};
                                    cb.chessBoard[i][j] = newT;
                                } 
                            }
                        }
                        /*(if (!cb.isWhiteStalemate(cb.WhiteKingPosY(cb), cb.WhiteKingPosX(cb), cb, inputVector)) {
                            cout << "STALEMATE! GAME OVER! DRAW!" << endl;
                            cb.ISSTALEMATE = true;
                            return;
                        }*/
                        // Change turns
                        if (isWhiteTurn == true) {
                            isWhiteTurn = false;
                        } else if (isWhiteTurn == false) {
                            isWhiteTurn = true;
                        }
                    } else {
                        cout << "Invalid move! Please enter command again!" << endl;
                        inputVector.clear();
                        if (isCompPlaying) {
                            throw std::exception();
                        }
                        return;
                    }
                    if (isWhiteTurn && cb.isWhiteCheck(cb, tile1, tile2, inputVector)) {
                        for (int i = 0; i < 8; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (i == 8 - y1 && j == x1 - 1) {
                                    Tile newT = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                                    cb.chessBoard[i][j] = newT;
                                }
                                if (i == 8 - y2 && j == x2 - 1) {
                                    Tile newT = {x2, y2, tile1.c, tile1.p};
                                    cb.chessBoard[i][j] = newT;
                                } 
                            }
                        }
                        cout << "White is in check!" << endl;
                    }
                    else if (!isWhiteTurn && cb.isBlackCheck(cb, tile1, tile2, inputVector)) {
                        for (int i = 0; i < 8; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (i == 8 - y1 && j == x1 - 1) {
                                    Tile newT = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                                    cb.chessBoard[i][j] = newT;
                                }
                                if (i == 8 - y2 && j == x2 - 1) {
                                    Tile newT = {x2, y2, tile1.c, tile1.p};
                                    cb.chessBoard[i][j] = newT;
                                } 
                            }
                        }
                        cout << "Black is in check!" << endl;
                    } 
                    cout << cb;
                    inputVector.clear();
                    return;
                } else {
                    cout << "Invalid move! Please enter command again!" << endl;
                    inputVector.clear();
                    if (isCompPlaying) {
                            throw std::exception();
                        }
                    return;
                }
}

void findAndMoveLevels(ChessBoard &cb, int i, int j, Colour colour, PieceType p, vector <string> &inputVector) {
    Tile startingTile = {j + 1, 8 - i, colour, p};
    bool moved = false;
    // Vertical up
    for (int pos = 0; pos < i; ++pos) {
        if (cb.chessBoard[i - pos - 1][j].p == PieceType::NoPiece) {
            Tile destinationTile = {j + 1, 8 - (i - pos - 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && 
                IsValid(startingTile, destinationTile, cb) 
                /*!cb.isWhiteCheck(cb, startingTile, destinationTile, inputVector)*/) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        } else {
            Tile destinationTile = {j + 1, 8 - (i - pos - 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && 
                IsValid(startingTile, destinationTile, cb) 
                /*!cb.isWhiteCheck(cb, startingTile, destinationTile, inputVector)*/) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Vertical down
    for (int pos = 0; pos < 8 - i - 1; ++pos) {
        if (cb.chessBoard[i + pos + 1][j].p == PieceType::NoPiece) {
            Tile destinationTile = {j + 1, 8 - (i + pos + 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        } else {
            Tile destinationTile = {j + 1, 8 - (i + pos + 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Horizontal right
    for (int pos = 0; pos < 8 - j - 1; ++pos){
        if (cb.chessBoard[i][j + pos + 1].p == PieceType::NoPiece) {
            Tile destinationTile = {pos + 2, 8 - i, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        } else {
            Tile destinationTile = {pos + 2, 8 - i, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Horizontal left
    for (int pos = 0; pos < j; ++pos){
        if (cb.chessBoard[i][j - pos - 1].p == PieceType::NoPiece) {
            Tile destinationTile = {8 - pos - 1, 8 - i, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        } else {
            Tile destinationTile = {8 - pos - 1, 8 - i, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Diagonal Up Right
    for (int pos = 0; pos < min(i, 8 - j - 1); ++pos){
        if (cb.chessBoard[i - pos - 1][j + pos + 1].p == PieceType::NoPiece) {
            Tile destinationTile = {startingTile.alphabet + pos + 1, 8 - (i - pos - 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        } else {
            Tile destinationTile = {startingTile.alphabet + pos + 1, 8 - (i - pos - 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Diagonal Down Right
    for (int pos = 0; pos < min(8 - i - 1, 8 - j - 1); ++pos){
        if (cb.chessBoard[i + pos + 1][j + pos + 1].p == PieceType::NoPiece) {
            Tile destinationTile = {startingTile.alphabet+ 1, 8 - i - 1, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        } else {
            Tile destinationTile = {startingTile.alphabet+ 1, 8 - i - 1, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Diagonal Down Left
    for (int pos = 0; pos < min(8 - i - 1, j); ++pos){
        if (cb.chessBoard[i + pos + 1][j - pos - 1].p == PieceType::NoPiece) {
            Tile destinationTile = {8 - pos - 1, 8 - i - 1, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        } else {
            Tile destinationTile = {8 - pos - 1, 8 - i - 1, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Diagonal Up Left
    for (int pos = 0; pos < min(i, j); ++pos){
        if (cb.chessBoard[i - pos - 1][j - pos - 1].p == PieceType::NoPiece) {
            Tile destinationTile = {8 - pos - 1, 8 - (i - pos - 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        } else {
            Tile destinationTile = {8 - pos - 1, 8 - (i - pos - 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) {
        return;
    } else {
        throw std::exception();
    }
}

void findAndMove(ChessBoard &cb, int i, int j, Colour colour, PieceType p, vector <string> &inputVector) {
    Tile startingTile = {j + 1, 8 - i, colour, p};
    bool moved = false;
    // Vertical up
    for (int pos = 0; pos < i; ++pos) {
        if (cb.chessBoard[i - pos - 1][j].p == PieceType::NoPiece) {
            Tile destinationTile = {j + 1, 8 - (i - pos - 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && 
                IsValid(startingTile, destinationTile, cb) 
                /*!cb.isWhiteCheck(cb, startingTile, destinationTile, inputVector)*/) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Vertical down
    for (int pos = 0; pos < 8 - i - 1; ++pos) {
        if (cb.chessBoard[i + pos + 1][j].p == PieceType::NoPiece) {
            Tile destinationTile = {j + 1, 8 - (i + pos + 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Horizontal right
    for (int pos = 0; pos < 8 - j - 1; ++pos){
        if (cb.chessBoard[i][j + pos + 1].p == PieceType::NoPiece) {
            Tile destinationTile = {pos + 2, 8 - i, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Horizontal left
    for (int pos = 0; pos < j; ++pos){
        if (cb.chessBoard[i][j - pos - 1].p == PieceType::NoPiece) {
            Tile destinationTile = {8 - pos - 1, 8 - i, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Diagonal Up Right
    for (int pos = 0; pos < min(i, 8 - j - 1); ++pos){
        if (cb.chessBoard[i - pos - 1][j + pos + 1].p == PieceType::NoPiece) {
            Tile destinationTile = {startingTile.alphabet + pos + 1, 8 - (i - pos - 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Diagonal Down Right
    for (int pos = 0; pos < min(8 - i - 1, 8 - j - 1); ++pos){
        if (cb.chessBoard[i + pos + 1][j + pos + 1].p == PieceType::NoPiece) {
            Tile destinationTile = {startingTile.alphabet+ 1, 8 - i - 1, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Diagonal Down Left
    for (int pos = 0; pos < min(8 - i - 1, j); ++pos){
        if (cb.chessBoard[i + pos + 1][j - pos - 1].p == PieceType::NoPiece) {
            Tile destinationTile = {8 - pos - 1, 8 - i - 1, Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) return;
    // Diagonal Up Left
    for (int pos = 0; pos < min(i, j); ++pos){
        if (cb.chessBoard[i - pos - 1][j - pos - 1].p == PieceType::NoPiece) {
            Tile destinationTile = {8 - pos - 1, 8 - (i - pos - 1), Colour::NoColour, PieceType::NoPiece};
            if (IsLegal(startingTile, destinationTile, cb) && IsValid(startingTile, destinationTile, cb)) {
                cb.chessBoard[8 - destinationTile.num][destinationTile.alphabet - 1] = startingTile;
                cb.chessBoard[i][j] = destinationTile;
                cout << cb;
                moved = true;
                break;
            }
        }
        break;
    }
    if (moved == true) {
        return;
    } else {
        throw std::exception();
    }
}

void playWithComputer(ChessBoard &cb, string colour, int cLevel1, int cLevel2, bool areBothcomp, vector <string> &inputVector) {
    bool isWhiteTurn;
    string input;
    int turn = 1;
    bool foundPiece = false;
    if (areBothcomp) {
        vector <randInfo> whitePieces;
        vector <randInfo> blackPieces;
        if (colour == "white") {
            while (true) {
                if (turn % 2 != 0) {
                    if (cLevel1 == 1) {
                        for (int i = 0; i < 8; ++i) {
                            try {
                                for (int j = 0; j < 8; ++j) {
                                    if (j == 8 - 1) throw std::exception();
                                        try {
                                            if (cb.chessBoard[i][j].c == Colour::White) {
                                                foundPiece = true;
                                                findAndMove(cb, i, j, Colour::White, cb.chessBoard[i][j].p, inputVector);
                                                break;
                                            }
                                        } catch (std::exception &e) {
                                            continue;
                                        }
                                    }
                                } catch (std::exception &e){
                                    continue;
                                }
                            if (foundPiece) {
                                foundPiece = false;
                                break;
                            }
                        }
                    } else if (cLevel1 == 2) {
                        whitePieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::White) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    whitePieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn;
                                if (whitePieces.size() != 1) {
                                    rn = rand() % (whitePieces.size() - 1);
                                } else {
                                    rn = 0;
                                }
                                randInfo TrialPieceToMove = whitePieces[rn];
                                findAndMove(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::White, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    } else if (cLevel1 == 3) {
                        whitePieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::White) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    whitePieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn;
                                if (whitePieces.size() != 1) {
                                    rn = rand() % (whitePieces.size() - 1);
                                } else {
                                    rn = 0;
                                }
                                randInfo TrialPieceToMove = whitePieces[rn];
                                findAndMoveLevels(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::White, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    } else if (cLevel1 == 4) {
                        whitePieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::White) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    whitePieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn;
                                if (whitePieces.size() != 1) {
                                    rn = rand() % (whitePieces.size() - 1);
                                } else {
                                    rn = 0;
                                }
                                randInfo TrialPieceToMove = whitePieces[rn];
                                findAndMoveLevels(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::White, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    }
                } else {
                    if (cLevel2 == 1) {
                        for (int i = 0; i < 8; ++i) {
                            try {
                                for (int j = 0; j < 8; ++j) {
                                    if (j == 8 - 1) throw std::exception();
                                        try {
                                            if (cb.chessBoard[i][j].c == Colour::Black) {
                                                foundPiece = true;
                                                findAndMove(cb, i, j, Colour::Black, cb.chessBoard[i][j].p, inputVector);
                                                break;
                                            }
                                        } catch (std::exception &e) {
                                            continue;
                                        }
                                    }
                                } catch (std::exception &e){
                                    continue;
                                }
                            if (foundPiece) {
                                foundPiece = false;
                                break;
                            }
                        }
                    } else if (cLevel2 == 2) {
                        blackPieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::Black) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    blackPieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn;
                                if (blackPieces.size() != 1) {
                                    rn = rand() % (blackPieces.size() - 1);
                                } else {
                                    rn = 0;
                                }
                                randInfo TrialPieceToMove = blackPieces[rn];
                                findAndMove(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::Black, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    } else if (cLevel2 == 3) {
                        blackPieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::Black) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    blackPieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn;
                                if (blackPieces.size() != 1) {
                                    rn = rand() % (blackPieces.size() - 1);
                                } else {
                                    rn = 0;
                                }
                                randInfo TrialPieceToMove = blackPieces[rn];
                                findAndMoveLevels(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::Black, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    } else if (cLevel2 == 4) {
                        blackPieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::Black) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    blackPieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn;
                                if (blackPieces.size() != 1) {
                                    rn = rand() % (blackPieces.size() - 1);
                                } else {
                                    rn = 0;
                                }
                                randInfo TrialPieceToMove = blackPieces[rn];
                                findAndMoveLevels(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::Black, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    }
                }
                turn += 1;
            }
        } else {
            
        }
    } else {
        if (colour == "white") {
            //isWhiteTurn = false;
            vector <randInfo> whitePieces;
            int turn = 1;
            while (true) {
                if (turn % 2 != 0) {
                    if (cLevel1 == 1) {
                        for (int i = 0; i < 8; ++i) {
                            try {
                                for (int j = 0; j < 8; ++j) {
                                    if (j == 8 - 1) throw std::exception();
                                        try {
                                            if (cb.chessBoard[i][j].c == Colour::White) {
                                                foundPiece = true;
                                                findAndMove(cb, i, j, Colour::White, cb.chessBoard[i][j].p, inputVector);
                                                break;
                                            }
                                        } catch (std::exception &e) {
                                            continue;
                                        }
                                    }
                                } catch (std::exception &e){
                                    continue;
                                }
                            if (foundPiece) {
                                foundPiece = false;
                                break;
                            }
                        }
                    } else if (cLevel1 == 2) {
                        whitePieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::White) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    whitePieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn = rand() % (whitePieces.size() - 1);
                                randInfo TrialPieceToMove = whitePieces[rn];
                                findAndMove(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::White, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    } else if (cLevel1 == 3) {
                        whitePieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::White) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    whitePieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn = rand() % (whitePieces.size() - 1);
                                randInfo TrialPieceToMove = whitePieces[rn];
                                findAndMoveLevels(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::White, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    } else if (cLevel2 == 4) {
                        whitePieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::White) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    whitePieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn = rand() % (whitePieces.size() - 1);
                                randInfo TrialPieceToMove = whitePieces[rn];
                                findAndMoveLevels(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::White, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    }
                } else {
                    getline(cin, input);
                    istringstream ss(input);
                    string word;
                    while (ss >> word) {
                        inputVector.emplace_back(word);
                    }
                    if (inputVector[0] != "move") {
                        cout << "Invalid input!" << endl;
                        inputVector.clear();
                        continue;
                    }
                    int x1 = cb.getX(inputVector[1][0]);
                    int y1 = cb.getY(inputVector[1][1]);
                    int x2 = cb.getX(inputVector[2][0]);
                    int y2 = cb.getY(inputVector[2][1]);
                    Colour wT = whichTurn(x1, y1, cb);
                    Tile tile1;
                    Tile tile2;
                    for (int i = 0; i < 8; ++i) {
                        for (int j = 0; j < 8; ++j) {
                            if (i == 8 - y1 && j == x1 - 1) {
                                tile1 = {x1, y1, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                            }
                            if (i == 8 - y2 && j == x2 - 1) {
                                tile2 = {x2, y2, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                            }
                        }
                    }
                    try {
                        move(cb, x1, y1, x2, y2, wT, tile1, tile2, isWhiteTurn, inputVector, true);
                    } catch(std::exception& e) {
                        continue;
                    }
                }
                turn += 1;
            }
        } else {
            //isWhiteTurn = false;
            int turn = 0;
            vector <randInfo> blackPieces;
            while (true) {
                if (turn % 2 != 0) {
                    if (cLevel2 == 1) {
                        for (int i = 0; i < 8; ++i) {
                            try {
                                for (int j = 0; j < 8; ++j) {
                                    if (j == 8 - 1) throw std::exception();
                                        try {
                                            if (cb.chessBoard[i][j].c == Colour::Black) {
                                                foundPiece = true;
                                                findAndMove(cb, i, j, Colour::Black, cb.chessBoard[i][j].p, inputVector);
                                                break;
                                            }
                                        } catch (std::exception &e) {
                                            continue;
                                        }
                                    }
                                } catch (std::exception &e){
                                    continue;
                                }
                            if (foundPiece) {
                                foundPiece = false;
                                break;
                            }
                        }
                    } else if (cLevel2 == 2) {
                        blackPieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::Black) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    blackPieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn;
                                if (blackPieces.size() != 1) {
                                    rn = rand() % (blackPieces.size() - 1);
                                } else {
                                    rn = 0;
                                }
                                randInfo TrialPieceToMove = blackPieces[rn];
                                findAndMove(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::Black, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    } else if (cLevel2 == 3) {
                        blackPieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::Black) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    blackPieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn = rand() % (blackPieces.size() - 1);
                                randInfo TrialPieceToMove = blackPieces[rn];
                                findAndMoveLevels(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::Black, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    } else if (cLevel2 == 4) {
                        blackPieces.clear();
                        for (int i = 0; i < 8; ++ i) {
                            for (int j = 0; j < 8; ++j) {
                                if (cb.chessBoard[i][j].c == Colour::Black) {
                                    randInfo ri = {i, j, cb.chessBoard[i][j].p};
                                    blackPieces.emplace_back(ri);
                                }
                            }
                        }
                        bool hasItBeenFoundYet = false;
                        while (!hasItBeenFoundYet) {
                            try {
                                int rn = rand() % (blackPieces.size() - 1);
                                randInfo TrialPieceToMove = blackPieces[rn];
                                findAndMoveLevels(cb, TrialPieceToMove.i, TrialPieceToMove.j, Colour::Black, TrialPieceToMove.p, inputVector);
                                hasItBeenFoundYet = true;
                                if (foundPiece) {
                                    foundPiece = false;
                                }
                            } catch (std::exception &e) {
                                continue;
                            }
                        }
                    }
                } else {
                    getline(cin, input);
                    istringstream ss(input);
                    string word;
                    while (ss >> word) {
                        inputVector.emplace_back(word);
                    }
                    if (inputVector[0] != "move") {
                        cout << "Invalid input!" << endl;
                        inputVector.clear();
                        continue;
                    }
                    int x1 = cb.getX(inputVector[1][0]);
                    int y1 = cb.getY(inputVector[1][1]);
                    int x2 = cb.getX(inputVector[2][0]);
                    int y2 = cb.getY(inputVector[2][1]);
                    Tile tile1;
                    Tile tile2;
                    Colour wT = whichTurn(x1, y1, cb);
                    if (inputVector.size() == 3) {
                        for (int i = 0; i < 8; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (i == 8 - y1 && j == x1 - 1) {
                                    tile1 = {x1, y1, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                                }
                                if (i == 8 - y2 && j == x2 - 1) {
                                    tile2 = {x2, y2, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                                }
                            }
                        }
                        try {
                            move(cb, x1, y1, x2, y2, wT, tile1, tile2, isWhiteTurn, inputVector, true);
                        } catch(std::exception& e) {
                            continue;
                        }
                    } else {
                        PieceType pPiece = whichPiece(inputVector[3]);
                        if (pPiece == PieceType::Pawn || pPiece == PieceType::King) {
                            cout << "Invalid input! Promotion piece can be either of Rook, Knight, Bishop or Queen!" << endl;
                            inputVector.clear();
                            return;
                        }
                        Colour pColour = whichColour(inputVector[3]);
                        if (isWhiteTurn && pColour != Colour::White) {
                            cout << "Invalid input! It is White's turn! Promotion piece must be White!" << endl;
                            inputVector.clear();
                            return;
                        } else if (!isWhiteTurn && pColour != Colour::Black) {
                            cout << "Invalid input! It is Black's turn! Promotion piece must be Black" << endl;
                            inputVector.clear();
                            return;
                        }
                        if (isWhiteTurn && whichTurn(x1, y1, cb) != Colour::White) {
                            cout << "Invalid input! It is White's turn!" << endl;
                            inputVector.clear();
                            return;
                        } else if (!isWhiteTurn && whichTurn(x1, y1, cb) != Colour::Black) {
                            cout << "Invalid input! It is Black's turn!" << endl;
                            inputVector.clear();
                            return;
                        }
                        for (int i = 0; i < 8; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (i == 8 - y1 && j == x1 - 1) {
                                    tile1 = {x1, y1, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                                }
                                if (i == 8 - y2 && j == x2 - 1) {
                                    tile2 = {x2, y2, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                                }
                            }
                        }
                        try {
                            move(cb, x1, y1, x2, y2, wT, tile1, tile2, isWhiteTurn, inputVector, true);
                        } catch(std::exception& e) {
                            continue;
                        }
                    }
                }
                turn += 1;
            }
        }
    }
}

int main(void) {
    bool setupTurn = true;
    bool isWhiteTurn = true;
    bool didIjustSetup = false;
    string computerTurn = "no";
    int computerLevel1;
    int computerLevel2;
    bool isP1Comp;
    bool isP2Comp;
    string input;
    vector <string> inputVector; 
    ChessBoard cb;
    bool invalidSetup = false;
    int whiteKing = 0;
    int blackKing = 0;
    cout << "==============================" << endl;
    cout << "Hi! Welcome to the Game of Chess" << endl;
    cout << "Type 'game a b' where 'a' is player 1 (W) and b is player 2 (B)" << endl;
    cout << "Player 'a' or 'b' can either be 'human' or 'computer[1-4]'" << endl;
    cout << "To make a move type 'move x y' where 'x' is the current position and 'y' is the new position" << endl;
    cout << "To enter setup mode, type 'setup'" << endl;
    cout << "To leave a game, type 'resign'" << endl;
    cout << "==============================" << endl;
    while (true) { 
        /*
        if (cb.ISSTALEMATE) {
            cb.whiteScore += 1;
            cb.blackScore += 1;
            cb.ISSTALEMATE = false;
            inputVector.clear();
            cb.init();
            continue;
        }*/
        getline(cin, input);
        istringstream ss(input);
        string word;
        while (ss >> word) {
            inputVector.emplace_back(word);
        }
        if ((inputVector.size() == 1 || inputVector.size() == 4) && inputVector[0] != "move") {
            if (inputVector[0] == "resign") {
                break;
            } else if (inputVector[0] == "setup" && setupTurn) {
                didIjustSetup = true;
                cb.init_empty();
                while (true) {
                    getline(cin, input);
                    istringstream ss(input);
                    string word;
                    while (ss >> word) {
                    inputVector.emplace_back(word);
                    }
                    if (inputVector.size() == 4) {
                        if (inputVector[1] == "+") {
                            PieceType p = whichPiece(inputVector[2]);
                            Colour c = whichColour(inputVector[2]);
                            if (p == PieceType::King && c == Colour::Black) {
                                blackKing += 1;
                            } else if (p == PieceType::King && c == Colour::White) {
                                whiteKing += 1;
                            } 
                            if (p == PieceType::NoPiece || c == Colour::NoColour) {
                                cout << "Invalid input! Please enter command again!" << endl;
                                inputVector.clear();
                                inputVector.emplace_back("setup");
                                continue;
                            }
                            int x = cb.getX(inputVector[3][0]);
                            int y = cb.getY(inputVector[3][1]);
                            for (int i = 0; i < 8; ++i) {
                                for (int j = 0; j < 8; ++j) {
                                    if (i == 8 - y && j == x - 1) {
                                        Tile newTile = {i, j, c, p};
                                        cb.chessBoard[i][j] = newTile;
                                        cout << cb;
                                        inputVector.clear();
                                        inputVector.emplace_back("setup");
                                        continue;
                                    }
                                }
                            }
                        } else {
                            cout << "Invalid input! Please enter command again!" << endl;
                            inputVector.clear();
                            inputVector.emplace_back("setup");
                            continue;
                        }
                    } else if (inputVector.size() == 3) {
                        if (inputVector[1] == "-") {
                            int x1 = cb.getX(inputVector[2][0]);
                            int y1 = cb.getY(inputVector[2][1]);
                            for (int i = 0; i < 8; ++i) {
                                for (int j = 0; j < 8; ++j) {
                                    if (i == 8 - y1 && j == x1 - 1) {
                                        PieceType currentP = cb.chessBoard[i][j].p;
                                        Colour currentC = cb.chessBoard[i][j].c;
                                        if (currentC == Colour::Black && currentP == PieceType::King) {
                                            blackKing -= 1;
                                        }
                                        if (currentC == Colour::White && currentP == PieceType::King) {
                                            whiteKing -= 1;
                                        }
                                        Tile newT = {i, j, Colour::NoColour, PieceType::NoPiece};
                                        cb.chessBoard[i][j] = newT;
                                        cout << cb;
                                        inputVector.clear();
                                        inputVector.emplace_back("setup");
                                        continue;
                                    }
                                }
                            }
                        } else if (inputVector[1] == "=") {
                            if (inputVector[2] == "black") {
                                isWhiteTurn = false;
                                inputVector.clear();
                                inputVector.emplace_back("setup");
                                continue;
                            } else if (inputVector[2] == "white") {
                                isWhiteTurn = true;
                                inputVector.clear();
                                inputVector.emplace_back("setup");
                                continue;
                            } else {
                                cout << "Invalid input! Please enter command again!" << endl;
                                inputVector.clear();
                                inputVector.emplace_back("setup");
                                continue;
                            }
                        } 
                    } else if (inputVector.size() == 2) {
                        if (inputVector[1] == "done") { 
                            setupTurn = false;
                            for (int i = 0; i < 8; ++i) {
                                if (invalidSetup) {
                                    break;
                                }
                                for (int j = 0; j < 8; ++j) {
                                    if (i == 0 || i == 7) {
                                        if (cb.chessBoard[i][j].p == PieceType::Pawn || cb.chessBoard[i][j].p == PieceType::Pawn) {
                                            invalidSetup = true;
                                            cout << "Invalid setup! You can not place Pawn on the first or last row!" << endl;
                                            inputVector.clear();
                                            inputVector.emplace_back("setup");
                                            break;
                                        }
                                    } 
                                    if (whiteKing != 1) {
                                        invalidSetup = true;
                                        cout << "Invalid setup! You need ONE White King!." << endl;
                                        inputVector.clear();
                                        inputVector.emplace_back("setup");
                                        break;
                                    }
                                    if (blackKing != 1) {
                                        invalidSetup = true;
                                        cout << "Invalid setup! You need ONE Black King!." << endl;
                                        inputVector.clear();
                                        inputVector.emplace_back("setup");
                                        break;
                                    }
                                }
                            }
                            if (invalidSetup) {
                                inputVector.clear();
                                inputVector.emplace_back("setup");
                                invalidSetup = false;
                                continue;
                            } else {
                                inputVector.clear();
                                break;
                            }
                        }
                    }
                }
                if (!invalidSetup) {
                    continue;
                }
            } else {
                if (!setupTurn) {
                    cout << "You can't use setup during a game!" << endl;
                    inputVector.clear();
                    continue;
                } else {
                    cout << "Invalid input! Please enter command again!" << endl;
                    inputVector.clear();
                    continue;
                }
            }
        } else if (inputVector.size() == 3) {
            if (inputVector[0] == "game") {
                // Initialize Player 1
                if (inputVector[1] == "human") {
                } else if (inputVector[1].substr(0, 8) == "computer") {
                    char levelChar = inputVector[1][9];
                    int level = levelChar - '0';
                    if (0 < level &&  level < 5) {
                        computerTurn = "white";
                        computerLevel1 = level;
                        isP1Comp = true;
                    } else {
                        cout << "Invalid input! Please enter command again!" << endl;
                        inputVector.clear();
                        continue;
                    }
                } else {
                    cout << "Invalid input! Please enter command again!" << endl;
                    inputVector.clear();
                    continue;
                }
                // Initialize Player 2 
                if (inputVector[2] == "human") {
                    inputVector.clear();
                    setupTurn = false;
                    if (didIjustSetup) {
                        cout << cb;
                    } else {
                        cb.init();
                        cout << cb;
                    } 
                } else if (inputVector[2].substr(0, 8) == "computer") {
                    char levelChar = inputVector[2][9];
                    int level = levelChar - '0';
                    if (0 < level &&  level < 5) {
                        if (computerTurn != "white") {
                            computerTurn = "black";
                        }
                        computerLevel2 = level;
                        isP2Comp = true;
                        inputVector.clear();
                        setupTurn = false;
                        if (didIjustSetup) {
                            cout << cb;
                        } else {
                            cb.init();
                            cout << cb;
                        } 
                    } else {
                        cout << "Invalid input! Please enter command again!" << endl;
                        inputVector.clear();
                        continue;
                    }
                } else {
                    cout << "Invalid input! Please enter command again!" << endl;
                    inputVector.clear();
                    continue;
                }
                if (computerTurn == "white") {
                    if (isP1Comp && isP2Comp) {
                        playWithComputer(cb, "white", computerLevel1, computerLevel2, true, inputVector);
                    } else {
                        playWithComputer(cb, "white", computerLevel1, 0, false, inputVector);
                    }
                } else if (computerTurn == "black") {
                    if (isP1Comp && isP2Comp) {
                        playWithComputer(cb, "black", computerLevel1, computerLevel2, true, inputVector);
                    } else {
                        playWithComputer(cb, "black", 0, computerLevel2, false, inputVector);
                    }
                }
            } else if (inputVector[0] == "move") {
                int x1 = cb.getX(inputVector[1][0]);
                int y1 = cb.getY(inputVector[1][1]);
                int x2 = cb.getX(inputVector[2][0]);
                int y2 = cb.getY(inputVector[2][1]);
                Colour wT = whichTurn(x1, y1, cb);
                Tile tile1;
                Tile tile2;
                if (whichTurn(x1, y1, cb) == Colour::NoColour) {
                    cout << "Invalid input!" << endl;
                    inputVector.clear();
                    continue;
                } else if (isWhiteTurn && whichTurn(x1, y1, cb) != Colour::White) {
                    cout << "Invalid input! It is White's turn!" << endl;
                    inputVector.clear();
                    continue;
                } else if (!isWhiteTurn && whichTurn(x1, y1, cb) != Colour::Black) {
                    cout << "Invalid input! It is Black's turn!" << endl;
                    inputVector.clear();
                    continue;
                }
                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 8; ++j) {
                        if (i == 8 - y1 && j == x1 - 1) {
                           tile1 = {x1, y1, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                        }
                        if (i == 8 - y2 && j == x2 - 1) {
                           tile2 = {x2, y2, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                        }
                    }
                }
                move(cb, x1, y1, x2, y2, wT, tile1, tile2, isWhiteTurn, inputVector, false);
            } else {
                cout << "Invalid input! Please enter command again!" << endl;
                inputVector.clear();
                continue;
            }
        } else if (inputVector.size() == 4) {
            if (inputVector[0] == "move") {
                cout << "inside right move" << endl;
                int x1 = cb.getX(inputVector[1][0]);
                int y1 = cb.getY(inputVector[1][1]);
                int x2 = cb.getX(inputVector[2][0]);
                int y2 = cb.getY(inputVector[2][1]);
                PieceType pPiece = whichPiece(inputVector[3]);
                if (pPiece == PieceType::Pawn || pPiece == PieceType::King) {
                    cout << "Invalid input! Promotion piece can be either of Rook, Knight, Bishop or Queen!" << endl;
                    inputVector.clear();
                    continue;
                }
                Colour pColour = whichColour(inputVector[3]);
                if (isWhiteTurn && pColour != Colour::White) {
                    cout << "Invalid input! It is White's turn! Promotion piece must be White!" << endl;
                    inputVector.clear();
                    continue;
                } else if (!isWhiteTurn && pColour != Colour::Black) {
                    cout << "Invalid input! It is Black's turn! Promotion piece must be Black" << endl;
                    inputVector.clear();
                    continue;
                }
                if (isWhiteTurn && whichTurn(x1, y1, cb) != Colour::White) {
                    cout << "Invalid input! It is White's turn!" << endl;
                    inputVector.clear();
                    continue;
                } else if (!isWhiteTurn && whichTurn(x1, y1, cb) != Colour::Black) {
                    cout << "Invalid input! It is Black's turn!" << endl;
                    inputVector.clear();
                    continue;
                }
                Tile tile1;
                Tile tile2;
                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 8; ++j) {
                        if (i == 8 - y1 && j == x1 - 1) {
                           tile1 = {x1, y1, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                        }
                        if (i == 8 - y2 && j == x2 - 1) {
                           tile2 = {x2, y2, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                        }
                    }
                }
                if (IsLegal(tile1, tile2, cb)) {
                    if (IsValid(tile1, tile2, cb)) {
                        for (int i = 0; i < 8; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (i == 8 - y1 && j == x1 - 1) {
                                    Tile newT = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                                    cb.chessBoard[i][j] = newT;
                                }
                                if (i == 8 - y2 && j == x2 - 1) {
                                    if (tile1.p == PieceType::Pawn && tile1.c == Colour::White && i == 0) {
                                        Tile newT = {x2, y2, tile1.c, pPiece};
                                        cb.chessBoard[i][j] = newT;
                                    } else if (tile1.p == PieceType::Pawn && tile1.c == Colour::Black && i == 7) {
                                        Tile newT = {x2, y2, tile1.c, pPiece};
                                        cb.chessBoard[i][j] = newT;
                                    } else {
                                        Tile newT = {x2, y2, tile1.c, tile1.p};
                                        cb.chessBoard[i][j] = newT;
                                    } 
                                } 
                            }
                        }
                        if (isWhiteTurn == true) {
                            isWhiteTurn = false;
                         } else if (isWhiteTurn == false) {
                            isWhiteTurn = true;
                        }
                    } else {
                        cout << "Invalid move! Please enter command again!" << endl;
                        inputVector.clear();
                        continue;
                    }
                    cout << cb;
                    inputVector.clear();
                    continue;
                } else {
                    cout << "Invalid move! Please enter command again!" << endl;
                    inputVector.clear();
                    continue;
                }
            } else {
                cout << "Invalid input! Please enter command again!" << endl;
                inputVector.clear();
                continue;
            }
        }
    }
    return 0;
}

