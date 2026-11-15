
#include <iostream>
#include <vector>
#include <string>

#include "ChessBoard.h"
#include "MoveGenerator.h"
#include "Benchmark.h"

using namespace std;

int main() {

    cout << "====================================\n";
    cout << "      CHESS STL BENCHMARK SYSTEM\n";
    cout << "====================================\n";

    // STEP 1: Initialize chessboard

    ChessBoard chess;

    cout << "\nINITIAL CHESSBOARD:\n";
    chess.displayBoard();


    // STEP 2: Generate possible moves

    MoveGenerator generator;

    vector<Move> moves =
        generator.generateMoves(chess, true);

    cout << "\nPossible moves for White: "
         << moves.size() << "\n";


    // STEP 3: Generate benchmark dataset

    vector<string> keys;

    int datasetSize = 100000;

    for (int i = 0; i < datasetSize; i++) {

        keys.push_back("position_" + to_string(i));

    }

    cout << "\nBenchmark dataset generated: "
         << keys.size() << " keys\n";


    // STEP 4: Run STL benchmark

    Benchmark benchmark;

    benchmark.runBenchmark(keys);


    cout << "\nPROJECT EXECUTION COMPLETED!\n";

    return 0;
}
