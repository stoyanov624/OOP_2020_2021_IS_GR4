#include <iostream>
#include <cstring>
// Да се напише структура, представляваща студент, която съдържа информация за
// име на студента (не по - дълго от 30 символа);
// ЕГН (не по - дълго от 10 символа);
// факултетен номер;
// списък от оценки.
//Student(<подходящ тип> name, <подходящ тип> egn, <подходящ тип> fac_number, <подходящ тип> grades_list);
struct Student
{
    char *name;
    char egn[11];
    int fac_number;
    double grades_list[6]; //= {0};

    Student()
    {
        name = new char[10];
        strcpy_s(name, 8, "student");
        strcpy_s(egn, 11, "0000000000");
        fac_number = 0;

        for (size_t i = 0; i < 6; i++)
            grades_list[i] = 0;
    }

    Student(const char* _name,const char* _egn, int _fac_number, double* _grades_list)
    {
        name = new char[strlen(_name) + 1];    
        strcpy_s(name, strlen(_name) + 1 , _name);
        strcpy_s(egn,strlen(_egn) + 1, _egn);
        fac_number = _fac_number;
        
        for (int i = 0; i < 6; ++i)
              grades_list[i] = _grades_list[i];
    }

    void printData()
    {
        std::cout << name << std::endl;
        std::cout << egn << std::endl;
        std::cout << fac_number << std::endl;

        for (size_t i = 0; i < 6; i++)
            std::cout << grades_list[i] << ' ';

        std::cout << std::endl;
    }
};


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
