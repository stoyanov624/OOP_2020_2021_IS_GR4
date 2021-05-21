#include "ShapeFactory.h"
#include "Circle.h" // includ-ваме тук Circle за да не стане взаймно инклудваме между Circle и Shape
#include "Square.h"

Shape* ShapeFactory::makeShape(std::string& typeOfShape) { // Тук изпозлвайте вашия стринг :)
    Shape* shape = nullptr;
    if(typeOfShape == "cirlce") {
        shape = new Circle(0);
        
    } else if (typeOfShape == "square") {
        return new Square(0);
    } 
    return shape;
}  