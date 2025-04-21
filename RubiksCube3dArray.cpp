//
// Created by Aniket Gupta on 20-04-2025.
//

#include "RubiksCube.h"

class RubiksCube3dArray: public RubiksCube {
private:
    void rotateFace(int fid) {  // rotating the face(fid) by 90degree clk-wise
        int n = 3;
        for(int i =0; i <= n/2 - 1; i++) {
            for(int j =0;  j<= n/2; j++) {
                char temp = cube[fid][i][j];
                cube[fid][i][j] = cube[fid][n - j - 1][i];
                cube[fid][n - j - 1][i] = cube[fid][n - i - 1][n - j - 1];
                cube[fid][n - i - 1][n - j - 1] = cube[fid][j][n - i - 1];
                cube[fid][j][n - i - 1] = temp;
            }
        }
    }

public:
    char cube[6][3][3]{};

    RubiksCube3dArray() {
        for(int face =0 ; face < 6 ; face++) {
            for(int row =0 ; row < 3 ; row++) {
                for(int col =0 ; col < 3 ; col++) {
                    cube[face][row][col] = getColorLetter(COLOR(face));
                }
            }
        }
    };

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char ch = cube[int(face)][row][col];

        if (ch == 'W')    return COLOR::WHITE;
        else if (ch == 'G')    return COLOR::GREEN;
        else if (ch == 'R')    return COLOR::RED;
        else if (ch == 'B')    return COLOR::BLUE;
        else if (ch == 'O')    return COLOR::ORANGE;
        else    return COLOR::YELLOW;
    }

    bool isSolved() override {
        bool ok = true;
        for(int face =0 ; face < 6 ; face++) {
            for(int row =0 ; row < 3 ; row++) {
                for(int col =0 ; col < 3 ; col++) {
                    ok &= cube[face][row][col] == getColorLetter(COLOR(face));
                }
            }
        }
        return ok;
    }

    RubiksCube& u() override {
        this -> rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];
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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

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
};