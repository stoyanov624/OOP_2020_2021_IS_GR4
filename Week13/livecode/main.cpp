#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <cmath>
#include "string"
#include "Vector.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
// "[a,b,c]"
// a b c
// {a, b ,c}

//des
// expected input -> "[a,b,c]"


int main() {
    Shape* s = new Circle(1);
    Shape* s2 = new Square();

    s2->load(std::cin);
    s2->read(std::cout);
    s2->printArea();

    s->load(std::cin);  // вече може да напишем 5 в конзолата и да ни промени радиуса на 5.
    s->read(std::cout);
    s->printArea();

    
}