#include <iostream>
#include <functional>

template <class T>
using modifierTwo = void (*) (T&);

void doubleNumber(int &number) {
    number *= 2;
}

void addTwo(int &number) {
    number += 2;
}

int main() {
    void (*modifier) (int&);
    modifier = &doubleNumber;

    modifierTwo<int> modTwo = &addTwo;

    int numberA = 10;
    int numberB = 15;
    modifier(numberA);
    modTwo(numberB);

    std::cout << numberA << std::endl; 
    std::cout << numberB << std::endl;

    int numberC = 10;
	std::function<int(int)> returner = [](int x) -> int {
        std::cout << "Before modification: " << x << std::endl;
        doubleNumber(x);
        std::cout << "After modification: " << x << std::endl;
        return x;};

    returner(10);                                                    
}