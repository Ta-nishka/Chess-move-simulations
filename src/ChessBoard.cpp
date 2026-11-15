
#include <iostream>
#include "ChessBoard.h"

using namespace std;

// Constructor
ChessBoard::ChessBoard() {
    initializeBoard();
}

// Initialize all 64 squares
void ChessBoard::initializeBoard() {

    // Empty all squares
    board.fill('.');

    // Black pieces
    board[0] = 'r';
    board[1] = 'n';
    board[2] = 'b';
    board[3] = 'q';
    board[4] = 'k';
    board[5] = 'b';
    board[6] = 'n';
    board[7] = 'r';

    for (int i = 8; i < 16; i++) {
        board[i] = 'p';
    }

    // White pieces
    for (int i = 48; i < 56; i++) {
        board[i] = 'P';
    }

    board[56] = 'R';
    board[57] = 'N';
    board[58] = 'B';
    board[59] = 'Q';
    board[60] = 'K';
    board[61] = 'B';
    board[62] = 'N';
    board[63] = 'R';
}

// Display chessboard
void ChessBoard::displayBoard() const {

    cout << "\n   a b c d e f g h\n";
    cout << "  -----------------\n";

    for (int row = 0; row < 8; row++) {

        cout << 8 - row << " | ";

        for (int col = 0; col < 8; col++) {

            cout << board[row * 8 + col] << " ";
        }

        cout << "| " << 8 - row << endl;
    }

    cout << "  -----------------\n";
    cout << "   a b c d e f g h\n";
}

// Retrieve a piece from a particular square
char ChessBoard::getPiece(int row, int col) const {

    if (row < 0 || row >= 8 || col < 0 || col >= 8) {
        return '.';
    }

    return board[row * 8 + col];
}


void ChessBoard::applyMove(int fromRow, int fromCol, int toRow, int toCol) {
    // Check that both positions are within the board
    if (fromRow < 0 || fromRow >= 8 ||
        fromCol < 0 || fromCol >= 8 ||
        toRow < 0 || toRow >= 8 ||
        toCol < 0 || toCol >= 8) {
        return;
    }

    // Move the piece
    char piece = board[fromRow * 8 + fromCol];

    board[toRow * 8 + toCol] = piece;
    board[fromRow * 8 + fromCol] = '.';
}

std::string ChessBoard::getPositionKey(bool whiteToMove) const {
    std::string key;

    // Store all 64 squares
    for (char piece : board) {
        key += piece;
    }

    // Include whose turn it is
    key += whiteToMove ? 'W' : 'B';

    return key;
}
