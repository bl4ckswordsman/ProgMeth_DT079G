// Laboration2, DT079G
// Amarildo Rajta
// Rectangle.cpp, created 2022-12-01, edited 2022-12-01

#include "Rectangle.h"

Rectangle::Rectangle(std::string col, double b, double h): Shape(col) {
    setBase(b);
    setHeight(h);
}

void Rectangle::setBase(const double &b) {
    base = b;
}

void Rectangle::setHeight(const double &h) {
    height = h;
}

const double Rectangle::getArea() const {
    return getBase()*getHeight();
}

const double &Rectangle::getBase() const {
    return base;
}

const double &Rectangle::getHeight() const {
    return height;
}
