// Laboration2, DT079G
// Amarildo Rajta
// Shape.cpp, created 2022-12-01, edited 2022-12-01

#include "Shape.h"

const std::string &Shape::getColour() const {
    return colour;
}


void Shape::setColour(const std::string &colour) {
    Shape::colour = colour;
}

Shape::Shape(std::string c) {
    setColour(c);
}

