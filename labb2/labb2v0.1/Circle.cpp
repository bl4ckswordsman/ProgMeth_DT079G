//
// Created by amari on 2022-12-01.
//

#include "Circle.h"

Circle::Circle(std::string col, double rad): Shape(col) {
    setRadius(rad);
}

const double Circle::getArea() const {
    return 3.14*radius*radius;  //πr^2
}

void Circle::setRadius(const double &radius) {
    Circle::radius = radius;
}

const double & Circle::getRadius() const {
    return radius;
}
