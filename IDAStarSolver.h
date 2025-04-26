//
// Created by Aniket Gupta on 24-04-2025.
//

#ifndef IDASTARSOLVER_H
#define IDASTARSOLVER_H

#include "bits/stdc++.h"

using namespace  std;

template<typename T, typename X>
class IDAStarSolver {
public:
    IDAStarSolver(T& rubik) : rubik_(rubik) {};

    vector<typename T::MOVE> solve() {
        Node src = Node(rubik_, 0);
        cur_max_depth_ = 1, next_depth_ = 100;

        while (!IDAStar(src)) {
            cur_max_depth_ = next_depth_;
        }
        return moves_;
    }
private:
    T& rubik_;
    int cur_max_depth_ = 1, next_depth_ = 100;
    vector<typename T::MOVE> moves_;
    unordered_map<T, typename T::MOVE, X> parent_move_;
    struct Node {
        T cube;
        int gn, hn;
        Node (T c, int g = 0, int h = 0) : cube(c), gn(g), hn(h) {};
    };

    struct myComp {
      bool operator()(const Node &p1, const Node &p2) {
          if (p1.gn + p1.hn == p2.gn + p2.hn)
              return p1.hn > p2.hn;
          return p1.gn + p1.hn > p2.gn + p2.hn;
      }
    };

    /**
     * @return:  whether cube is solved or not,
     *           if SOLVED: fills the vector<moves_> and returns 1;
     *           else: returns 0;
     */
    bool IDAStar(Node src) {
        unordered_map<T, bool, X> visited_;
        priority_queue<Node, vector<Node>, myComp> pq;

        pq.push(src);

        while (!pq.empty()) {
            Node node = pq.top();    pq.pop();

            if (visited_[node.cube]) continue;
            visited_[node.cube] = true;

            for (int i = 0; i < 18; i++) {
                Node v = Node(node.cube, node.gn + 1);

                v.cube.move(typename T::MOVE(i));

                if (v.cube.isSolved()) {
                    parent_move_[v.cube] = typename T::MOVE(i);
                    getPath(v);
                    return true;
                }

                if (!visited_[v.cube]) {
                    if (v.gn + v.hn <= cur_max_depth_) {
                        parent_move_[v.cube] = typename T::MOVE(i);
                        pq.push(v);
                    }
                    else {
                        next_depth_ = min(next_depth_, v.gn + v.hn);
                    }
                }
            }
        }
        return false;
    }

    void getPath(Node v) {
        while (!(v.cube == rubik_)) {
            moves_.push_back(parent_move_[v.cube]);
            v.cube.revertMove(parent_move_[v.cube]);
        }
        rubik_= v.cube;
        reverse(moves_.begin(), moves_.end());
    }

};

#endif //IDASTARSOLVER_H
