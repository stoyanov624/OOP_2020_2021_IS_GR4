#pragma once
#include <iostream>

class Vector {
public:
    Vector();
    // Vector(const Vector& other);
    // Vector& operator= (const Vector& other);
    // ~Vector();

    void pushBack(int newElement);
    void popBack();
    void print() const;
private:
    int* vector;
    size_t size;
    size_t capacity;

    void copy(const Vector& other);
    void resize();
};