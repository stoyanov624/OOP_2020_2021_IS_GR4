#include <iostream>
#include <string.h>
#include "Baby.h"
class Animal {
private:
    enum class Type {CARNIVOROUS, VEGAN, TREVOPASNO} animalType;
public:
    Animal () {
        animalType = Type::VEGAN;
    }

    Animal(int type) {
        switch(type) {
            case 0: animalType = Type::CARNIVOROUS; break;
            case 1: animalType = Type::VEGAN; break;
            case 2: animalType = Type::TREVOPASNO; break;
        }
    }

    void printWayOfEating() {
        switch(animalType) {
            case Type::CARNIVOROUS: std::cout << "carn"; break;
            case Type::VEGAN: std::cout << "vegan"; break;
            case Type::TREVOPASNO: std::cout << "treva"; break;
        }
    }
};

class Printer {
public:
    static void printA4() {
        std::cout << "I printed an A4 list" << std::endl;
    }
    static void printA5() {
        std::cout << "I printed an A5 list" << std::endl;
    }
};

void iterateFunc() {
    static int counter = 0;
    counter++;
    std::cout << counter << std::endl;
}

int main () {
    Baby b1;
    Baby b2;
    Baby b3;

    b1.printBabyCount();
    b2.printBabyCount();
    b3.printBabyCount();
}   