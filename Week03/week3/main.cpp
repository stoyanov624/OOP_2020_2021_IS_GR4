#include <iostream>
#include "Location.h"
#include "Person.h"
// default constructor
// copy construcotr
// operator=
// destructor;


int main () {
    Location loc1;
    loc1.setName("Sofia");
    loc1.setCoordX(0);
    loc1.setCoordY(0);

    loc1.print();

    Location loc2(loc1);
    loc2.print();

    Location loc3;
    loc3.setName("Pernik");
    loc3.setCoordX(15);
    loc3.setCoordY(0);

    loc1 = loc3;
    loc1.print();
    int a = 5;
}