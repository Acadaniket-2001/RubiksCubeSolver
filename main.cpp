//
// Created by Aniket Gupta on 22-04-2025.
//


#include <bits/stdc++.h>
#include "RubiksCube3dArray.cpp"
#include "RubiksCube1dArray.cpp"
#include "RubiksCubeBitboard.cpp"

using namespace std;

int main () {

    RubiksCubeBitboard obj;
    vector<RubiksCubeBitboard::MOVE> moves = obj.randomShuffleCube(10);

    for (auto e : moves) {
        cout << obj.getMove(e) << " ";
    }

    cout << endl;
    obj.print();



























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