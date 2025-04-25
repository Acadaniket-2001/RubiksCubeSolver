//
// Created by Aniket Gupta on 24-04-2025.
//

#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H

#include "DFSSolver.h"
#include "bits/stdc++.h"

using namespace std;

template<typename T, typename X>
class IDDFSSolver {
public:
    IDDFSSolver(T &rubik, int max_search_depth = 7) :
        rubik_(rubik), max_search_depth_(max_search_depth) {};

    vector<typename T::MOVE> solve() {

        int max_depth = 0;
        while (true) {
            max_depth++;

            if (max_depth > max_search_depth_) break;

            DFSSolver<T, X> dfsSolver(rubik_, max_search_depth_);
            moves_ = dfsSolver.solve();
            if (rubik_.isSolved())  break;
        }
        return moves_;
    };

private:
    T &rubik_;
    int max_search_depth_;
    vector<typename T::MOVE> moves_;
};

#endif //IDDFSSOLVER_H
