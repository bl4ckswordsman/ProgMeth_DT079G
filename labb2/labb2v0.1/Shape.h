// Laboration2, DT079G
// Amarildo Rajta
// Shape.h, created 2022-12-01, edited 2022-12-01

#ifndef LABB2V0_1_SHAPE_H
#define LABB2V0_1_SHAPE_H

#include <string>

class Shape {
    std::string colour;
public:
    Shape(std::string c);
    virtual ~Shape()=default;
    void setColour(const std::string &colour);
    const std::string &getColour() const;
    virtual const double getArea() const = 0;     //pure virtual
};


#endif //LABB2V0_1_SHAPE_H
