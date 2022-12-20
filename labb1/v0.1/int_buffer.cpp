// Laboration1, DT079G
// Amarildo Rajta
// int_buffer.cpp, created 2022-11-15, edited 2022-11-20
// contains the implementation for class int_buffer, which handles int memory resource

#include <iterator>
#include <cstdlib>
#include <iostream>
#include "int_buffer.h"

int_buffer::int_buffer(size_t size):first(new int[size]), last(first + size) {
}

int_buffer::int_buffer(const int *source, size_t size):
first(new int[size]), last(first+size) {
    std::copy(source,source+size, this);
    /*auto buff = new int[size];
    for (int i = 0; i<this->size(); i++) {
        buff[i] = (size+i);
    }*/
}

int_buffer::int_buffer(const int_buffer& rhs): int_buffer(std::distance(rhs.first, rhs.last)) {

}

size_t int_buffer::size() const {
    return std::distance(first, last);
}


int_buffer::~int_buffer() {
    delete[] first;
}

int_buffer &int_buffer::operator=(int rhs) {
    int_buffer copy(rhs);
    swap(copy);
    return *this;
}

void int_buffer::swap(int_buffer &other) {
    std::swap(first, other.first);
    std::swap(last, other.last);

}

int_buffer::int_buffer(int_buffer &&rhs): first(nullptr), last(nullptr) {
    swap(rhs);
}

int_buffer &int_buffer::operator=(int_buffer &&rhs) {
    swap(rhs);
    return *this;
}

int &int_buffer::operator[](size_t index) {
    return *(first + index);
}

const int &int_buffer::operator[](size_t index) const {
    return *(first + index);
}

int *int_buffer::begin() {
    return first;
}

int *int_buffer::end() {
    return last;
}

const int *int_buffer::begin() const {
    return first;
}

const int *int_buffer::end() const {
    return last;
}

void int_buffer::print() const {
    for (auto e: *this){
        std::cout << e << ", ";
    }
    std::cout << "\n";
}

/*int_buffer::int_buffer(std::initializer_list<int> init_list):
int_buffer(init_list.begin(), init_list.end()) {

}*/

/*int_buffer::int_buffer(const int *first, const int *last):
        int_buffer(std::distance(first,last)) {
    auto target = this->first;
    std::copy(first, last, target);
}*/
