// Laboration2, DT079G
// Amarildo Rajta
// Parallelepiped.h, created 2022-12-01, edited 2022-12-01

#ifndef LABB2V0_1_PARALLELEPIPED_H
#define LABB2V0_1_PARALLELEPIPED_H

#include "Rectangle.h"

class Parallelepiped: public Rectangle {
    double depth;
public:
    Parallelepiped(std::string col, double b, double h, double d);
    void setDepth(const double &depth);
    const double & getDepth() const;
    const double getArea() const;

};


#endif //LABB2V0_1_PARALLELEPIPED_H
