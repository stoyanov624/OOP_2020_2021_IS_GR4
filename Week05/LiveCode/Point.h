#pragma once
#include <iostream>

template <typename T>
class Point {
private:
	T x;
	T y;
public:
	Point();
	Point(T other_x, T other_y);
	void setY(T other_y);
	T getY() const;
    

    Point<T>& operator=(const Point<T>& other);

    friend std::ostream& operator<<(std::ostream& out,const Point& point) {
        out << "Coordinate X: " << point.x << "\n";
        out << "Coordinate Y: " << point.y << "\n";

        return out;
    }

    friend std::istream& operator>>(std::istream& in, Point& point) {
        std::cout << "Enter coordinate X: ";
        in >> point.x;
        std::cout << "Enter coordinate Y: ";
        in >> point.y;

        return in;
    }
};

template <typename T>
Point<T>::Point() {
    this->x = 0;
    this->y = 0;
}

template <typename T>
Point<T>::Point(T other_x, T other_y) {
    this->x = other_x;
    this->y = other_y;
}


template<typename T>
void Point<T>::setY(T other_y){
    this->y=other_y;
}

template<typename T>
T Point<T>::getY() const{
    return this->y;
}

template <typename T>
Point<T>& Point<T>::operator=(const Point<T>& other) {
    this->x = other.x;
    this->y = other.y;
}

