#include <iostream>
class Baby {
private:
    static int countBaby;
    int babyID = 1;
public:
    Baby();
    void printBabyCount() const;
};