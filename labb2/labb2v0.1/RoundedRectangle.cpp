//
// Created by amari on 2022-12-01.
//

#include "RoundedRectangle.h"

RoundedRectangle::RoundedRectangle( std::string col, double b, double h, double rad) :
        Shape(col), Rectangle(col, b, h) {
    setRadius(rad);
}

void RoundedRectangle::setRadius(const double &rad) {
    RoundedRectangle::radius = rad;
}

const double RoundedRectangle::getRadius() const {
    return radius;
}

const double RoundedRectangle::getArea() const {
    return Rectangle::getArea()-((radius*radius)*(4-3.14));                   //Rectangle area - 4x(square areas with side=radius) + 4x(1/4 circle areas)
                                                                                //The 4 small squares have one corner at each big rectangle corner and
                                                                                //2 sides laid on each 2 big rectangle sides.
                                                                                //The circles have their centre on each small square that points to the
                                                                                //middle of the big rectangle
    //return                                                                 //b*h - radius² * (4-π)
}


