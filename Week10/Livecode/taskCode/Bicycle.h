#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle {
private:
    bool hasLights;
	bool hasRing;
	size_t speeds;
	void copy(const Bicycle&);
public:
	Bicycle();
	Bicycle(const char*, const char*, size_t, size_t, double, bool, bool, size_t);
	Bicycle(const Bicycle&);
	Bicycle& operator=(const Bicycle&);
	void print() const;
};