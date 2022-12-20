// Laboration1, DT079G
// Amarildo Rajta
// int_buffer.cpp, created 2022-11-15, edited 2022-11-20
// contains the implementation for class int_buffer, which handles int memory resource

#include <iterator>
#include "int_buffer.h"

int_buffer::int_buffer(size_t size):first(new int[size]), last(first + size) {
}

int_buffer::int_buffer(const int_buffer::value_type* source, size_t size) {
    int_buffer::value_type* buff = new int_buffer::value_type[size];
    for (int i = 0; i<size; i++) {
        buff[i] = *(source+i);
    }
}

int_buffer::int_buffer(const int_buffer &rhs): int_buffer(rhs.first, rhs.last) {

}

size_t int_buffer::size() const {
    return std::distance(first, last);
}


int_buffer::~int_buffer() {
    delete[] first;
}

int_buffer &int_buffer::operator=(const int_buffer &rhs) {
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

int_buffer::value_type* int_buffer::begin() {
    return first;
}

int_buffer::value_type* int_buffer::end() {
    return last;
}

const int_buffer::value_type* int_buffer::begin() const {
    return first;
}

const int_buffer::value_type* int_buffer::end() const {
    return last;
}

int_buffer::int_buffer(std::initializer_list<int> init_list): int_buffer(init_list.begin(), init_list.end()) {

}

int_buffer::int_buffer(const int_buffer::value_type* first, const int_buffer::value_type* last):
        int_buffer(std::distance(first,last))
{
    auto target = this->first;
    std::copy(first, last, target);
}
