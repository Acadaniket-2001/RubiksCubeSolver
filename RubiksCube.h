//
// Created by KIIT on 20-04-2025.
//

#include "bits/stdc++.h"

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H


class RubiksCube {
public:
    enum FACE {
        FRONT, BACK,
        UP, DOWN,
        LEFT, RIGHT
    };

    enum COLOR {
        BLUE,
        GREEN,
        YELLOW,
        ORANGE,
        RED,
        WHITE
    };

    enum MOVE {
        F, FPRIME, F2,
        B, BPRIME, B2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        L, LPRIME, L2,
        R, RPRIME, R2
    };


    virtual RubiksCube& f() = 0;
    virtual RubiksCube& fPrime() = 0;
    virtual RubiksCube& f2() = 0;

    virtual RubiksCube& b() = 0;
    virtual RubiksCube& bPrime() = 0;
    virtual RubiksCube& b2() = 0;

    virtual RubiksCube& u() = 0;
    virtual RubiksCube& uPrime() = 0;
    virtual RubiksCube& u2() = 0;

    virtual RubiksCube& d() = 0;
    virtual RubiksCube& dPrime() = 0;
    virtual RubiksCube& d2() = 0;

    virtual RubiksCube& l() = 0;
    virtual RubiksCube& lPrime() = 0;
    virtual RubiksCube& l2() = 0;

    virtual RubiksCube& r() = 0;
    virtual RubiksCube& rPrime() = 0;
    virtual RubiksCube& r2() = 0;

    RubiksCube& move(MOVE ind);
    RubiksCube& invert(MOVE ind);


    virtual COLOR getColor(FACE face, unsigned row, unsigned col) = 0;
    void print() const;

    vector<MOVE> randomShuffleCube(unsigned int times);

    virtual bool isSolved() = 0;
};


#endif //RUBIKSCUBE_H
