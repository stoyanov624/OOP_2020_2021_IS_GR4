#include "Vector.h"
 
Vector::Vector() {
    this->size = 0;
    this->capacity = 8;
    this->vector = new int[this->capacity];
}

void Vector::resize() {
    this->capacity *= 2;
    int* biggerVector = new int[this->capacity];

    for (size_t i = 0; i < size; i++) {
        biggerVector[i] = this->vector[i];
    }

    delete [] vector;
    this->vector = biggerVector;
}

void Vector::copy(const Vector& other) {
    this->vector = new int[other.capacity];
    this->size = other.size;
    this->capacity = other.capacity;

    for (size_t i = 0; i < size; i++) {
        this->vector[i] = other.vector[i];
    }
}

void Vector::pushBack(int newElement) {
    if(size >= capacity) {
        this->resize();
    }

    this->vector[size] = newElement;
    size++;
}

void Vector::popBack() {
    if(size > 0) {
        this->size--;
    }
}

void Vector::print() const {
    for (size_t i = 0; i < size; i++) {
        std::cout << this->vector[i] << std::endl;
    }
}