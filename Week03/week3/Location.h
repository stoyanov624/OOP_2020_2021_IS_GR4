#pragma once
#include <iostream>
#include<cstring>
// Да се дефинира клас Location, който има член-данни указател към първия елемент на динамичен масив
//от символи за име (символен низ с произволна дължина) на локацията и две числа от тип double за
//координати. Класа трябва да съдържа голяма четворка, сетъри и гетъри и член-функция print.
class Location {
private:
    char* name;
    double coordX;
    double coordY;

    void copy(const Location& other_location);
    void erase();
public:
    Location();
    Location& operator=(const Location& other_location);
    Location(const Location& other_location);
    ~Location();

    void setName(const char* _name);
    void setCoordX(double _coordX);
    void setCoordY(double _coordY);

    const char* getName() const;
    double getCoordX() const;
    double getCoordY() const;

    void print() const;
};