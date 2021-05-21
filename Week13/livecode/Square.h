#pragma once
#include "Shape.h"

class Square : public Shape {
private:
    double a;
public:
    Square() {
        a = 0;
    }
    Square(double _a) : a(_a) {}

    void printPerimeter() const override {
        std::cout << "square perimeter: " << 4.0 * a << std::endl;
    }

    void printArea() const override {
        std::cout << "squre area: " << a * a << std::endl;
    }

    void read(std::ostream& out) override {
        out << "square\n";
        out << "Side A: " << a << "\n";
    }

    void load(std::istream& in) override {
        std::cout << "Enter square side: ";
        in >> a;
    }

};
