#include <iostream>
#include <cstring>
class Vehicle {
protected:
    char brand[10];
    double price;
public:
    Vehicle() {
        strcpy_s(brand,1,"");
        price = 0;
    }

    Vehicle(const char* brand, double price) {
        strcpy_s(this->brand, strlen(brand) + 1, brand);
        this->price = price;
    }

    void printVehicleInfo() const {
        std::cout << brand << std::endl;
        std::cout << price << std::endl;
    }
};

class Car : public Vehicle {
public:
    Car() : Vehicle() {}
    Car(const char* brand, double price) : Vehicle(brand, price) {}

    void startNitro() {
        std::cout << "starting nitro" << std::endl; 
    }
};

class Jeep : public Vehicle {
public:
    Jeep() : Vehicle() {}
    Jeep(const char* brand, double price) : Vehicle(brand,price) {}

    void start4po4() {
        std::cout << "starting 4 po 4" << std::endl; 
    }
};

class Bus : public Vehicle {
public:
    Bus() : Vehicle() {}    
    Bus(const char* brand, double price) : Vehicle(brand, price) {}
    void startDrifting() {
        std::cout << "start drifting" << std::endl;
    }
};

int main() {
    Car c1("Golf",100000);
    Bus b1("Mazda",123213);
    Jeep j1("JEEP", 1344);

    c1.printVehicleInfo();
    b1.printVehicleInfo();
    j1.printVehicleInfo();

    c1.startNitro();
    b1.startDrifting();
    j1.start4po4();
}