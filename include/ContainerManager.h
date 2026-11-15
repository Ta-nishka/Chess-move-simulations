
#ifndef CONTAINERMANAGER_H
#define CONTAINERMANAGER_H

#include <map>
#include <unordered_map>
#include <string>

class ContainerManager {

private:

    // Ordered storage
    std::map<std::string, int> orderedPositions;

    // Hash-based storage
    std::unordered_map<std::string, int> hashedPositions;

public:

    // Insert operations
    void insertIntoMap(const std::string& key);
    void insertIntoUnorderedMap(const std::string& key);

    // Search operations
    bool searchMap(const std::string& key) const;
    bool searchUnorderedMap(const std::string& key) const;

    // Delete operations
    void deleteFromMap(const std::string& key);
    void deleteFromUnorderedMap(const std::string& key);

    // Get container sizes
    size_t getMapSize() const;
    size_t getUnorderedMapSize() const;

};

#endif
