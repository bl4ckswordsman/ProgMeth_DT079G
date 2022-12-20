//
// Created by amari on 2022-12-01.
//

#ifndef LABB2V0_1_CYLINDER_H
#define LABB2V0_1_CYLINDER_H

#include "Circle.h"

class Cylinder: public Circle{
    double height;
public:
    Cylinder(std::string col, double rad, double h);
    const double & getHeight() const;
    const double getArea() const;

};


#endif //LABB2V0_1_CYLINDER_H
