// Laboration1, DT079G
// Amarildo Rajta
// int_buffer.h, created 2022-11-21, edited 2022-11-21
// contains the implementation for class int_sorted, which handles int_buffer sorting

#include <cstdlib>
#include <iostream>
#include "int_sorted.h"


int_sorted::int_sorted(const int *source, size_t size):buffer(source, size) {
    if (size==0){
        return ;
    }
    if (size==1) {

        buffer=int_buffer(source, size);
        return ;
    }
    else {
        buffer = sort(source, source + size).buffer;
    }


    /*if (buffer.size() < 1) {}
    if (buffer.size() == 1){
        buffer=int_buffer(source, size);
        //return;
    }
    else {
        buffer = sort(source, source + size).buffer;
        int_buffer tmp(buffer.begin(), 0);
        tmp = sort(buffer.begin(), buffer.end()).buffer;
        buffer = tmp;
    }*/
}

size_t int_sorted::size() const {
    return buffer.end() - buffer.begin();
}

void int_sorted::insert(int value) {
    int_sorted newElement(&value, 1);
    int_sorted inserted(merge(newElement));
    buffer=inserted.buffer;
}

const int *int_sorted::begin() const {
    return buffer.begin();
}

const int *int_sorted::end() const {
    return buffer.end();
}

int_sorted int_sorted::merge(const int_sorted &merge_with) const {
    int_buffer temp_buf(size() + merge_with.size());
    const int* pointerA = begin();
    const int* pointerB = merge_with.begin();
    int a = 0;
    int b = 0;
    int main_counter = 0;
    while (pointerA != end() && pointerB != merge_with.end()) {
        a = *pointerA;
        b = *pointerB;
        if (a < b) {
            temp_buf[main_counter++] = *pointerA;
            pointerA++;
        } else {
            temp_buf[main_counter++] = *pointerB;
            pointerB++;
        }
    }
    while (pointerA != end()) {
        temp_buf[main_counter++] = *pointerA;
        a = *++pointerA;
    }
    while (pointerB != merge_with.end()) {
        temp_buf[main_counter++] = *pointerB;
        b = *++pointerB;
    }
    int_sorted merged(nullptr, 0);
    merged.buffer = temp_buf;
    return merged;
}

int_sorted int_sorted::sort(const int *begin, const int *end) {
    if (begin == end)return int_sorted(begin, 1);
    if (begin == end - 1)return int_sorted(begin, 1);
    ptrdiff_t half = (end - begin) / 2;
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

void int_sorted::print() const {
    for (auto e: *this) {
        std::cout << e << ", ";
    }
    std::cout << "\n";
}
