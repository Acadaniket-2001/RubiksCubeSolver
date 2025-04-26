//
// Created by "ANIKET GUPTA" on 26-04-2025.
//

#ifndef CORNERPATTERNDATABASE_H
#define CORNERPATTERNDATABASE_H

#include "PatternDatabase.h"
#include "PermutationIndexer.h"

class CornerPatternDatabase : public PatternDatabase {
public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_Val);

    uint32_t getDatabaseIndex(RubiksCube &cube) const;

private:
    PermutationIndexer<8> indexer_;
};

#endif //CORNERPATTERNDATABASE_H
