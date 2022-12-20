// Laboration1, DT079G
// Amarildo Rajta
// int_buffer.h, created 2022-11-21, edited 2022-11-21
// header to int_sorted.cpp

#ifndef V0_1_INT_SORTED_H
#define V0_1_INT_SORTED_H
#include "int_buffer.h"

class int_sorted {
public :
    int_sorted (const int* source , size_t size);
    size_t size() const;
    void insert (int value);
    const int* begin() const;
    const int* end() const;
    int_sorted merge(const int_sorted &merge_with) const;

    int_sorted sort(const int*begin, const int* end);

    void print() const;
private:
    //static const size_t MIN_CAPACITY = 16;
    int_buffer buffer;
    // = int_buffer(MIN_CAPACITY);
};



#endif //V0_1_INT_SORTED_H
