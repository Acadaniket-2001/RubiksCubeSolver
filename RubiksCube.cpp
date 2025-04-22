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
}

string RubiksCube::getMove(RubiksCube::MOVE mv) {
    switch (mv) {
        case RubiksCube::MOVE::L: return "L";
        case RubiksCube::MOVE::LPRIME: return "L'";
        case RubiksCube::MOVE::L2: return "L2";

        case RubiksCube::MOVE::R: return "R";
        case RubiksCube::MOVE::RPRIME: return "R'";
        case RubiksCube::MOVE::R2: return "R2";

        case RubiksCube::MOVE::U: return "U";
        case RubiksCube::MOVE::UPRIME: return "U'";
        case RubiksCube::MOVE::U2: return "U2";

        case RubiksCube::MOVE::D: return "D";
        case RubiksCube::MOVE::DPRIME: return "D'";
        case RubiksCube::MOVE::D2: return "D2";

        case RubiksCube::MOVE::F: return "F";
        case RubiksCube::MOVE::FPRIME: return "F'";
        case RubiksCube::MOVE::F2: return "F2";

        case RubiksCube::MOVE::B: return "B";
        case RubiksCube::MOVE::BPRIME: return "B'";
        case RubiksCube::MOVE::B2: return "B2";
    }
}

RubiksCube& RubiksCube::move(const RubiksCube::MOVE mv) {
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
    return *this;
}

RubiksCube& RubiksCube::revertMove(const RubiksCube::MOVE mv) {
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
    return *this;
}


vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(unsigned int times) {

    srand(time(0));

    vector<RubiksCube::MOVE> moves;
    for (unsigned int i = 0; i < times; i++) {
        int idx = rand() % 18;
        moves.push_back(static_cast<RubiksCube::MOVE>(idx));
        this->move(RubiksCube::MOVE(idx));
    }

    return moves;
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