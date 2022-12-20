// Laboration3, DT079G
// Amarildo Rajta
// main.cpp, created 2022-12-03, edited 2022-12-09
#include <iostream>
#include <random>
#include "p_queue.h"

//A DealerShare object that contains the dealer name and the share price
struct DealerShare {
    std::string name;
    int price;
};

//Function object that compares prices of 2 DealerShare objects, returns true if first price is lower than second
struct SharePriceComp{
    bool operator()(const DealerShare &d1, const DealerShare &d2){
        return d1.price<d2.price;
    }
};

int main() {

    std::random_device rd;              //'C++11 Random library' setup
    std::mt19937 mt(rd());
    int MINval=15;
    int MAXval=30;
    std::uniform_int_distribution<int> dist(MINval, MAXval);

    p_queue<DealerShare,SharePriceComp> buyer;
    p_queue<DealerShare,SharePriceComp> seller;
    for(auto i = 1; i<7; i++){
        buyer.push({"Erik Pendel", dist(mt)});
        buyer.push({"Jarl Wallenburg", dist(mt)});
        buyer.push({"Joakim von Anka", dist(mt)});
        seller.push({"Erik Pendel", dist(mt)});
        seller.push({"Jarl Wallenburg", dist(mt)});
        seller.push({"Joakim von Anka", dist(mt)});
    }

    while(!buyer.empty() && !seller.empty()) {
        auto s1 = seller.pop();
        auto b1 = buyer.pop();

        if(b1.price >= s1.price) {                             //&& b1.name!=s1.name //Can a person buy shares from himself/herself?
            std::cout << b1.name << " spent " << b1.price << "SEK to buy a share priced "
                      << s1.price << "SEK from the seller " << s1.name << "\n";
        }
        //else{seller.push(s1);}
        /*else{                     //If the purchase fails
            std::cout << " X " << b1.name << " offered " << b1.price << "SEK to buy a share priced "
                        << s1.price << "SEK from seller " << s1.name << "\n";
        }*/
    }

    return 0;
}
