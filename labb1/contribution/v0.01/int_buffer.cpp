//
// Created by nasir on 2022-11-12.
//

#include "int_buffer.h"
#include <algorithm>
#include <iostream>


int_buffer::int_buffer(size_t size) : sz(size), buf(new int[size]) {
}

int_buffer::int_buffer(const int *source, size_t size) : int_buffer(size) {
    std::copy(source, source + size, buf);
}

int_buffer::int_buffer(const int_buffer &rhs) : int_buffer(rhs.buf, rhs.sz) {
}

int_buffer::int_buffer(int_buffer &&rhs) : buf(nullptr), sz(0) {
    std::swap(buf, rhs.buf);
    std::swap(sz, rhs.sz);
}

int_buffer &int_buffer::operator=(const int_buffer &rhs) {
    int_buffer temp(rhs);
    std::swap(temp.buf, buf);
    std::swap(temp.sz, sz);
    return *this;
}

int_buffer &int_buffer::operator=(int_buffer &&rhs) {
    std::swap(buf, rhs.buf);
    std::swap(sz, rhs.sz);
    return *this;
}

int &int_buffer::operator[](size_t index) {
    return buf[index];
}

const int &int_buffer::operator[](size_t index) const {
    return buf[index];
}

size_t int_buffer::size() const {
    return sz;
}

int *int_buffer::begin() {
    return buf;
}

int *int_buffer::end() {
    return buf + sz;
}

const int *int_buffer::begin() const {
    return buf;
}

const int *int_buffer::end() const {
    return buf + sz;
}

int_buffer::~int_buffer() {
    delete[] buf;
}
