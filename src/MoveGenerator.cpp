
#include "MoveGenerator.h"

#include <cctype>
#include <vector>
#include <utility>

using namespace std;

vector<Move> MoveGenerator::generateMoves(
    const ChessBoard& board,
    bool white
) const {

    vector<Move> moves;

    // Knight movement directions
    const int knightMoves[8][2] = {
        {-2, -1}, {-2, 1},
        {-1, -2}, {-1, 2},
        {1, -2}, {1, 2},
        {2, -1}, {2, 1}
    };

    // All eight directions
    const int allDirections[8][2] = {
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1},
        {-1, -1}, {-1, 1},
        {1, -1}, {1, 1}
    };

    // Four diagonal directions
    const int diagonalDirections[4][2] = {
        {-1, -1}, {-1, 1},
        {1, -1}, {1, 1}
    };

    // Four straight directions
    const int straightDirections[4][2] = {
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1}
    };

    // Check every square on the board
    for (int row = 0; row < 8; row++) {

        for (int col = 0; col < 8; col++) {

            char piece = board.getPiece(row, col);

            if (piece == '.') {
                continue;
            }

            // Determine piece color
            bool pieceIsWhite = isupper(
                static_cast<unsigned char>(piece)
            );

            if (pieceIsWhite != white) {
                continue;
            }

            char type = static_cast<char>(
                tolower(static_cast<unsigned char>(piece))
            );

            // Add a move if the destination is empty
            // or contains an opponent's piece.
            auto addMove = [&](int newRow, int newCol) {

                if (newRow < 0 || newRow >= 8 ||
                    newCol < 0 || newCol >= 8) {
                    return false;
                }

                char target = board.getPiece(newRow, newCol);

                if (target != '.') {

                    bool targetIsWhite = isupper(
                        static_cast<unsigned char>(target)
                    );

                    if (targetIsWhite == white) {
                        return false;
                    }
                }

                moves.push_back({
                    row, col, newRow, newCol
                });

                return target == '.';
            };

            // PAWN
            if (type == 'p') {

                int direction = white ? -1 : 1;
                int startRow = white ? 6 : 1;

                int nextRow = row + direction;

                // Move one square forward
                if (nextRow >= 0 && nextRow < 8 &&
                    board.getPiece(nextRow, col) == '.') {

                    addMove(nextRow, col);

                    // Move two squares from starting position
                    int doubleRow = row + 2 * direction;

                    if (row == startRow &&
                        board.getPiece(doubleRow, col) == '.') {

                        addMove(doubleRow, col);
                    }
                }

                // Capture diagonally
                for (int dc : {-1, 1}) {

                    int newCol = col + dc;

                    if (nextRow >= 0 && nextRow < 8 &&
                        newCol >= 0 && newCol < 8) {

                        char target = board.getPiece(
                            nextRow, newCol
                        );

                        if (target != '.') {

                            bool targetIsWhite = isupper(
                                static_cast<unsigned char>(target)
                            );

                            if (targetIsWhite != white) {
                                addMove(nextRow, newCol);
                            }
                        }
                    }
                }
            }

            // KNIGHT
            else if (type == 'n') {

                for (const auto& direction : knightMoves) {

                    int newRow = row + direction[0];
                    int newCol = col + direction[1];

                    addMove(newRow, newCol);
                }
            }

            // BISHOP, ROOK AND QUEEN
            else if (type == 'b' || type == 'r' || type == 'q') {

                const int (*directions)[2];
                int count;

                if (type == 'b') {
                    directions = diagonalDirections;
                    count = 4;
                }
                else if (type == 'r') {
                    directions = straightDirections;
                    count = 4;
                }
                else {
                    directions = allDirections;
                    count = 8;
                }

                for (int i = 0; i < count; i++) {

                    int newRow = row + directions[i][0];
                    int newCol = col + directions[i][1];

                    while (newRow >= 0 && newRow < 8 &&
                           newCol >= 0 && newCol < 8) {

                        bool canContinue = addMove(
                            newRow, newCol
                        );

                        if (!canContinue) {
                            break;
                        }

                        newRow += directions[i][0];
                        newCol += directions[i][1];
                    }
                }
            }

            // KING
            else if (type == 'k') {

                for (const auto& direction : allDirections) {

                    int newRow = row + direction[0];
                    int newCol = col + direction[1];

                    addMove(newRow, newCol);
                }
            }
        }
    }

    return moves;
}
