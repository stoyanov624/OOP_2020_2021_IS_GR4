#pragma once
#include <iostream>
class Shape {
public:
    virtual void printPerimeter() const = 0;
    virtual void printArea() const = 0;
    virtual void read(std::ostream& out) = 0;
    virtual void load(std::istream& in) = 0;
};

std::ostream& operator<<(std::ostream& out, Shape* shape);
std::istream& operator>>(std::istream& in, Shape* shape);