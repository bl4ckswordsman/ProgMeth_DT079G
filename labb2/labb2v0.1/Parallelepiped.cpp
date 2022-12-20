// Laboration2, DT079G
// Amarildo Rajta
// Parallelepiped.cpp, created 2022-12-01, edited 2022-12-01

#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(std::string col, double b, double h, double d):
        Shape(col), Rectangle(col, b, h){
    setDepth(d);
}

void Parallelepiped::setDepth(const double &depth) {
    Parallelepiped::depth = depth;
}

const double &Parallelepiped::getDepth() const {
    return depth;
}

const double Parallelepiped::getArea() const {
    return (2*((Rectangle::getArea()) + (Rectangle::getBase()*depth) + (Rectangle::getHeight()*depth)));
    //A=2(bh+bd+hd)     b-base h-height d-depth
}




