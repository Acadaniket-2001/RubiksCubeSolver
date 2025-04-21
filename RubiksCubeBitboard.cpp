//
// Created by Aniket Gupta on 21-04-2025.
//

#include "RubiksCube.h"

class RubiksCubeBitboard : public RubiksCube {
private:
    uint64_t solved_side_mask[6]{};

    int pos[3][3] = {
        {0, 1, 2},
        {7, 8, 3},
        {6, 5, 4}
    };

    uint64_t one_24 = (1 << 24) - 1;

    uint64_t colorMask[6] = {1, 2, 4, 8, 16, 32};

    uint64_t shiftBy(int r, int c) {
        return pos[r][c] << 3;
    }

    void rotateFace(int fid) {
        uint64_t fmask = bitboard[fid];
        uint64_t mask = fmask >> (8 * 6);

        bitboard[fid] = (fmask << 16) | mask;
    }


    // For debugging
    void prBin(uint64_t x) const {
        for (int i = 63; i >= 0; i--) {
            cout << ((x >> i) & 1ULL);
            if (i % 8 == 0) cout << " ";
        }
        cout << endl;
    }

public:
    uint64_t bitboard[6] = {0};

    RubiksCubeBitboard() {
        for (int face = 0; face < 6; face++) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    bitboard[face] |= colorMask[face] << shiftBy(row, col);
                }
            }

            solved_side_mask[face] = bitboard[face];
            // prBin(bitboard[face]);
        }
    };

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        if(row == 1 and col == 1)   return COLOR(int(face));

        uint64_t fmask = bitboard[int(face)];
        uint64_t mask = (1 << 8) - 1;

        fmask >>= (shiftBy(row, col) & mask);

        int idx = 0;
        for (int i = 0; i < 6; i++) {
            if (fmask & (1ULL << i)) {
                idx = i;
                break;
            }
        }
        return COLOR(idx);
    }

    bool isSolved() {
        for (int face = 0; face < 6; face++) {
            if (bitboard[face] != solved_side_mask[face])   return false;
        }
        return true;
    }

    RubiksCube &u() override {
        this -> rotateFace(0);

        uint64_t temp = ((bitboard[4] << 40) >> 40);
        bitboard[4] = (bitboard[4] & (~one_24)) | ((bitboard[1] << 40) >> 40);
        bitboard[1] = (bitboard[1] & (~one_24)) | ((bitboard[2] << 40) >> 40);
        bitboard[2] = (bitboard[2] & (~one_24)) | ((bitboard[3] << 40) >> 40);
        bitboard[3] = temp;

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

        // uint64_t clr1 = (bitboard[2] & (one_8 << (8 * 0))) >> (8 * 0);
        // uint64_t clr2 = (bitboard[2] & (one_8 << (8 * 6))) >> (8 * 6);
        // uint64_t clr3 = (bitboard[2] & (one_8 << (8 * 7))) >> (8 * 7);
        //
        // this->rotateSide(2, 0, 7, 6, 0, 0, 7, 6);
        // this->rotateSide(0, 0, 7, 6, 4, 4, 3, 2);
        // this->rotateSide(4, 4, 3, 2, 5, 0, 7, 6);
        //
        // bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 0))) | (clr1 << (8 * 0));
        // bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 6))) | (clr2 << (8 * 6));
        // bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 7))) | (clr3 << (8 * 7));

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