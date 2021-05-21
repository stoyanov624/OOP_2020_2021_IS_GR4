#include "ShapeFactory.h"
std::ostream& operator<<(std::ostream& out, Shape* shape) {
    shape->read(out);

    return out;
}

std::istream& operator>>(std::istream& in, Shape* shape) {
    std::string type;
    if(shape != nullptr) {
        delete shape;
    }
    in >> type; 
    shape = ShapeFactory::makeShape(type);
    shape->load(in);
    return in;
}