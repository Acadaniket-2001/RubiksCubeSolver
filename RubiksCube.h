//
// Created by Aniket Gupta on 20-04-2025.
//


#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

class RubiksCube {
public:
    virtual ~RubiksCube() = default;

    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };


    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    static char getColorLetter(COLOR color);

    void print() const;


    virtual bool isSolved() = 0;


    void move(MOVE mv);
    void revertMove(MOVE mv);


    virtual RubiksCube& u() = 0;
    virtual RubiksCube& uPrime() = 0;
    virtual RubiksCube& u2() = 0;

    virtual RubiksCube& l() = 0;
    virtual RubiksCube& lPrime() = 0;
    virtual RubiksCube& l2() = 0;

    virtual RubiksCube& f() = 0;
    virtual RubiksCube& fPrime() = 0;
    virtual RubiksCube& f2() = 0;

    virtual RubiksCube& r() = 0;
    virtual RubiksCube& rPrime() = 0;
    virtual RubiksCube& r2() = 0;

    virtual RubiksCube& b() = 0;
    virtual RubiksCube& bPrime() = 0;
    virtual RubiksCube& b2() = 0;

    virtual RubiksCube& d() = 0;
    virtual RubiksCube& dPrime() = 0;
    virtual RubiksCube& d2() = 0;

    // vector<MOVE> randomShuffleCube(unsigned int times);
};

#endif //RUBIKSCUBE_H
