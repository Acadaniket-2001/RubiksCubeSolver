//
// Created by Aniket Gupta on 20-04-2025.
//

#include "RubiksCube.h"

char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::WHITE:
            return 'W';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::BLUE:
            return 'B';
        case COLOR::ORANGE:
            return 'O';
        default:
            return 'Y';
    }
};

void RubiksCube::move(const RubiksCube::MOVE mv) {
    switch (mv) {
        case RubiksCube::MOVE::L:
            this -> l(); break;
        case RubiksCube::MOVE::LPRIME:
            this -> lPrime(); break;
        case RubiksCube::MOVE::L2:
            this ->l2(); break;

        case RubiksCube::MOVE::R:
            this -> r(); break;
        case RubiksCube::MOVE::RPRIME:
            this -> rPrime(); break;
        case RubiksCube::MOVE::R2:
            this ->r2(); break;

        case RubiksCube::MOVE::U:
            this -> u(); break;
        case RubiksCube::MOVE::UPRIME:
            this -> uPrime(); break;
        case RubiksCube::MOVE::U2:
            this ->u2(); break;

        case RubiksCube::MOVE::D:
            this -> d(); break;
        case RubiksCube::MOVE::DPRIME:
            this -> dPrime(); break;
        case RubiksCube::MOVE::D2:
            this ->d2(); break;

        case RubiksCube::MOVE::F:
            this -> f(); break;
        case RubiksCube::MOVE::FPRIME:
            this -> fPrime(); break;
        case RubiksCube::MOVE::F2:
            this ->f2(); break;

        case RubiksCube::MOVE::B:
            this -> b(); break;
        case RubiksCube::MOVE::BPRIME:
            this -> bPrime(); break;
        case RubiksCube::MOVE::B2:
            this ->b2(); break;
    }
}

void RubiksCube::revertMove(const RubiksCube::MOVE mv) {
    switch (mv) {
        case RubiksCube::MOVE::L:
            this -> lPrime(); break;
        case RubiksCube::MOVE::LPRIME:
            this -> l(); break;
        case RubiksCube::MOVE::L2:
            this ->l2(); break;

        case RubiksCube::MOVE::R:
            this -> rPrime(); break;
        case RubiksCube::MOVE::RPRIME:
            this -> r(); break;
        case RubiksCube::MOVE::R2:
            this ->r2(); break;

        case RubiksCube::MOVE::U:
            this -> uPrime(); break;
        case RubiksCube::MOVE::UPRIME:
            this -> u(); break;
        case RubiksCube::MOVE::U2:
            this ->u2(); break;

        case RubiksCube::MOVE::D:
            this -> dPrime(); break;
        case RubiksCube::MOVE::DPRIME:
            this -> d(); break;
        case RubiksCube::MOVE::D2:
            this ->d2(); break;

        case RubiksCube::MOVE::F:
            this -> fPrime(); break;
        case RubiksCube::MOVE::FPRIME:
            this -> f(); break;
        case RubiksCube::MOVE::F2:
            this ->f2(); break;

        case RubiksCube::MOVE::B:
            this -> bPrime(); break;
        case RubiksCube::MOVE::BPRIME:
            this -> b(); break;
        case RubiksCube::MOVE::B2:
            this ->b2(); break;
    }
}

void RubiksCube::print() const {
    cout << "RUBIK's CUBE:\n\n";

    // face 0
    for (int i = 0; i < 3; i++) {
        for (int space = 0; space < 3; space++)     cout << "  ";
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << getColorLetter(getColor(FACE::UP, i, j)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // face 1 -> 2 -> 3 -> 4
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << getColorLetter(getColor(FACE::LEFT, i, j)) << " ";
        cout << " ";
        for (int j = 0; j < 3; j++) cout << getColorLetter(getColor(FACE::FRONT, i, j)) << " ";
        cout << " ";
        for (int j = 0; j < 3; j++) cout << getColorLetter(getColor(FACE::RIGHT, i, j)) << " ";
        cout << " ";
        for (int j = 0; j < 3; j++) cout << getColorLetter(getColor(FACE::BACK, i, j)) << " ";
        cout << "\n";
    }
    cout << "\n";

    // face 5
    for (int i = 0; i < 3; i++) {
        for (int space = 0; space < 3; space++)     cout << "  ";
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << getColorLetter(getColor(FACE::DOWN, i, j)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";

}