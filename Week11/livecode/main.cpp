#include <iostream>
class Shape {
public:
    virtual void printPerimeter() const = 0;
    virtual void printArea() const = 0;
};

class Square : public Shape {
protected:
    int a;
public:
    Square(int _a) : a(_a) {}

    void printAngles() const {

    }

    virtual void printPerimeter() const override {
        std::cout << "sqr p: " << 4 * a  << std::endl;
    }

    virtual void printArea() const override {
        std::cout << "sqr a: " << a * a  << std::endl;
    }
};

// Shape -> Square -> Rectangle

class Rectangle : public Square {
private:
    int b;
public:
    Rectangle(int _a, int _b) : Square(_a), b(_b) {}

    void printPerimeter() const override {
        std::cout << "rect p: " << 2 * (a + b)  << std::endl;
    }

    void printArea() const override {
        std::cout << "rect a: " << a * b  << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(int _radius) : radius(_radius) {}

    void printPerimeter() const override {
        std::cout << "circle p: " << 2.0 * 3.14 * radius << std::endl;
    }

    void printArea() const override {
        std::cout << "circle a: " << 3.14 * radius * radius << std::endl;
    }
};

// class Firm {
//     Employable* employee;
// };

// class Employable {
//     virtual void work() = 0;
// };

// class PersonM : public Employable {
//      void work() {}
// };
// class PersonF : public Employable {
//      void work() {}
// };

// class Dog {

// };

int main() {
    Rectangle r(1,2);
    Circle c(5);

    Shape* shape1 = new Circle(5);
    Shape* shape2 = new Rectangle(1,2);
    Shape* shape3 = new Square(5);

    Shape** shapes = new Shape*[3];
    shapes[0] = shape1;
    shapes[1] = shape2;
    shapes[2] = shape3;

    for (size_t i = 0; i < 3; i++)
    {
        shapes[i]->printPerimeter();
    }

    delete shape1;
    delete shape2;
	delete shape3;
}