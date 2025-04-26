//
// Created by "ANIKET GUPTA" on 26-04-2025.
//

#ifndef DBMAKER_H
#define DBMAKER_H

#include "CornerPatternDatabase.h"

using namespace std;

class CornerDBMaker {
private:
    string fileName_;
    CornerPatternDatabase cornerDB_;

public:
    CornerDBMaker(string fileName, uint8_t init_val);

    bool bfsAndStore(int mx_depth = 7);
};

#endif //DBMAKER_H
