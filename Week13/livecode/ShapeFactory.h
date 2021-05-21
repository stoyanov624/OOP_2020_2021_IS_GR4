#pragma once
#include <iostream>
#include "Shape.h"

class ShapeFactory {

public:
    static Shape* makeShape(std::string& typeOfShape);
};