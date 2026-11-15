# ♟️ Chess Move Simulation & STL Benchmarking

A C++ project that combines chess move simulation with a performance comparison of `std::map` and `std::unordered_map` from the Standard Template Library (STL).

## Overview

This project implements a basic chessboard and pseudo-legal move generator, alongside a benchmarking system to evaluate the performance of two commonly used C++ associative containers.

The benchmark compares insertion, searching, and deletion operations to understand how ordered and hash-based data structures behave under the same workload.

## Features

- **Chessboard Representation:** Models an 8×8 chessboard using a fixed-size array.
- **Move Generation:** Generates pseudo-legal moves for chess pieces, including pawns, knights, bishops, rooks, queens, and kings.
- **STL Container Comparison:** Implements both `std::map` and `std::unordered_map`.
- **Performance Benchmarking:** Measures insertion, search, and deletion execution times using C++ `<chrono>`.
- **Search Verification:** Checks that both containers successfully find the expected keys.

## Tech Stack

- Language: C++
- Standard: C++17
- STL: `std::map`, `std::unordered_map`, `std::vector`
- Timing: `<chrono>`
- Concepts: Object-Oriented Programming, data structures, algorithmic complexity

## Project Structure

```text
Chess-STL-Benchmark/
│
├── include/
│   ├── ChessBoard.h
│   ├── MoveGenerator.h
│   ├── ContainerManager.h
│   └── Benchmark.h
│
├── src/
│   ├── main.cpp
│   ├── ChessBoard.cpp
│   ├── MoveGenerator.cpp
│   ├── ContainerManager.cpp
│   └── Benchmark.cpp
│
├── results/
├── docs/
├── README.md
├── .gitignore
└── CMakeLists.txt
```

## ⚙️ Build and Run

### Prerequisites

- GCC or another C++17-compatible compiler
- VS Code or any C++ development environment

### Compile

Run the following command from the project root:

```bash
g++ -std=c++17 -O2 src/main.cpp src/ChessBoard.cpp src/MoveGenerator.cpp src/ContainerManager.cpp src/Benchmark.cpp -I include -o chess
```

### Execute

On Windows PowerShell:

```powershell
.\chess.exe
```

## Benchmark Comparison

The project evaluates three operations:

| Operation | std::map | std::unordered_map |
|---|---|---|
| Insertion | O(log n) | O(1) average |
| Searching | O(log n) | O(1) average |
| Deletion | O(log n) | O(1) average |

### Sample Benchmark Results

One observed run with 100,000 keys:

| Operation | std::map (µs) | std::unordered_map (µs) |
|---|---:|---:|
| Insertion | 47,959 | 14,406 |
| Searching | 16,236 | 10,317 |
| Deletion | 29,168 | 22,841 |

In this run, `std::unordered_map` was faster across all three operations.

**Note:** These are sample measurements from a single execution, not statistically averaged results. Execution times depend on hardware, compiler optimizations, data distribution, and system conditions.

## Key Learnings

- Understanding ordered maps and hash tables.
- Comparing theoretical time complexity with measured execution time.
- Applying OOP principles through modular C++ classes.
- Using `<chrono>` for runtime measurement.
- Understanding the trade-offs between ordered and unordered associative containers.

## Current Limitations

- Chess move generation does not validate king safety or implement all special chess rules.
- Benchmark results currently use synthetic keys rather than serialized chess positions.
- Performance measurements are based on a single run.

## Future Improvements

- Repeated benchmark trials and average execution-time analysis.
- Performance comparisons across different dataset sizes.
- CSV-based benchmark result storage.
- Graphical visualization of benchmark results.
- Integration of generated chess positions into the benchmark dataset.

## Author

**Tanishka Deshmukh**

Solo C++ Project | 2025
