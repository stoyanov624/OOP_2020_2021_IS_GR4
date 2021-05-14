#include "Baby.h"
int Baby::countBaby = 0;

Baby::Baby() {
        ++countBaby;
        babyID = countBaby;
    }

void Baby::printBabyCount() const {
        std::cout << babyID << std::endl;
}