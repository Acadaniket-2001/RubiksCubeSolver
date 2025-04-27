//
// Created by Aniket Gupta on 25-04-2025.
//

#include "NibbleArray.h"

NibbleArray::NibbleArray(const size_t size, const uint8_t val) : size_(size) {
    arr_.resize(size_ / 2 + 1, val);
};

uint8_t NibbleArray::getVal(int idx) const {
    const int offset = idx % 2;
    idx /= 2;
    assert(idx <= size_);

    const uint8_t ans = arr_[idx];
    if (offset)
        return (ans & 0x0F);
    return (ans >> 4);
}

void NibbleArray::setVal(int idx, const uint8_t val) {
    int offset = idx % 2;
    idx /= 2;
    assert(idx <= size_);

    if (offset)
        arr_[idx] = (arr_[idx] & 0xF0) | (val & 0x0F);
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