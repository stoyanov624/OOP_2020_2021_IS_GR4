#pragma once
#include "Employee.h"

class Programmer : public Employee {
private:
    bool knowsCplusplus;
    bool knowsJava;
    
public:
    void printStatus() const override {
        std::cout << "programmer" << std::endl;
    }
};