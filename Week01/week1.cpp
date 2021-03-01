#include <iostream>
#include <cstring>
#include "Student.h"


int main()
{
    Student s1;
	s1.printData();

    std::cout << std::endl;
    double grades[6] = {3.5, 5,4,2,4,6};
    Student s2("Ivo","666",71975,grades);
	s2.printData();
    std::cout << std::endl;

}
