#include <iostream>
#include <random>
#include "int_buffer.h"
#include "int_sorted.h"

void f(int_buffer buf){
    static int start_value = 1;
    int it = start_value;
    std::cout<< "f: Printing and assigning via for-loops:\n";
    for (int* i = buf.begin(); i!= buf.end(); i++){
        *i=it;
        it++;
    }
    for (const int* i = buf.begin(); i !=buf.end() ; i ++){
        std::cout << *i << ", ";
    }
    std::cout << "\n";
}

void f2(int_buffer buf) {
    std::cout << "f2: Printing and assigning via range-for:\n";
    static int start_value = 1;
    int it = start_value;
    for (auto &e: buf) {
        e=it;
        it++;
    }
    for(auto e:buf){
        std::cout << e << ", ";
    }
}



bool is_sorted(int_buffer int_buf){
    int* a = int_buf.begin();
    int* b = nullptr;
    while (a != int_buf.end() -1){
        b= a + 1;
        if (*a > *b){
            return false;
        }
        else{
            a = b;
        }
    }
    return true;
}


int main() {
    std::random_device rd;              //'C++11 Random library' setup
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 1000);


        //1.
    std::cout << "\tTask 1:\n";
    f(int_buffer(10));
    f2(int_buffer(10));
    std::cout << "\n\n";

        //2.
    std::cout << "\tTask 2:\n";
    int_buffer buf1(100);
    for (auto i = 0; i < 100; i++){
        buf1[i] = (dist(mt));
    }
    buf1.print();
    int_sorted buf_s(buf1.begin(),buf1.size());
    buf_s.print();

    std::cout << "\n\n";
    int_sorted bufS(nullptr,0);
    for (auto i = 0; i < 100; i++){
        bufS.insert(dist(mt));
    }
    bufS.print();
    //print(buf1);


    /*int arr[]={3, 7, 10};
    int i=1;
    int* i2 = &i;
    //int_buffer b4(arr,arr+1);
    int_buffer b5 = int_buffer(i2, 10);
    int_buffer b(10);
    auto siz = b.size();*/


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
