
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <array>
#include <string>

class ChessBoard {
private:
    std::array<char, 64> board;

public:
    ChessBoard();

    void initializeBoard();
    void displayBoard() const;

    char getPiece(int row, int col) const;

    void applyMove(int fromRow, int fromCol, int toRow, int toCol);

    std::string getPositionKey(bool whiteToMove) const;
};

#endif
