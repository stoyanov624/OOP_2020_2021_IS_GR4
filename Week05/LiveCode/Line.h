#pragma once
#include <iostream>
#include "Point.h"

template <typename T>
class Line {
    
private:
	Point<T> a;
	Point<T> b;
    
public:
	Line();
	Line(const Point<T>& other_a,const Point<T>& other_b);

	friend std::ostream& operator<<(std::ostream& out, const Line<T>& line){
        out << line.a;
        out << line.b;

        return out;
    }
};

template <typename T>
Line<T>::Line() {
    a = Point<T>();
    b = Point<T>();
}

template <typename T>
Line<T>::Line(const Point<T>& other_a,const Point<T>& other_b) {
    this->a = other_a;
    this->b = other_b;
}