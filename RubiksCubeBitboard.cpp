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

    uint64_t one_8 = (1 << 8) - 1, one_24 = (1 << 24) - 1;

    uint64_t colorMask[6] = {1, 2, 4, 8, 16, 32};

    uint64_t shiftBy(int r, int c) const {
        return pos[r][c] << 3;
    }

    void rotateFace(int fid) {
        uint64_t fmask = bitboard[fid];
        uint64_t mask = fmask >> (8 * 6);

        bitboard[fid] = (fmask << 16) | mask;
    }

    /*
     * pastes the color of cells @ idx:[f2_1, f2_2, f2_3] in face=f2 ---to--- cells @ idx:[f1_1, f1_2, f1_3] in face_f1
     */
    void rotateSide(int f1, int f1_1, int f1_2, int f1_3, int f2, int f2_1, int f2_2, int f2_3) {
        uint64_t clr1 = (bitboard[f2] & (one_8 << (8 * f2_1))) >> (8 * f2_1);
        uint64_t clr2 = (bitboard[f2] & (one_8 << (8 * f2_2))) >> (8 * f2_2);
        uint64_t clr3 = (bitboard[f2] & (one_8 << (8 * f2_3))) >> (8 * f2_3);

        bitboard[f1] = (bitboard[f1] & ~(one_8 << (8 * f1_1))) | (clr1 << (8 * f1_1));
        bitboard[f1] = (bitboard[f1] & ~(one_8 << (8 * f1_2))) | (clr2 << (8 * f1_2));
        bitboard[f1] = (bitboard[f1] & ~(one_8 << (8 * f1_3))) | (clr3 << (8 * f1_3));
    }

    /**
     *For debugging
     */
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
        bitboard[3] = bitboard[3] & (~one_24) | temp;

        /**
         *OR
         */
        // uint64_t temp = bitboard[2] & one_24;
        // bitboard[2] = (bitboard[2] & ~one_24) | (bitboard[3] & one_24);
        // bitboard[3] = (bitboard[3] & ~one_24) | (bitboard[4] & one_24);
        // bitboard[4] = (bitboard[4] & ~one_24) | (bitboard[1] & one_24);
        // bitboard[1] = (bitboard[1] & ~one_24) | temp;

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

        /**
         *saving color of cell at (idx = 0: circular index) in face 2
         */
        uint64_t clr1 = (bitboard[2] & (one_8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (bitboard[2] & (one_8 << (8 * 6))) >> (8 * 6);
        uint64_t clr3 = (bitboard[2] & (one_8 << (8 * 7))) >> (8 * 7);

        /**
         *moves the colors to cell[0, 7, 6] in face=2 from cell[0, 7, 6] in face=0
         */
        this->rotateSide(2, 0, 7, 6, 0, 0, 7, 6);
        this->rotateSide(0, 0, 7, 6, 4, 4, 3, 2);
        this->rotateSide(4, 4, 3, 2, 5, 0, 7, 6);

        /**
         *pasting the saved colors of cell[0, 7, 6] in face 2 to cells[0, 7, 6] in face 5
         */
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 0))) | (clr1 << (8 * 0));
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 6))) | (clr2 << (8 * 6));
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 7))) | (clr3 << (8 * 7));

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

        uint64_t clr1 = (bitboard[3] & (one_8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (bitboard[3] & (one_8 << (8 * 7))) >> (8 * 7);
        uint64_t clr3 = (bitboard[3] & (one_8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(3, 0, 7, 6, 0, 6, 5, 4);
        this->rotateSide(0, 6, 5, 4, 1, 4, 3, 2);
        this->rotateSide(1, 4, 3, 2, 5, 2, 1, 0);

        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 2))) | (clr1 << (8 * 2));
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 1))) | (clr2 << (8 * 1));
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

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

        uint64_t clr1 = (bitboard[0] & (one_8 << (8 * 2))) >> (8 * 2);
        uint64_t clr2 = (bitboard[0] & (one_8 << (8 * 3))) >> (8 * 3);
        uint64_t clr3 = (bitboard[0] & (one_8 << (8 * 4))) >> (8 * 4);

        this->rotateSide(0, 2, 3, 4, 2, 2, 3, 4);
        this->rotateSide(2, 2, 3, 4, 5, 2, 3, 4);
        this->rotateSide(5, 2, 3, 4, 4, 7, 6, 0);

        bitboard[4] = (bitboard[4] & ~(one_8 << (8 * 7))) | (clr1 << (8 * 7));
        bitboard[4] = (bitboard[4] & ~(one_8 << (8 * 6))) | (clr2 << (8 * 6));
        bitboard[4] = (bitboard[4] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    };

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    };

    RubiksCube &b() override {
        this->rotateFace(4);

        uint64_t clr1 = (bitboard[0] & (one_8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (bitboard[0] & (one_8 << (8 * 1))) >> (8 * 1);
        uint64_t clr3 = (bitboard[0] & (one_8 << (8 * 2))) >> (8 * 2);

        this->rotateSide(0, 0, 1, 2, 3, 2, 3, 4);
        this->rotateSide(3, 2, 3, 4, 5, 4, 5, 6);
        this->rotateSide(5, 4, 5, 6, 1, 6, 7, 0);

        bitboard[1] = (bitboard[1] & ~(one_8 << (8 * 6))) | (clr1 << (8 * 6));
        bitboard[1] = (bitboard[1] & ~(one_8 << (8 * 7))) | (clr2 << (8 * 7));
        bitboard[1] = (bitboard[1] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    };

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    };

    RubiksCube &d() override {
        this->rotateFace(5);

        uint64_t clr1 = (bitboard[2] & (one_8 << (8 * 4))) >> (8 * 4);
        uint64_t clr2 = (bitboard[2] & (one_8 << (8 * 5))) >> (8 * 5);
        uint64_t clr3 = (bitboard[2] & (one_8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(2, 4, 5, 6, 1, 4, 5, 6);
        this->rotateSide(1, 4, 5, 6, 4, 4, 5, 6);
        this->rotateSide(4, 4, 5, 6, 3, 4, 5, 6);

        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 4))) | (clr1 << (8 * 4));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 5))) | (clr2 << (8 * 5));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 6))) | (clr3 << (8 * 6));

        return *this;
    };

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    };

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }
};