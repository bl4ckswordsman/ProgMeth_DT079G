#include <iostream>
#include "int_buffer.h"

void f(int_buffer buf){
    for (int* i = buf.begin(); i!= buf.end(); i++){

        //buf[*i]=*i;
    }
    for (const int* i = buf.begin(); i !=buf.end() ; i ++){}
    for (auto e: buf){}
}

int main() {
    //int_buffer test(10);
    //int_buffer test2(&test[1],2);
    //f(int_buffer(10));
    int_buffer::value_type arr[]={0, 1, 2, 32};
    int_buffer arr_buf(arr, arr+4);

    int i=1;
    int* i2 = &i;
    int_buffer b5 = int_buffer(i2, 10);
    int_buffer b(10);
    auto siz = b.size();


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
