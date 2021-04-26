#include <iostream>
#include <cstring>

class Card {
protected:
    int power;

    Card() {
        power = 0;
    }

    Card(int power) {
        this->power = power;
    }
};

class WindCard : public Card {
    int windPower;

    WindCard() : Card() {
        windPower = 0;
    }

    WindCard(int power,int windPower) : Card(power) {
        this->windPower = windPower;
    } 
};


int main() {
    
}