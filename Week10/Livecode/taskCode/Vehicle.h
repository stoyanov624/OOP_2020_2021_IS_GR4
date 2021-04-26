#pragma once
#include <iostream>
#include <cstring>

class Vehicle {
protected:
    char* color;
    char* brand;
    size_t year;
    size_t numberOfSeats;
    double maxSpeed;
private:
    void copy(const Vehicle&);
	void erase();
public:
    Vehicle();
    Vehicle(const char*, const char*, size_t, size_t, double);
    Vehicle(const Vehicle&);
    Vehicle& operator=(const Vehicle&);
    ~Vehicle();
    void print() const;
};