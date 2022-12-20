// Laboration2, DT079G
// Amarildo Rajta
// main.cpp, created 2022-12-01, edited 2022-12-01
#include <iostream>
#include <memory>
#include <vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Cylinder.h"
#include "RoundedRectangle.h"
#include "Parallelepiped.h"


using Shape_ptr = std::unique_ptr<Shape>;

void GetData(std::vector<Shape_ptr> &shapeList){
    double totalA=0;

    for (auto& e: shapeList){
        auto* c_p = dynamic_cast<Circle*>(e.get());
        auto* cy_p = dynamic_cast<Cylinder*>(e.get());
        auto* r_p = dynamic_cast<Rectangle*>(e.get());
        auto* pp_p = dynamic_cast<Parallelepiped*>(e.get());
        auto* rr_p = dynamic_cast<RoundedRectangle*>(e.get());

        if(c_p && !cy_p)    { std::cout << "Circle; ";}
        if(cy_p)            { std::cout << "Cylinder; ";}
        if(r_p && !pp_p && !rr_p) { std::cout << "Rectangle; ";}
        if(pp_p)            { std::cout << "Parallelepiped; ";}
        if(rr_p)            { std::cout << "Rounded Rectangle; ";}
        std::cout << "Colour: " << e->getColour() << ", Area: " << e->getArea() << "\n";
        totalA += e->getArea();
    }
    std::cout << " Total area: " << totalA << "\n";
}

int main() {

    std::vector<Shape_ptr> shapeL;
    shapeL.push_back(std::make_unique<Circle>("white", 7));
    shapeL.push_back(std::make_unique<Cylinder>("orange", 10, 3));
    shapeL.push_back(std::make_unique<Rectangle>("purple", 3.2, 6.9));
    shapeL.push_back(std::make_unique<Parallelepiped>("gray", 11, 4, 4.5));
    shapeL.push_back(std::make_unique<RoundedRectangle>("green", 13.7, 3, 2));
    shapeL.push_back(std::make_unique<Rectangle>("blue", 17, 1));
    shapeL.push_back(std::make_unique<Circle>("yellow", 7.9));
    GetData(shapeL);

    return 0;
}
