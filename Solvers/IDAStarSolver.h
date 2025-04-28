//
// Created by ANIKET GUPTA on 24-04-2025.
// Version: 2.0

#ifndef IDASTARSOLVER_H
#define IDASTARSOLVER_H

#include<bits/stdc++.h>
#include "../Models/RubiksCube.h"
#include "../PatternDatabases/CornerPatternDatabase.h"


template<typename T, typename H>
class IDAStarSolver {
private:
    CornerPatternDatabase cornerDB;
    vector<RubiksCube::MOVE> moves;
    unordered_map<T, RubiksCube::MOVE, H> move_done;
    unordered_map<T, bool, H> visited;

    struct Node {
        T cube;
        int depth;
        int estimate;

        Node(T _cube, int _depth, int _estimate) : cube(_cube), depth(_depth), estimate(_estimate) {};
    };

    struct compareCube {
        bool operator()(pair<Node, int> const &p1, pair<Node, int> const &p2) {
            auto n1 = p1.first, n2 = p2.first;
            if (n1.depth + n1.estimate == n2.depth + n2.estimate) {
                return n1.estimate > n2.estimate;
            } else return n1.depth + n1.estimate > n2.depth + n2.estimate;
        }
    };

    void resetStructure() {
        moves.clear();
        move_done.clear();
        visited.clear();
    }

// returns {solved cube, bound}: if the cube was solved
// returns {rubiksCube, next_bound}, if the cube was not solved
    pair<T, int> IDAstar(int bound) {
//        priority_queue contains pair(Node, move done to reach that)
        priority_queue<pair<Node, int>, vector<pair<Node, int>>, compareCube> pq;
        Node start = Node(rubiksCube, 0, cornerDB.getHeuristic(rubiksCube));
        pq.push(make_pair(start, 0));
        int next_bound = 100;
        while (!pq.empty()) {
            auto p = pq.top();
            Node node = p.first;
            pq.pop();

            if (visited[node.cube]) continue;

            visited[node.cube] = true;
            move_done[node.cube] = RubiksCube::MOVE(p.second);

            if (node.cube.isSolved()) return make_pair(node.cube, bound);
            node.depth++;
            for (int i = 0; i < 18; i++) {
                auto curr_move = RubiksCube::MOVE(i);
                node.cube.move(curr_move);
                if (!visited[node.cube]) {
                    node.estimate = cornerDB.getHeuristic(node.cube);
                    if (node.estimate + node.depth > bound) {
                        next_bound = min(next_bound, node.estimate + node.depth);
                    } else {
                        pq.push(make_pair(node, i));
                    }
                }
                node.cube.revertMove(curr_move);
            }

        }
        return make_pair(rubiksCube, next_bound);
    }

public:
    T rubiksCube;

    IDAStarSolver(T _rubiksCube, string fileName) {
        rubiksCube = _rubiksCube;
        cornerDB.fromFile(fileName);
    }

    vector<RubiksCube::MOVE> solve() {
        int bound = 1;
        auto p = IDAstar(bound);
        while (p.second != bound) {
            resetStructure();
            bound = p.second;
            p = IDAstar(bound);
        }
        T solved_cube = p.first;
        assert(solved_cube.isSolved());
        T curr_cube = solved_cube;
        while (!(curr_cube == rubiksCube)) {
            RubiksCube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.revertMove(curr_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif // IDASTARSOLVER_H






// //
// // Created by Aniket Gupta on 24-04-2025.
// // Version: 1.0
//
// #ifndef IDASTARSOLVER_H
// #define IDASTARSOLVER_H
//
// #include "bits/stdc++.h"
// #include "../PatternDatabases/CornerPatternDatabase.h"
//
// using namespace  std;
//
// template<typename T, typename X>
// class IDAStarSolver {
// public:
//     T& rubik_;
//
//     IDAStarSolver(T& rubik, const string& filename) : rubik_(rubik) {
//         cornerDB.fromFile(filename);
//     };
//
//     vector<typename T::MOVE> solve() {
//         Node src = Node(rubik_, 0, cornerDB.getHeuristic(rubik_));
//
//         cur_max_depth_ = 1, next_depth_ = 100;
//         while (!IDAStar(src)) {
//             resetStructure();
//             cur_max_depth_ = next_depth_;
//         }
//         return moves_;
//     }
// private:
//     int cur_max_depth_ = 1, next_depth_ = 100;
//     CornerPatternDatabase cornerDB;
//
//     vector<typename T::MOVE> moves_;
//     unordered_map<T, typename T::MOVE, X> parent_move_;
//
//     struct Node {
//         T cube;
//         int gn, hn;
//         Node (T c, int g, int h = 0) : cube(c), gn(g), hn(h) {};
//     };
//
//     struct myComp {
//       bool operator()(const Node &p1, const Node &p2) {
//           if (p1.gn + p1.hn == p2.gn + p2.hn)
//               return p1.hn > p2.hn;
//           return p1.gn + p1.hn > p2.gn + p2.hn;
//       }
//     };
//
//     /**
//      * @return:  whether cube is solved or not,
//      *           if SOLVED: fills the vector<moves_> and returns 1;
//      *           else: returns 0;
//      */
//     bool IDAStar(Node src) {
//         unordered_map<T, bool, X> visited_;
//         priority_queue<Node, vector<Node>, myComp> pq;
//
//         pq.push(src);
//
//         while (!pq.empty()) {
//             Node node = pq.top();    pq.pop();
//
//             if (visited_[node.cube]) continue;
//             visited_[node.cube] = true;
//
//             node.gn++;
//             for (int i = 0; i < 18; i++) {
//
//                 node.cube.move(typename T::MOVE(i));
//                 node.hn = cornerDB.getHeuristic(node.cube);
//
//                 if (node.hn == 0) {   // ⭐⭐⭐ done optimisation
//                     parent_move_[node.cube] = typename T::MOVE(i);
//                     getPath(node);
//                     return true;
//                 }
//
//                 if (!visited_[node.cube]) {
//                     if (node.gn + node.hn <= cur_max_depth_) {
//                         parent_move_[node.cube] = typename T::MOVE(i);
//                         pq.push(node);
//                     }
//                     else {
//                         next_depth_ = min(next_depth_, node.gn + node.hn);
//                     }
//                 }
//
//                 node.cube.revertMove(typename T::MOVE(i));
//             }
//         }
//         return false;
//     }
//
//     void getPath(Node v) {
//         while (!(v.cube == rubik_)) {
//             moves_.push_back(parent_move_[v.cube]);
//             v.cube.revertMove(parent_move_[v.cube]);
//         }
//         reverse(moves_.begin(), moves_.end());
//
//         for (auto e: moves_)    rubik_.move(e);
//     }
//
//     void resetStructure() {
//         moves_.clear();
//         parent_move_.clear();
//     }
// };
//
// #endif //IDASTARSOLVER_H



