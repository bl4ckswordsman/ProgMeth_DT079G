// Laboration5, DT079G
// Amarildo Rajta
// Created on 2022-12-11

#ifndef L5V0_01_CAR_H
#define L5V0_01_CAR_H


#include <string>
#include <ostream>
#include <iostream>

class Car {
    std::string name;
    double speed;
public:
    Car(std::string carName, double carSpeed);

    const std::string &getName() const;
    double getSpeed() const;

    bool operator==(const Car &rhs) const;

};


class MyPrint {
public:
    void operator()(const Car& car) const {
        std::cout << "Car name: " << car.getName() << ", Speed: " << car.getSpeed() << "km/h" << std::endl;
    }
};


class HigherSpeedThan {
    double speedToCompare;
public:
    HigherSpeedThan(const double & compSpeed):speedToCompare(compSpeed){
    }

    bool operator()(const Car& c1){
        return c1.getSpeed()>speedToCompare;
    }
};


#endif //L5V0_01_CAR_H
