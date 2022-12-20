// Laboration2, DT079G
// Amarildo Rajta
// Rectangle.h, created 2022-12-01, edited 2022-12-01

#ifndef LABB2V0_1_RECTANGLE_H
#define LABB2V0_1_RECTANGLE_H

#include "Shape.h"

class Rectangle: public virtual Shape {
    double base;
    double height;
public:
    const double & getHeight() const;
    Rectangle(std::string col, double b, double h);
    void setHeight(const double &h);
    void setBase(const double &b);
    const double & getBase() const;
    const double getArea() const;             //override gör att befintlig funktion görs om


};


#endif //LABB2V0_1_RECTANGLE_H
