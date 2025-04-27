//
// Created by Aniket Gupta on 25-04-2025.
//

#ifndef NIBBLEARRAY_H
#define NIBBLEARRAY_H

#include "bits/stdc++.h"

using namespace std;

class NibbleArray {
public:
    NibbleArray(const size_t size, const uint8_t val = 0xFF);

    uint8_t getVal(int idx) const;

    void setVal(int idx, uint8_t val);

    /**
     * returns the pointer to the arr_: useful for file reading/writing
     */
    unsigned char *data();
    const unsigned char *data() const;

    /**
     * returns arr_.size()
     */
    size_t storageSize() const;

    void inflate(vector<uint8_t> &dest) const;

    void reset(const uint8_t val = 0xFF);

private:
    /**
     * # of entries possible in the Nibble Array
     */
    size_t size_;
    vector<uint8_t> arr_;
};


#endif //NIBBLEARRAY_H
