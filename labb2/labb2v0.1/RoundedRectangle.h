//
// Created by amari on 2022-12-01.
//

#ifndef LABB2V0_1_ROUNDEDRECTANGLE_H
#define LABB2V0_1_ROUNDEDRECTANGLE_H


#include "Rectangle.h"

class RoundedRectangle: public Rectangle{
    double radius;
public:
    const double getRadius() const;

public:
    RoundedRectangle(std::string col, double b, double h, double rad);
    void setRadius(const double &rad);
    const double getArea() const;

};


#endif //LABB2V0_1_ROUNDEDRECTANGLE_H
