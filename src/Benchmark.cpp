
#include "Benchmark.h"
#include "ContainerManager.h"

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void Benchmark::runBenchmark(const vector<string>& keys) {

    ContainerManager manager;

    cout << "\n========== STL BENCHMARK ==========\n";
    cout << "Dataset size: " << keys.size() << "\n\n";

    // =================================
    // 1. INSERTION BENCHMARK
    // =================================

    auto startMapInsert = high_resolution_clock::now();

    for (const string& key : keys) {
        manager.insertIntoMap(key);
    }

    auto endMapInsert = high_resolution_clock::now();

    auto mapInsertTime =
        duration_cast<microseconds>(
            endMapInsert - startMapInsert
        ).count();


    auto startHashInsert = high_resolution_clock::now();

    for (const string& key : keys) {
        manager.insertIntoUnorderedMap(key);
    }

    auto endHashInsert = high_resolution_clock::now();

    auto hashInsertTime =
        duration_cast<microseconds>(
            endHashInsert - startHashInsert
        ).count();


    // =================================
    // 2. SEARCH BENCHMARK
    // =================================

    size_t mapHits = 0;
    size_t hashHits = 0;

    auto startMapSearch = high_resolution_clock::now();

    for (const string& key : keys) {
        if (manager.searchMap(key)) {
            ++mapHits;
        }
    }

    auto endMapSearch = high_resolution_clock::now();

    auto mapSearchTime =
        duration_cast<microseconds>(
            endMapSearch - startMapSearch
        ).count();


    auto startHashSearch = high_resolution_clock::now();

    for (const string& key : keys) {
        if (manager.searchUnorderedMap(key)) {
            ++hashHits;
        }
    }

    auto endHashSearch = high_resolution_clock::now();

    auto hashSearchTime =
        duration_cast<microseconds>(
            endHashSearch - startHashSearch
        ).count();


    // =================================
    // 3. DELETION BENCHMARK
    // =================================

    auto startMapDelete = high_resolution_clock::now();

    for (const string& key : keys) {
        manager.deleteFromMap(key);
    }

    auto endMapDelete = high_resolution_clock::now();

    auto mapDeleteTime =
        duration_cast<microseconds>(
            endMapDelete - startMapDelete
        ).count();


    auto startHashDelete = high_resolution_clock::now();

    for (const string& key : keys) {
        manager.deleteFromUnorderedMap(key);
    }

    auto endHashDelete = high_resolution_clock::now();

    auto hashDeleteTime =
        duration_cast<microseconds>(
            endHashDelete - startHashDelete
        ).count();


    // =================================
    // 4. DISPLAY RESULTS
    // =================================

    cout << "Operation       std::map     unordered_map\n";

    cout << "Insertion       "
         << mapInsertTime << " us       "
         << hashInsertTime << " us\n";

    cout << "Searching       "
         << mapSearchTime << " us       "
         << hashSearchTime << " us\n";

    cout << "Deletion        "
         << mapDeleteTime << " us       "
         << hashDeleteTime << " us\n";

    cout << "\nSearch verification:\n";

    cout << "Map matches: " << mapHits << "\n";
    cout << "Hash matches: " << hashHits << "\n";

    cout << "\nRemaining map elements: "
         << manager.getMapSize() << "\n";

    cout << "Remaining hash elements: "
         << manager.getUnorderedMapSize() << "\n";

    cout << "\n===================================\n";
}
