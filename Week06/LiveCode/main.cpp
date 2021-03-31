#include <iostream>
#include "Set.h"

int main () {
    Set<int> set1;
    Set<char> set2;

    set1.addNewElement(1);
    set1.addNewElement(2);

    set2.addNewElement('a');
    set2.addNewElement('b');
    set2 += 'c';

    set1[0] = 6;
    std::cout << set1[0];

}