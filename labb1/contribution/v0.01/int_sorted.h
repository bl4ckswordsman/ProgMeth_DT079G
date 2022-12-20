//Kurs: Programmeringsmetodik
// Created by nasir on 2022-11-10.
//Filnamn: int_sorted.h

#ifndef LABB1_INT_SORTED_H
#define LABB1_INT_SORTED_H
#include "int_buffer.h"
#include <cstdlib>
#include <iostream>
class int_sorted {
public:
    int_sorted(const int *source, size_t size);
    size_t size() const;
    void insert(int value);
    const int *begin() const;
    const int *end() const;
    int_sorted merge(const int_sorted &merge_with) const;
    int_sorted sort(const int *begin, const int *end);
    void print() const;
private:
    int_buffer buffer;
};
#endif//LABB1_INT_SORTED_H
