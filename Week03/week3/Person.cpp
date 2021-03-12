#include "Person.h"

void Person::copy(const Person& other) {
    name = new char[strlen(other.name) + 1];
    strcpy_s(name,strlen(other.name) + 1,other.name);
    age = other.age;
}

void Person::erase() {
    delete [] name;
}

Person::Person() {
        name = new char[1];
        name[0] = '\0';
        age = 0;
    }

Person::Person(const Person& other) {
    this->copy(other);
}

Person& Person::operator=(const Person& other) {

    if(this != &other) {
        this->erase();
        this->copy(other);
    }

    return *this;
}
    
Person::~Person() {
    std::cout << "Destruction";
    this->erase();
}

bool Person::operator==(const Person& other_person ) const {
    return age == other_person.age;
}

bool Person::operator!=(const Person& other_person) const {
    return !(*this == other_person);
}