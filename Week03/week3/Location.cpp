#include "Location.h"

void Location::copy(const Location& other_location)
{
    this->name = new char[strlen(other_location.name) + 1];
    strcpy_s(this->name, strlen(other_location.name) + 1, other_location.name);
    this->coordX = other_location.coordX;
    this->coordY = other_location.coordY;
}

void Location::erase()
{
    delete [] this->name;
}

Location::Location()
{
    this->name = new char[6];
    strcpy_s(this->name, 6, "Empty");
    this->coordX = 0;
    this->coordY = 0;
}

Location& Location::operator=(const Location &other_location)
{
    if(this != &other_location)
    {
		this->erase();
		this->copy(other_location);
	}
	return *this;
}

Location::~Location()
{
	this->erase();
}

void Location::setName(const char* _name) {
	delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

void Location::setCoordX(double _coordX) {
   this->coordX = _coordX;
}

void Location::setCoordY(double _coordY)
{
	this->coordY = _coordY;
}

const char* Location::getName() const
{
    return this->name;
}

double Location::getCoordX() const
{
    return this->coordX;
}

double Location::getCoordY() const
{
    return this->coordY;
}

void Location::print() const
{
	std::cout << name << std::endl;
	std::cout << coordX << std::endl;
    std::cout << coordY << std::endl;
}

Location::Location(const Location& other_location)
{
	this->copy(other_location);
}