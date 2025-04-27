//
// Created by "ANIKET GUPTA" on 26-04-2025.
//

#include "CornerDBMaker.h"
#include "../Models/RubiksCubeBitboard.cpp"

using namespace std;

CornerDBMaker::CornerDBMaker(string fileName, uint8_t init_val) {
    fileName_ = fileName;
    cornerDB_ = CornerPatternDatabase(init_val);
}

bool CornerDBMaker::bfsAndStore(int mx_depth) {
    RubiksCubeBitboard cube;

    queue<RubiksCubeBitboard> q;

    q.push(cube);
    cornerDB_.setHeuristic(cube, 0);

    while (!q.empty()) {
        auto node = q.front(); q.pop();
        int depth = cornerDB_.getHeuristic(node);

        if (depth + 1 > min(9, mx_depth)) break;       // added a safety limit of 9 levels

        for (int i = 0; i < 18; i++) {
            RubiksCubeBitboard v = node;
            v.move(RubiksCube::MOVE(i));

            if (cornerDB_.getHeuristic(v) > depth + 1) {
                cornerDB_.setHeuristic(v, depth + 1);
                q.push(v);
            }
        }
    }

    cornerDB_.toFile(fileName_);
    return true;
}