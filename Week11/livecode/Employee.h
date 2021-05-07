#include <iostream>
#pragma once

class Employee {
protected:
    char* name;
    int id;
    int exp;
    double salary;

public:
    Employee();
    Employee(const Employee&);
    Employee& operator= (const Employee&);
    virtual ~Employee();

    virtual void printStatus() const = 0;
};