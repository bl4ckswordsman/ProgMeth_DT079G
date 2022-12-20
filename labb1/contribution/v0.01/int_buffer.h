//Kurs: Programmeringsmetodik
// Created by nasir on 2022-11-10.
//Filnamn: int_buffer.h

#ifndef LABB1_INT_BUFFER_H
#define LABB1_INT_BUFFER_H
#include <cstdlib>

class int_buffer {
public:
    explicit int_buffer(size_t size);// size_t is defined in cstdlib

    int_buffer(const int *source, size_t size);  // copies it into the buffer.
    int_buffer(const int_buffer &rhs);           // copy construct
    int_buffer(int_buffer &&rhs);                // move construct
    int_buffer &operator=(const int_buffer &rhs);// copy assign
    int_buffer &operator=(int_buffer &&rhs);     // move assign
    int &operator[](size_t index);               //buf index
    const int &operator[](size_t index) const;

    size_t size() const;//the size of buffer
    //an iterrator value type
    int *begin();
    int *end();
    const int *begin() const;
    const int *end() const;
    ~int_buffer();

private:
    size_t sz;
    int *buf;
};


#endif//LABB1_INT_BUFFER_H
