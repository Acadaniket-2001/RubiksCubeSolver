//
// Created by "ANIKET GUPTA" on 26-04-2025.
//

#include "CornerPatternDatabase.h"
#include "math.h"

CornerPatternDatabase::CornerPatternDatabase() :
    PatternDatabase(100179840) {}

CornerPatternDatabase::CornerPatternDatabase(uint8_t init_val) :
    PatternDatabase(100179840, init_val) {}

uint32_t CornerPatternDatabase::getDatabaseIndex(RubiksCube& cube)
const {
    array<uint8_t, 8> cornerPermutation;
    for (int idx = 0; idx < 8; idx++) {
        cornerPermutation[idx] = cube.getCornerIndex(idx);
    }
    uint32_t permIndex = indexer_.rank(cornerPermutation);


    array<uint8_t, 8> cornerOrientation;

    // Using only 7 orientations: Cube Laws
    for (int idx = 0; idx < 7; idx++) {
        cornerOrientation[idx] = cube.getCornerOrientation(idx);
    }

    // Using Dictionary Ranking Logic to calc. orienIndex
    uint32_t orienIndex = 0;
    for (int i = 0; i < 7; i++) {
        orienIndex += cornerOrientation[i] * pow(3, 7 - i - 1);
    }

    // Since, each prev permutation can have (3^7 = 3.3.3....7times) orientation, so permIndex * (3^7)
    return permIndex*pow(3, 7) + orienIndex;
}