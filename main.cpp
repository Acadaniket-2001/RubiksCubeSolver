//
// Created by Aniket Gupta on 22-04-2025.
//


#include <bits/stdc++.h>

#include "BFSSolver.h"
#include "DFSSolver.h"
#include "RubiksCube3dArray.cpp"
#include "RubiksCube1dArray.cpp"
#include "RubiksCubeBitboard.cpp"

using namespace std;

int main () {

































    // Testing DFSSolver: ----------------------------------------------------------------------------------------------

    /*
     * Solves within feasible time for upto depth:
     * 6 - In 3d/1d form
     * 7 - In BitBoard form
     */

    // RubiksCubeBitboard obj;
    // obj.print();
    //
    // vector<RubiksCubeBitboard::MOVE> steps = obj.randomShuffleCube(7);
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




    // Testing DFSSolver: ----------------------------------------------------------------------------------------------

    /*
     * Solves within feasible time for upto depth 6
     */

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




    // Testing custom Hashes for the RubiksCubeSolver ------------------------------------------------------------------

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




    // Testing randomShuffleCube() -------------------------------------------------------------------------------------

    // RubiksCubeBitboard obj;
    // vector<RubiksCubeBitboard::MOVE> moves = obj.randomShuffleCube(10);
    // for (auto e : moves) {
    //     cout << obj.getMove(e) << " ";
    // }
    // cout << endl;
    // obj.print();


    // Testing BIT-MODEL -----------------------------------------------------------------------------------------------

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