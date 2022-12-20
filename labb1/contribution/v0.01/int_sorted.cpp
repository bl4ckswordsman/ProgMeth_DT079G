//Kurs: Programmeringsmetodik
// Created by nasir on 2022-11-10.
//Filnamn: int_sorted.cpp

#include "int_sorted.h"


int_sorted::int_sorted(const int *source, size_t size):  buffer(nullptr,0)//buffer(source,size)//buffer(source,size)//buffer(nullptr,0)//buffer(source,size){
{
    //if(size>1 )  {buffer = sort(source, source + size).buffer;}

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

}

size_t int_sorted::size() const {
    return buffer.size();
}

void int_sorted::insert(int value) {
    int_sorted newElement(&value, 1);
    int_sorted inserted(merge(newElement));
    buffer=inserted.buffer;
}

int_sorted int_sorted::sort(const int *begin, const int *end) {
    if (begin == end) return int_sorted(nullptr, 0);
    if (begin == end - 1) return int_sorted(begin, 1);
    std::ptrdiff_t half = (end - begin) / 2;//pointer diff type
    const int *mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

const int *int_sorted::begin() const {
    return buffer.begin();
}

const int *int_sorted::end() const {
    return buffer.end();
}

int_sorted int_sorted::merge(const int_sorted &merge_with) const {
    int_buffer c(size() + merge_with.size());
    const int *pointerA = begin(), *pointerB = merge_with.begin();
    int a, b, index = 0;
    while (pointerA != end() && pointerB != merge_with.end()) {
        a = *pointerA;
        b = *pointerB;
        if (a < b) {
            c[index++] = *pointerA;
            pointerA++;
        } else {
            c[index++] = *pointerB;
            pointerB++;
        }
    }
    while (pointerA != end()) {
        c[index++] = *pointerA;
        a = *++pointerA;
    }
    while (pointerB != merge_with.end()) {
        c[index++] = *pointerB;
        b = *++pointerB;
    }
    int_sorted merged(nullptr, 0);
    merged.buffer = c;
    return merged;
}

void int_sorted::print() const {
    for (auto e: *this) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

