#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "piece.h"
#include "tile.h"
#include "info.h"
//#include "graphicsdisplay.h"
#include <vector>
#include <cstdlib>
#include <algorithm>

class ChessBoard{
    const int boardSize = 8;
    public:
        int whiteScore = 0;
        int blackScore = 0;
        bool ISSTALEMATE = false;
        bool ISCHECKMATE = false;
        bool hasPawnMovedTwice = false;
        bool castlingWhiteAllowedRight = true;
        bool castlingWhiteAllowedLeft = true;
        bool castlingBlackAllowedRight = true;
        bool castlingBlackAllowedLeft = true;
        int WhiteKingPosX(ChessBoard &cb);
        int WhiteKingPosY(ChessBoard &cb);
        int BlackKingPosX(ChessBoard &cb);
        int BlackKingPosY(ChessBoard &cb);
        int getX(char s);
        int getY(char s);
        std::vector<std::vector<Tile>> chessBoard;
        ChessBoard();
        ~ChessBoard();
        //bool isWhiteStalemate(int i, int j, ChessBoard &cb, std::vector <std::string> inputVector);
        //bool isBlackStalemate(int i, int j, ChessBoard &cb, std::vector <std::string> inputVector);
        bool isWhiteCheck(ChessBoard &cb, Tile t1, Tile t2, std::vector <std::string> inputVector);
        bool isBlackCheck(ChessBoard &cb, Tile t1, Tile t2, std::vector <std::string> inputVector);
        void init_empty();
        void init();
        friend std::ostream &operator<<(std::ostream &out, const ChessBoard &cb);
};

bool IsLegal(Tile t1, Tile t2, ChessBoard &cb);
bool IsValid(Tile t1, Tile t2, ChessBoard &cb);

#endif


