// Laboration5, DT079G
// Amarildo Rajta
// Created on 2022-12-11

#include "Car.h"

Car::Car(std::string carName, double carSpeed):name(carName), speed(carSpeed) {
}

const std::string &Car::getName() const {
    return name;
}

double Car::getSpeed() const {
    return speed;
}

bool Car::operator==(const Car &rhs) const {
    return name == rhs.name;
}


