#include "Vehicle.h"
#include "Bicycle.h"

int main() {
    Bicycle b1("red","volvo",1967,1599,500,true,true,9); 
    b1.print();
    std::cout << "\n";
    Bicycle b2;
    b2.print();

    std::cout << "\n";

    b2 = b1;

    b2.print();
}