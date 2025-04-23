//
// Created by KIIT on 23-04-2025.
//

#ifndef BFSSOLVER_H
#define BFSSOLVER_H

#include "bits/stdc++.h"

using namespace std;

template<typename T, typename X>
class BFSSolver {
public:
    BFSSolver(T &rubik) : rubik_(rubik) {};

    vector<typename T::MOVE> solve() {
        bfs();
        return moves_;
    };

private:
    T &rubik_;
    vector<typename T::MOVE> moves_;

    /**
     * <current_node, <parent_node, move_idx>, Hash>:
     *  although we can work around by just storing MOVES as back pointer
     *  and using revertMove() in getPath() to get sequence of moves
     */
    unordered_map<T, pair<T, typename T::MOVE>, X> parent_;

    void bfs() {
        queue<T> q;
        q.push(rubik_);
        parent_[rubik_] = {rubik_,typename T::MOVE(0)};

        while (!q.empty()) {
            auto node = q.front(); q.pop();

            for (int i = 0; i < 18; i++) {
                auto temp = node;
                node.move(typename T::MOVE(i));

                if (parent_.find(node) == parent_.end()) {
                    parent_[node] = {temp, typename T::MOVE(i)};

                    if (node.isSolved()) {
                        getPath(node);
                        return;
                    }

                    q.push(node);
                }

                node.revertMove(typename T::MOVE(i));
            }
        }
    }

    void getPath(T node) {
        if (parent_[node].first == node)  return;
        getPath(parent_[node].first);
        moves_.push_back(parent_[node].second);
    }
};


#endif //BFSSOLVER_H
















