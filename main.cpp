//
// Created by Aniket Gupta on 22-04-2025.
//


#include <bits/stdc++.h>

#include "Solvers/IDAStarSolver.h"
#include "Solvers/IDDFSSolver.h"
#include "Solvers/BFSSolver.h"
#include "Solvers/DFSSolver.h"
#include "Models/RubiksCube3dArray.cpp"
#include "Models/RubiksCube1dArray.cpp"
#include "Models/RubiksCubeBitboard.cpp"
#include "PatternDatabases/CornerDBMaker.h"

using namespace std;

int main () {

    // IDA* Solver Testing --------------------------------------------------------------------------

    string fileName = "C:\\1_My_Data\\CP_codes\\RubiksCubeSolver\\Databases\\CornerDB.txt";

    // Code to create Corner Database
    CornerDBMaker dbMaker(fileName, 0xAA);
    // dbMaker.bfsAndStore(9);

    RubiksCubeBitboard cube;
    auto shuffleMoves = cube.randomShuffleCube(11);
    for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    cout << "\n\n";

    IDAStarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    auto moves = idaStarSolver.solve();

    for (auto move: moves) cout << cube.getMove(move) << " ";

























    // // IDA* Solver Testing --------------------------------------------------------------------------
    //
    // string fileName = "C:\\1_My_Data\\CP_codes\\RubiksCubeSolver\\Databases\\CornerDB.txt";
    //
    // // Code to create Corner Database
    // CornerDBMaker dbMaker(fileName, 0xAA);
    // // dbMaker.bfsAndStore(9);
    //
    // RubiksCubeBitboard cube;
    // auto shuffleMoves = cube.randomShuffleCube(11);
    // cout << "Shuffling Moves: ";
    // for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    // cout << "\n\n";
    // cube.print();
    // cout << (cube.isSolved() ? "SOLVED" : "NOT SOLVED\n") << endl;
    //
    // cout << "--------------------------------------\n\n";
    //
    // IDAStarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    // auto moves = idaStarSolver.solve();
    //
    // cout << "Solving Moves: ";
    // for (auto move: moves) cout << cube.getMove(move) << " ";
    // cout << "\n\n";
    // idaStarSolver.rubiksCube.print();
    // cout << (idaStarSolver.rubiksCube.isSolved() ? "SOLVED" : "NOT SOLVED\n") << endl;
    //
    // /**  IDA* Solver Test Results:
    //  *  ------------------------------------------------------------------------------------
    //  *    DB_Depth             DBMakeTime                #shuffles
    //  *  ------------------------------------------------------------------------------------
    //  *    6                    [1-2]min.                 <= 8 (quickly)
    //  *  ------------------------------------------------------------------------------------
    //  *    7                    [2-3]min.                 <= 9 (quickly)
    //  *  ------------------------------------------------------------------------------------
    //  *    8                    ~10 min.                  <=10 (quickly),
    //  *                                                   =11 (some shuffles take few min.)
    //  *  ------------------------------------------------------------------------------------
    //  *    9                    [25-30]min.               <=11 (quickly)
    //  *  ------------------------------------------------------------------------------------
    //  */




    // // CornerPatternDatabase Testing ---------------------------------------------------------------------------------
    //
    //    CornerPatternDatabase cornerDB;
    //    RubiksCubeBitboard cube;
    //    cube.print();
    //
    //    cout << (int)cornerDB.getHeuristic(cube) << "\n";
    //
    //    cornerDB.setHeuristic(cube, 5);
    //
    //    cout << (int)cornerDB.getHeuristic(cube) << "\n";
    //
    //    cube.randomShuffleCube(1);
    //    cube.print();
    //    cout << (int)cornerDB.getHeuristic(cube) << "\n";
    //
    //    cornerDB.setHeuristic(cube, 6);
    //
    //    cout << (int)cornerDB.getHeuristic(cube) << "\n";




    // // Testing IDDFSSolver: ----------------------------------------------------------------------------------------------
    //
    // RubiksCubeBitboard obj;
    // obj.print();
    //
    // vector<RubiksCubeBitboard::MOVE> steps = obj.randomShuffleCube(6);
    // for (auto e: steps)    cout << obj.getMove(e) << " ";
    // cout << endl;
    // obj.print();
    //
    // IDDFSSolver<RubiksCubeBitboard, HashBitboard> solver(obj);
    // vector<RubiksCubeBitboard::MOVE> moves = solver.solve();
    //
    // for (const auto e: moves)    cout << obj.getMove(e) << " ";
    // cout << endl;
    // obj.print();




    // // Testing DFSSolver: ----------------------------------------------------------------------------------------------
    //
    // /*
    //  * Solves within feasible time for upto depth:
    //  * 6 - In 3d/1d form
    //  * 7 - In BitBoard form
    //  */
    //
    // RubiksCubeBitboard obj;
    // obj.print();
    //
    // vector<RubiksCubeBitboard::MOVE> steps = obj.randomShuffleCube(6);
    // for (auto e: steps)    cout << obj.getMove(e) << " ";
    // cout << endl;
    // obj.print();
    //
    // BFSSolver<RubiksCubeBitboard, HashBitboard> solver(obj);
    // vector<RubiksCubeBitboard::MOVE> moves = solver.solve();
    //
    // for (const auto e: moves)    cout << obj.getMove(e) << " ";
    // cout << endl;
    // obj.print();




    // // Testing DFSSolver: ----------------------------------------------------------------------------------------------
    //
    // /*
    //  * Solves within feasible time for upto depth 6
    //  */
    //
    // RubiksCubeBitboard obj;
    // obj.print();
    //
    // vector<RubiksCubeBitboard::MOVE> steps = obj.randomShuffleCube(6);
    // for (auto e: steps)    cout << obj.getMove(e) << " ";
    // cout << endl;
    // obj.print();
    //
    // DFSSolver<RubiksCubeBitboard, Hash3d> solver(obj, 8);
    // vector<RubiksCubeBitboard::MOVE> moves = solver.solve();
    //
    // for (const auto e: moves)    cout << obj.getMove(e) << " ";
    // cout << endl;
    // obj.print();




    // // Testing custom Hashes for the RubiksCubeSolver ------------------------------------------------------------------
    //
    // unordered_map<RubiksCube3dArray, int, Hash3d> mp;
    // RubiksCube3dArray obj1;
    // obj1.l();
    // mp[obj1] = 200;
    // if (mp[obj1])   cout << "3D Cube found\n";
    //
    // obj1.u();
    // mp[obj1] = 1000;
    // if (mp[obj1])   cout << "3D Cube found\n";
    //
    //
    // unordered_map<RubiksCube1dArray, int, Hash1d> m2;
    // RubiksCube1dArray obj2;
    // obj2.l();
    // m2[obj2] = 200;
    // if (m2[obj2])   cout << "1D Cube found\n";
    //
    // obj2.u();
    // m2[obj2] = 1000;
    // if (m2[obj2])   cout << "1D Cube found\n";
    //
    //
    // unordered_map<RubiksCubeBitboard, int, HashBitboard> m3;
    // RubiksCubeBitboard obj3;
    // obj3.l();
    // m3[obj3] = 200;
    // if (m3[obj3])   cout << "BitCube found\n";
    //
    // obj2.u();
    // m3[obj3] = 1000;
    // if (m3[obj3])   cout << "BitCube found\n";




    // // Testing randomShuffleCube() -------------------------------------------------------------------------------------
    //
    // RubiksCubeBitboard obj;
    // vector<RubiksCubeBitboard::MOVE> moves = obj.randomShuffleCube(10);
    // for (auto e : moves) {
    //     cout << obj.getMove(e) << " ";
    // }
    // cout << endl;
    // obj.print();


    // // Testing BIT-MODEL -----------------------------------------------------------------------------------------------
    //
    // RubiksCubeBitboard obj1;
    // obj1.print();
    // cout << (obj1.isSolved() ? "SOLVED" : "!SOLVED") << endl;
    //
    // obj1.move(RubiksCube::MOVE::L);
    // obj1.move(RubiksCube::MOVE::LPRIME);
    // obj1.move(RubiksCube::MOVE::L2);
    // obj1.move(RubiksCube::MOVE::R);
    // obj1.move(RubiksCube::MOVE::RPRIME);
    // obj1.move(RubiksCube::MOVE::R2);
    // obj1.move(RubiksCube::MOVE::U);
    // obj1.move(RubiksCube::MOVE::UPRIME);
    // obj1.move(RubiksCube::MOVE::U2);
    // obj1.move(RubiksCube::MOVE::D);
    // obj1.move(RubiksCube::MOVE::DPRIME);
    // obj1.move(RubiksCube::MOVE::D2);
    // obj1.move(RubiksCube::MOVE::F);
    // obj1.move(RubiksCube::MOVE::FPRIME);
    // obj1.move(RubiksCube::MOVE::F2);
    // obj1.move(RubiksCube::MOVE::B);
    // obj1.move(RubiksCube::MOVE::BPRIME);
    // obj1.move(RubiksCube::MOVE::B2);
    // obj1.print();
    // cout << (obj1.isSolved() ? "SOLVED" : "!SOLVED") << endl;
    //
    // obj1.move(RubiksCube::MOVE::B2);
    // obj1.move(RubiksCube::MOVE::BPRIME);
    // obj1.move(RubiksCube::MOVE::B);
    // obj1.move(RubiksCube::MOVE::F2);
    // obj1.move(RubiksCube::MOVE::FPRIME);
    // obj1.move(RubiksCube::MOVE::F);
    // obj1.move(RubiksCube::MOVE::D2);
    // obj1.move(RubiksCube::MOVE::DPRIME);
    // obj1.move(RubiksCube::MOVE::D);
    // obj1.move(RubiksCube::MOVE::U2);
    // obj1.move(RubiksCube::MOVE::UPRIME);
    // obj1.move(RubiksCube::MOVE::U);
    // obj1.move(RubiksCube::MOVE::R2);
    // obj1.move(RubiksCube::MOVE::RPRIME);
    // obj1.move(RubiksCube::MOVE::R);
    // obj1.move(RubiksCube::MOVE::L2);
    // obj1.move(RubiksCube::MOVE::LPRIME);
    // obj1.move(RubiksCube::MOVE::L);
    // obj1.print();
    // cout << (obj1.isSolved() ? "SOLVED" : "!SOLVED") << endl;




    // // Testing 1D-MODEL ------------------------------------------------------------------------------------------------
    //
    // RubiksCube1dArray obj;
    // obj.print();
    //
    // obj.move(RubiksCube::MOVE::L);
    // obj.move(RubiksCube::MOVE::LPRIME);
    // obj.move(RubiksCube::MOVE::L2);
    // obj.move(RubiksCube::MOVE::R);
    // obj.move(RubiksCube::MOVE::RPRIME);
    // obj.move(RubiksCube::MOVE::R2);
    // obj.move(RubiksCube::MOVE::U);
    // obj.move(RubiksCube::MOVE::UPRIME);
    // obj.move(RubiksCube::MOVE::U2);
    // obj.move(RubiksCube::MOVE::D);
    // obj.move(RubiksCube::MOVE::DPRIME);
    // obj.move(RubiksCube::MOVE::D2);
    // obj.move(RubiksCube::MOVE::F);
    // obj.move(RubiksCube::MOVE::FPRIME);
    // obj.move(RubiksCube::MOVE::F2);
    // obj.move(RubiksCube::MOVE::B);
    // obj.move(RubiksCube::MOVE::BPRIME);
    // obj.move(RubiksCube::MOVE::B2);
    // obj.print();
    // cout << (obj.isSolved() ? "SOLVED" : "!SOLVED") << endl;
    //
    // obj.move(RubiksCube::MOVE::B2);
    // obj.move(RubiksCube::MOVE::BPRIME);
    // obj.move(RubiksCube::MOVE::B);
    // obj.move(RubiksCube::MOVE::F2);
    // obj.move(RubiksCube::MOVE::FPRIME);
    // obj.move(RubiksCube::MOVE::F);
    // obj.move(RubiksCube::MOVE::D2);
    // obj.move(RubiksCube::MOVE::DPRIME);
    // obj.move(RubiksCube::MOVE::D);
    // obj.move(RubiksCube::MOVE::U2);
    // obj.move(RubiksCube::MOVE::UPRIME);
    // obj.move(RubiksCube::MOVE::U);
    // obj.move(RubiksCube::MOVE::R2);
    // obj.move(RubiksCube::MOVE::RPRIME);
    // obj.move(RubiksCube::MOVE::R);
    // obj.move(RubiksCube::MOVE::L2);
    // obj.move(RubiksCube::MOVE::LPRIME);
    // obj.move(RubiksCube::MOVE::L);
    // obj.print();
    // cout << (obj.isSolved() ? "SOLVED" : "!SOLVED") << endl;




    // // Testing 3D-MODEL ------------------------------------------------------------------------------------------------

    // RubiksCube3dArray obj;
    // obj.print();
    //
    // obj.move(RubiksCube::MOVE::L);
    // obj.move(RubiksCube::MOVE::LPRIME);
    // obj.move(RubiksCube::MOVE::L2);
    // obj.move(RubiksCube::MOVE::R);
    // obj.move(RubiksCube::MOVE::RPRIME);
    // obj.move(RubiksCube::MOVE::R2);
    // obj.move(RubiksCube::MOVE::U);
    // obj.move(RubiksCube::MOVE::UPRIME);
    // obj.move(RubiksCube::MOVE::U2);
    // obj.move(RubiksCube::MOVE::D);
    // obj.move(RubiksCube::MOVE::DPRIME);
    // obj.move(RubiksCube::MOVE::D2);
    // obj.move(RubiksCube::MOVE::F);
    // obj.move(RubiksCube::MOVE::FPRIME);
    // obj.move(RubiksCube::MOVE::F2);
    // obj.move(RubiksCube::MOVE::B);
    // obj.move(RubiksCube::MOVE::BPRIME);
    // obj.move(RubiksCube::MOVE::B2);
    // obj.print();
    // cout << (obj.isSolved() ? "SOLVED" : "!SOLVED") << endl;
    //
    // obj.move(RubiksCube::MOVE::B2);
    // obj.move(RubiksCube::MOVE::BPRIME);
    // obj.move(RubiksCube::MOVE::B);
    // obj.move(RubiksCube::MOVE::F2);
    // obj.move(RubiksCube::MOVE::FPRIME);
    // obj.move(RubiksCube::MOVE::F);
    // obj.move(RubiksCube::MOVE::D2);
    // obj.move(RubiksCube::MOVE::DPRIME);
    // obj.move(RubiksCube::MOVE::D);
    // obj.move(RubiksCube::MOVE::U2);
    // obj.move(RubiksCube::MOVE::UPRIME);
    // obj.move(RubiksCube::MOVE::U);
    // obj.move(RubiksCube::MOVE::R2);
    // obj.move(RubiksCube::MOVE::RPRIME);
    // obj.move(RubiksCube::MOVE::R);
    // obj.move(RubiksCube::MOVE::L2);
    // obj.move(RubiksCube::MOVE::LPRIME);
    // obj.move(RubiksCube::MOVE::L);
    // obj.print();
    // cout << (obj.isSolved() ? "SOLVED" : "!SOLVED") << endl;


    return 0;
}