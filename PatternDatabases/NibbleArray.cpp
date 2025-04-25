//
// Created by Aniket Gupta on 25-04-2025.
//

#include "NibbleArray.h"

NibbleArray::NibbleArray(const size_t size, const uint8_t val) : size_(size / 2 + 1) {
    arr_.resize(size_, val);
};

uint8_t NibbleArray::getVal(int idx) const {
    const int offset = idx % 2;
    idx /= 2;
    const uint8_t ans = arr_[idx];
    if (offset)
        return ((ans << static_cast<uint8_t>(4)) >> static_cast<uint8_t>(4));
    return (ans >> static_cast<uint8_t>(4));
}

void NibbleArray::setVal(int idx, const uint8_t val) {
    int offset = idx % 2;
    idx /= 2;

    if (offset)
        arr_[idx] = (arr_[idx] & 0xF0) | val;
    else
        arr_[idx] = (arr_[idx] & 0x0F) | (val << 4);
}

/**
 * data() of vector returns the ptr to the array underlying in vector
 */
uint8_t *NibbleArray::data() {
    return arr_.data();
}

const uint8_t *NibbleArray::data() const {
    return arr_.data();
}

size_t NibbleArray::storageSize() const {
    return arr_.size();
}

/**
 * Move all the moves to a vector. This doubles the size, but is faster to access,
 * since there is no bitwise operation needed.
 */
void NibbleArray::inflate(vector<uint8_t> &dest) const {
    dest.reserve(size_);

    for (unsigned i = 0; i < size_; ++i)
        dest.push_back(getVal(i));
}

// Reset the array
void NibbleArray::reset(const uint8_t val) {
    fill(arr_.begin(), arr_.end(), val);
}