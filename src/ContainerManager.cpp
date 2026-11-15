
#include "ContainerManager.h"

using namespace std;

// INSERTION OPERATIONS

void ContainerManager::insertIntoMap(const string& key) {
    orderedPositions[key]++;
}

void ContainerManager::insertIntoUnorderedMap(const string& key) {
    hashedPositions[key]++;
}


// SEARCH OPERATIONS

bool ContainerManager::searchMap(const string& key) const {
    return orderedPositions.find(key) != orderedPositions.end();
}

bool ContainerManager::searchUnorderedMap(const string& key) const {
    return hashedPositions.find(key) != hashedPositions.end();
}


// DELETION OPERATIONS

void ContainerManager::deleteFromMap(const string& key) {
    orderedPositions.erase(key);
}

void ContainerManager::deleteFromUnorderedMap(const string& key) {
    hashedPositions.erase(key);
}


// SIZE OPERATIONS

size_t ContainerManager::getMapSize() const {
    return orderedPositions.size();
}

size_t ContainerManager::getUnorderedMapSize() const {
    return hashedPositions.size();
}
