#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    Circle() {
        radius = 0;
    }

    Circle(int _radius) : radius(_radius) {}

    void printPerimeter() const override {
        std::cout << "circle perimeter: " << 2.0 * 3.14 * radius << std::endl;
    }

    void printArea() const override {
        std::cout << "circle area: " << 3.14 * radius * radius << std::endl;
    }

    void read(std::ostream& out) override {
        out << "circle\n";
        out << "Radius: " << radius << "\n";
    }

    void load(std::istream& in) override {
        std::cout << "Enter circle Radius: ";
        in >> radius;
    }
};

