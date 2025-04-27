//
// Created by Aniket Gupta on 21-04-2025.
//

#include "RubiksCube.h"

class RubiksCube1dArray : public RubiksCube {
private:
    void rotateFace(int fid) {
        int n = 3;
        for(int i =0; i <= n/2 - 1; i++) {
            for(int j =0;  j<= n/2; j++) {
                char temp = cube[getIndex(fid, i,j )];
                cube[getIndex(fid, i,j )] = cube[getIndex(fid, n-j-1, i)];
                cube[getIndex(fid, n-j-1, i)] = cube[getIndex(fid, n-i-1, n-j-1)];
                cube[getIndex(fid, n-i-1, n-j-1)] = cube[getIndex(fid, j, n-i-1)];
                cube[getIndex(fid, j, n-i-1)] = temp;
            }
        }
    }

    static int getIndex(int face, int row, int col) {
        return face * 9 + row * 3 + col;
    };

public:
    char cube[54];

    RubiksCube1dArray() {
        for (int face = 0; face < 6; face++) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    cube[getIndex(face, row, col)] = getColorLetter(COLOR(face));
                }
            }
        }
    };

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char ch = cube[getIndex(int(face), (int)row, (int)col)];

        if (ch == 'W')    return COLOR::WHITE;
        else if (ch == 'G')    return COLOR::GREEN;
        else if (ch == 'R')    return COLOR::RED;
        else if (ch == 'B')    return COLOR::BLUE;
        else if (ch == 'O')    return COLOR::ORANGE;
        else    return COLOR::YELLOW;
    }

    bool isSolved() override {
        bool ok = true;
        for (int face = 0; face < 6; face++) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    ok &= (cube[getIndex(face, row, col)] == getColorLetter(COLOR(face)));
                }
            }
        }

        return ok;
    }

    RubiksCube& u() override {
        this -> rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(4, 0, 2-i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 0, 2-i)] = cube[getIndex(1, 0, 2-i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 0, 2-i)] = cube[getIndex(2, 0, 2-i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 0, 2-i)] = cube[getIndex(3, 0, 2-i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 0, 2-i)] = temp_arr[i];
        return *this;
    }

    RubiksCube& uPrime() override {
        this -> u();
        this -> u();
        this -> u();

        return *this;
    }

    RubiksCube& u2() override {
        this -> u();
        this -> u();

        return *this;
    }

    RubiksCube& l() override {
        this -> rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2-i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2-i, 2)] = cube[getIndex(5, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube& lPrime() override {
        this -> l();
        this -> l();
        this -> l();

        return *this;
    }

    RubiksCube& l2() override {
        this -> l();
        this -> l();

        return *this;
    }

    RubiksCube& f() override {
        this -> rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2-i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2-i, 2)] = cube[getIndex(5, 0, 2-i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 0, 2-i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube& fPrime() override {
        this -> f();
        this -> f();
        this -> f();

        return *this;
    }

    RubiksCube& f2() override {
        this -> f();
        this -> f();

        return *this;
    }

     RubiksCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2-i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2-i, 2)] = cube[getIndex(2, 2-i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2-i, 2)] = cube[getIndex(5, 2-i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2-i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = temp_arr[i];

        return *this;
    }

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }


    /**
     * Helper functions to create unordered_map<RubiksCube, bool>
     */
    bool operator== (const RubiksCube1dArray& c1) const {
        for (int face = 0; face < 6; face++) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    if (getColor(FACE(face), row, col) != c1.getColor(FACE(face), row, col)) return false;
                }
            }
        }
        return true;
    }

    RubiksCube1dArray& operator= (const RubiksCube1dArray &c1) {
        for (int face = 0; face < 6; face++) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    cube[getIndex(int(face), row, col)] = c1.cube[getIndex(int(face), row, col)];
                }
            }
        }
        return *this;
    }
};

struct Hash1d {

    size_t operator() (const RubiksCube1dArray& c1) const {
        string res = "";

        for (int i = 0; i < 54; i++) {
            res.push_back(c1.cube[i]);
        }

        return hash<string>()(res);
    }
};

















