// Laboration1, DT079G
// Amarildo Rajta
// int_buffer.h, created 2022-11-15, edited 2022-11-20
// header to int_buffer.cpp

#ifndef V0_1_INT_BUFFER_H
#define V0_1_INT_BUFFER_H
#include <cstdlib>

class int_buffer {
public :
    using value_type = int;
    explicit int_buffer (size_t size ) ; // size_t is defined in cstdlib
    int_buffer (const int_buffer::value_type * source , size_t size) ;
    int_buffer (const int_buffer & rhs) ; // copy construct
    int_buffer (int_buffer && rhs) ; // move construct
    int_buffer & operator =( const int_buffer &rhs ) ; // copy assign
    int_buffer & operator =( int_buffer && rhs ) ; // move assign
    int & operator []( size_t index ) ;
    const int & operator []( size_t index ) const ;
    size_t size() const ;
    int_buffer::value_type* begin() ;
    int_buffer::value_type* end() ;
    const int_buffer::value_type* begin() const ;
    const int_buffer::value_type* end() const ;
    ~int_buffer();

    int_buffer(std::initializer_list<int> init_list);
    int_buffer(const int_buffer::value_type* first, const int_buffer::value_type* last);
private:
    int_buffer::value_type* first{};
    int_buffer::value_type* last{};
    void swap(int_buffer &other);
    //size_t intsize;
    //int* intbuff;

};


#endif //V0_1_INT_BUFFER_H
