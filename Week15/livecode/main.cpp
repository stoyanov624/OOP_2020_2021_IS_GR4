#include <iostream>
#include "LList.h"
#include <vector>
int main () {
    LList<int> list;
    list.push_back(3);
    list.push_back(5);
    list.push_back(6);

    LList<int> list2 = list;

    for(LList<int>::Iterator it = list2.begin(); it != list2.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    for (int element : list2) {
        std::cout << element << " ";
    }

    // std::vector<int> v1;
    // v1.push_back(1);
    // v1.push_back(2);
    // v1.push_back(3);

    // for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
    //      std::cout << *it << " ";
    // }

    //  std::cout << "\n";

    // for (int element : v1) {
    //     std::cout << element << " ";
    // }
    
}