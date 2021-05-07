#pragma once
#include "Employee.h"

class Manager : public Employee {
private:
    int managedPeople;

public:
    void printStatus() const override {
        std::cout << "manager" << std::endl;
    }
};