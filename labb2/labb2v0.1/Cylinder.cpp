//
// Created by amari on 2022-12-01.
//

#include "Cylinder.h"

Cylinder::Cylinder(std::string col, double rad, double h): Circle(col, rad) {
    height = h;
}

const double Cylinder::getArea() const {
    return (2 * Circle::getArea()) + (2 * 3.14 * Circle::getRadius() * height);       //2πr^2 + 2πrh
}



const double &Cylinder::getHeight() const {
    return height;
}
