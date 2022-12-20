//Namn: Nasir Alizade
//Kurs: Programmeringsmetodik
// Created by nasir on 2022-11-10.
//Filnamn: main.cpp


#include "int_sorted.h"
#include <algorithm>
#include <chrono>
#include <iostream>


void pause();
bool check(int_buffer buf);
void f(int_buffer buf);
void fAuto(int_buffer buf);
void fSorted(int_sorted buf);
void fMerge(int_sorted buf1, int_sorted buf2);
void selectionSort(int *first, int *last);

int main() {

    srand(time(nullptr));
    //uppgift 1__________________________
    f(int_buffer(10));
    pause();
    //explicit int_buffer()- kontrueraren körs
    //både for-loop kör icke konst. förmodligen objekted inte är const.
    //sedan körs destruerare
    //rang-for syntax funkar (for(auto e: buf)).
    //_______________________________________________________________________

    //uppgift 2___________________________________________
    //testar sort klassen genom att göra insert på 100 slumptal
    fSorted(int_sorted(nullptr, 0));
    pause();
    //från begin till end är i stigande ordning.
    // testade flera gånger för säkerhets skulle.
    //_______________________________________________________________________________

    //uppgift 3_____________________________________
    //valde att göra en selection sort funktion.
    //~1,024s tar selection sort att sortera
    //~0,01512s tar för merge sort att sortera
    //~0,00519s tar std::sort att sortera 40000 random tal.
    int_buffer buf(400000);
    for (auto &e: buf) {
        e = rand() % 399999 + 1;
    }
    int_buffer buf2 = buf;
    std::cout << "Sorting 40000 elements using selection sort" << std::endl;
    std::cout << "sorting...." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(buf.begin(), buf.end());
    auto stop = std::chrono::high_resolution_clock::now();
    auto selectSortTime = std::chrono::duration<double>(stop - start);

    for (auto e: buf) {
        std::cout << e << ", ";
    }
    std::cout << std::endl
              << "time to sort using selection sorting: " << selectSortTime.count() << "s" << std::endl;
    pause();
    std::cout << " Sorting 40000 elements using merge sort" << std::endl;
    std::cout << "sorting...." << std::endl;
     start = std::chrono::high_resolution_clock::now();
    int_sorted buffer(buf.begin(), buf.size());
     stop = std::chrono::high_resolution_clock::now();
    auto mergesorttime = std::chrono::duration<double>(stop - start);
    //buffer.print();
    std::cout << std::endl
              << "time to sort using merge: " << mergesorttime.count() << "s" << std::endl;
    pause();
    std::cout << "Sorting 40000 elements using std::sort()" << std::endl;
    std::cout << "sorting...." << std::endl;
    start = std::chrono::high_resolution_clock::now();
    std::sort(buf2.begin(), buf2.end());
    stop = std::chrono::high_resolution_clock::now();
    auto sortTime = std::chrono::duration<double>(stop - start);
    for (auto e: buf2) {
        std::cout << e << ", ";
    }
    std::cout << std::endl
              << "time to sort using std::sort(): " << sortTime.count() << "s" << std::endl;

    return 0;
}


void f(int_buffer buf) {
    std::cout << "Function f: ";
    int count = 1;
    for (int *i = buf.begin(); i != buf.end(); i++) {
        *i = count;
        count++;
    }
    for (const int *i = buf.begin(); i != buf.end(); i++) {
        std::cout << *i << ',';
    }
    std::cout << std::endl
              << std::endl;
}
void fAuto(int_buffer buf) {
    std::cout << "använder range syntax, funktion fAuto" << std::endl;
    int count = 1;
    for (auto &e: buf) {
        e = count;
        count++;
    }
    for (auto e: buf) {
        std::cout << e << ',';
    }
    std::cout << std::endl
              << std::endl;
}
void fSorted(int_sorted buf) {
    std::cout << "inserts 100 random elements..: " << std::endl;
    for (int i = 0; i < 100; i++) {
        buf.insert(rand() % 9999 + 1);
    }
    buf.print();
    std::cout << std::endl;
}
void fMerge(int_sorted buf1, int_sorted buf2) {
    std::cout << "takes two sorted buffers and merges them.." << std::endl;
    for (int i = 0; i < 20; ++i) {
        buf1.insert(rand() % 9999 + 1);
        buf2.insert(rand() % 9999 + 1);
    }
    std::cout << "Buf1:" << std::endl;
    buf1.print();
    std::cout << "Buf2:" << std::endl;
    buf2.print();
    int_sorted merged = buf1.merge(buf2);
    std::cout << "merged buffer:" << std::endl;
    merged.print();
    pause();
}
void selectionSort(int *first, int *last) {
    int_buffer sorted(first, last - first);
    int *min = nullptr;
    for (int *i = first; i < last - 1; i++) {
        min = i;
        for (int *j = i + 1; j < last; j++) {
            if (*j < *min) {
                min = j;
            }
        }
        std::swap(*min, *i);
    }
}
void pause() {
    std::cout << std::endl;
    std::cout << "Tryck [ENTER] för att försätta.." << std::endl;
    std::cin.get();
}
void print(int_buffer buf) {
    for (auto e: buf) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}
bool check(int_buffer buf) {
    int *a = buf.begin();
    int *b = nullptr;

    while (a != buf.end() - 1) {
        b = a + 1;
        if (*a > *b) return false;
        else
            a = b;
    }
    return true;
}
