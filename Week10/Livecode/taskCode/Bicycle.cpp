#include "Bicycle.h"

void Bicycle::copy(const Bicycle& other) {
    this->hasLights = other.hasLights;
	this->hasRing = other.hasRing;
	this->speeds = other.speeds;
}

Bicycle::Bicycle() : Vehicle(), hasLights(false), hasRing(false), speeds(0) {}

Bicycle::Bicycle(const char* _color, const char* _brand, size_t _year, 
                size_t _numberOfSeats, double _maxSpeed, bool _hasLights, 
                bool _hasRing, size_t _speeds) 
: Vehicle(_color, _brand, _year, _numberOfSeats, _maxSpeed), hasLights(_hasLights), hasRing(_hasRing),speeds(_speeds){}

Bicycle::Bicycle(const Bicycle& other) : Vehicle(other) {
	this->copy(other);
}

Bicycle& Bicycle::operator=(const Bicycle& other) {
	if(this != &other)
	{
        Vehicle::operator=(other);
		this->copy(other);
	}
	return *this;
}

void Bicycle::print() const {
    std::cout << "Nasheto kolelo <3\n";
    Vehicle::print();
    std::cout << "Has lights: "<< std::boolalpha << hasLights << "\n";
    std::cout << "Has ring: "<< std::boolalpha << hasRing << "\n";
    std::cout << "Number of speeds: " << speeds << "\n";
}
