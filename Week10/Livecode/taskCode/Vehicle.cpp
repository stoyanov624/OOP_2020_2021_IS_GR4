#include "Vehicle.h"

Vehicle::Vehicle()
{
    this->color = new char[1];
    this->color[0] = '\0';
    this->brand = new char[1];
    this->brand[0] = '\0';
    this->year = 0;
    this->numberOfSeats = 0;
    this->maxSpeed = 0;
}

Vehicle::Vehicle(const char* color, const char* brand, size_t year, size_t numberOfSeats, double maxSpeed)
{
    this->color = new char[strlen(color) + 1];
    strcpy_s(this->color, strlen(color) + 1, color);
    this->brand = new char[strlen(brand) + 1];
    strcpy_s(this->brand, strlen(brand) + 1, brand);
    this->year = year;
    this->numberOfSeats = numberOfSeats;
    this->maxSpeed = maxSpeed;
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
    if(this != &other)
    {
		this->erase();
		this->copy(other);
    }
    return *this;
}
 
Vehicle::Vehicle(const Vehicle& other)
{
    this->copy(other);
}

Vehicle::~Vehicle()
{
    std::cout << "Destroing Vehicle" << std::endl;
    this->erase(); 
}

void Vehicle::copy(const Vehicle& other)
{
    this->color = new char[strlen(other.color) + 1];
    strcpy_s(this->color, strlen(other.color) + 1, other.color);
    this->brand = new char[strlen(other.brand) + 1];
    strcpy_s(this->brand, strlen(other.brand) + 1, other.brand);
    this->year = other.year;
    this->numberOfSeats = other.numberOfSeats;
    this->maxSpeed = other.maxSpeed;
}

void Vehicle::erase()
{
    delete[] this->color;
    delete[] this->brand;
}

void Vehicle::print() const
{
	std::cout << "Color: " << this->color << std::endl;
    std::cout << "Brand: " << this->brand << std::endl;
    std::cout << "Year: " << this->year << std::endl;
    std::cout << "Number of seats: " << this->numberOfSeats << std::endl;
    std::cout << "Max speed: " << this->maxSpeed << std::endl;
}