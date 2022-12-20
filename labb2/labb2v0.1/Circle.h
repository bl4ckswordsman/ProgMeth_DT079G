//
// Created by amari on 2022-12-01.
//

#ifndef LABB2V0_1_CIRCLE_H
#define LABB2V0_1_CIRCLE_H

#include "Shape.h"

class Circle: public Shape {
    double radius;
public:
    Circle(std::string col, double rad);
    void setRadius(const double &radius);
    const double &getRadius() const;
    const double getArea() const;

};


#endif //LABB2V0_1_CIRCLE_H
