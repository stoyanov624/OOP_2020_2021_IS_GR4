#include <iostream>
#include <cstring>
class Person {
private:
    char* name;
    int age;

	void copy(const Person &other);
	void erase();

public:
	Person();
	Person(const Person &other);
	Person &operator=(const Person &other);
	~Person();

	bool operator==(const Person &other_person) const;

	bool operator!=(const Person &other_person) const;

};