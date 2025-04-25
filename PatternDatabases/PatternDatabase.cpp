//
// Created by ANIKET GUPTA  on 25-04-2025.
//

#include "PatternDatabase.h"

const string filePath = "../Databases/CornerDB.txt";

PatternDatabase::PatternDatabase(const size_t size) :
    database(size, 0xFF), size(size), numItems(0) {}


PatternDatabase::PatternDatabase(const size_t size, uint8_t init_val) :
    database(size, init_val), size(size), numItems(0) {}


bool PatternDatabase::setHeuristic(const uint32_t ind, const uint8_t numMoves) {
    uint8_t oldNumMoves = getHeuristic(ind);

    if (oldNumMoves == 0xF) numItems++;      // 0XF = (0000 1111) = 15

    if (oldNumMoves > numMoves) {
        database.setVal(ind, oldNumMoves);
        return true;
    }
    return false;
}

bool PatternDatabase::setHeuristic(const RubiksCube &cube, const uint8_t numMoves) {
    return setHeuristic(getDatabaseIndex(cube), numMoves);
}

uint8_t PatternDatabase::getHeuristic(const uint32_t ind) const {
    return database.getVal(ind);
}

uint8_t PatternDatabase::getHeuristic(const RubiksCube &cube) const {
    return getHeuristic(getDatabaseIndex(cube));
}

size_t PatternDatabase::getSize() const {
    return size;
}

size_t PatternDatabase::getNumItems() const {
    return numItems;
}

bool PatternDatabase::isFull() const {
    return (numItems == size);
}

void PatternDatabase::toFile(const string &filePath) const {

    ofstream writer(filePath, ios::out | ios::binary | ios::trunc);

    if(!writer.is_open())
        throw "Failed to open the file to write";

    writer.write(
            reinterpret_cast<const char*>(database.data()),  // .data(): returns const unsigned char* (==const uint8_t*)
            database.storageSize()
            );

    writer.close();
}

// Returns true of database is loaded successfully
// else return false

bool PatternDatabase::fromFile(const string &filePath) {
    ifstream reader(filePath, ios::in | ios::ate);

    if(!reader.is_open())
        return false;

    size_t fileSize = reader.tellg();

    if(fileSize != database.storageSize()){
        reader.close();
        throw "Database corrupt! Failed to open Reader";
    }

    reader.seekg(0, ios::beg);
    reader.read(
            reinterpret_cast<char*> (database.data()),  // .data(): returns unsigned char*
            database.storageSize()
            );
    reader.close();
    numItems = size;
    return true;
}

vector<uint8_t> PatternDatabase::inflate() const {
    vector<uint8_t> inflated;
    database.inflate(inflated);
    return inflated;
}

void PatternDatabase::reset() {
    if(numItems != 0){
        database.reset(0xFF);
        numItems = 0;
    }
}