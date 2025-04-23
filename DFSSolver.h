//
// Created by Aniket Gupta on 23-04-2025.
//

#ifndef DFSSOLVER_H
#define DFSSOLVER_H

#include "bits/stdc++.h"

using namespace std;

template<typename T, typename X>
class DFSSolver {
public:

    DFSSolver(T &rubik, int max_search_depth = 8) :
        rubik_(rubik), max_search_depth_(max_search_depth) {};

    vector<typename T::MOVE> solve() {
        rec(max_search_depth_);
        return moves_;
    };


private:
    T &rubik_;
    int max_search_depth_;
    vector<typename T::MOVE> moves_;

    /**
     * visited map is removed to ensure that we always find the solution, @ the cost of more time
     **/
    // unordered_map<T, bool, X> visited_;
    void rec(int rem_depth) {
        if (rem_depth == 0 || rubik_.isSolved()) return;

        // visited_[rubik_] = true;

        for (int i = 0; i < 18; i++) {
            rubik_.move(typename T::MOVE(i));
            moves_.push_back(typename T::MOVE(i));

            // if (!visited_[rubik_]) {
                rec(rem_depth - 1);
                if (rubik_.isSolved()) return;
            // }
            rubik_.revertMove(typename T::MOVE(i));
            moves_.pop_back();
        }
    }
};

#endif //DFSSOLVER_H
