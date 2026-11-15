
#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include <vector>
#include "ChessBoard.h"

struct Move {
    int fromRow;
    int fromCol;
    int toRow;
    int toCol;
};

class MoveGenerator {
public:
    std::vector<Move> generateMoves(
        const ChessBoard& board,
        bool white
    ) const;
};

#endif
