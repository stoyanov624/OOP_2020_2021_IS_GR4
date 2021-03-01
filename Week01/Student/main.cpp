#include <iostream>
#include <cstring>
const int MAX_GRADES_COUNT = 6;

struct Student {
    char* name;
    char egn[11];
    int fac_number;
    double grades_list[MAX_GRADES_COUNT] = {0};

    Student() {
        // тъй като тук тепърва ще конструираме напия обект ТРЯБВА първо да заделим памет за член данните, които ще работят с дин. памет
        name = new char[20];
        strcpy_s(name,8,"student");
        strcpy_s(egn,11, "0000000000"); 
        fac_number = 0;

        for (size_t grade = 0; grade < MAX_GRADES_COUNT; ++grade) // алтернатива на = {0} написано по - горе 
            grades_list[grade] = 0;
    }

    // трябва да се стараем да подаваме данни като масив с const, за да се подсигурим, че няма да бъдат променяни в конструктора
    // за const char* също е удобно защото може да подадем какъвто и да е стринг на конструктора от сорта на "Ivan", без да има нужда
    // Ivan да го записвам в отделна променлива.
    Student(const char* _name, const char* _egn, int _fac_number,const double* _grades_list) { 
        size_t length_of_name = strlen(_name);
        size_t length_of_EGN = strlen(_egn);

        name = new char[length_of_name + 1];
        strcpy_s(name, length_of_name + 1, _name);
        strcpy_s(egn, length_of_EGN + 1, _egn); 
        fac_number = _fac_number;

        for (size_t grade = 0; grade < MAX_GRADES_COUNT; ++grade)
            grades_list[grade] = _grades_list[grade];
    }

    //подаваме другия студент по референция тъй като не искаме функцията да направи копие на този обект (като я извикаме 100 пъти и направи 100 копия с по - тежки данни няма да се хареса на комютъра и ще работи бавно). 
    //слагаме const пред аргумент защото не искаме в този метод да го променяме.
    void initializeStudent(const Student& other_student) { 
        size_t length_of_name = strlen(other_student.name);
        size_t length_of_EGN = strlen(other_student.egn);

        name = new char[length_of_name + 1];
        strcpy_s(name, length_of_name + 1, other_student.name);
        strcpy_s(egn, length_of_EGN + 1, other_student.egn); 
        fac_number = other_student.fac_number;

        for (size_t grade = 0; grade < MAX_GRADES_COUNT; ++grade)
            grades_list[grade] = other_student.grades_list[grade];
    }

    double averageScore() {
        double sum = 0;
        for (size_t i = 0; i < MAX_GRADES_COUNT; i++) 
            sum += grades_list[i];
        
        return sum / MAX_GRADES_COUNT;
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

    // това е специален метод наречен ДЕструктор, който се грижи за динамичната памет след като обекта изчезне
    ~Student() {
        delete [] name; 
    }
};

void generateStudents(Student* list_of_students, size_t amount_of_students) {
    char name[50];
    char egn[11];
    int fac_number = 0;
    double grades_list[MAX_GRADES_COUNT];

    // Взимаме си данните от тази функция, тъй като не е хубаво да имаме std::cin вътре в структурата.
    for(size_t i = 0; i < amount_of_students; ++i) {
        std::cout << "Enter student name: ";
        std::cin.getline(name,50);
        std::cout << "Enter student EGN: ";
        std::cin.getline(egn, 11);
        std::cout << "Enter student FN: ";
        std::cin >> fac_number;

        std::cout << "Enter student grades: ";

        for (size_t i = 0; i < MAX_GRADES_COUNT; i++) {
            std::cin >> grades_list[i];
        }

        Student temp_student(name, egn,fac_number,grades_list);
        list_of_students[i].initializeStudent(temp_student);
        std::cin.get();
        std::cout << std::endl;
    }
}

void printStudents(Student* list_of_students, size_t amount_of_students) {
    for (size_t i = 0; i < amount_of_students; i++) {
        list_of_students[i].printData();
        std::cout << std::endl;
    }
}

const Student& getBestStudent(Student* list_of_students, size_t amount_of_students) {
    size_t indexOfBestStudent = 0;

    for (size_t i = 0; i < amount_of_students; i++) {
        if(list_of_students[indexOfBestStudent].averageScore() < list_of_students[i].averageScore()) 
            indexOfBestStudent = i;
    }

    return list_of_students[indexOfBestStudent];
    
} 

int main () {
    size_t size = 2;
    Student* list_of_students = new Student[size];
    generateStudents(list_of_students,size);
    Student test_student;
    test_student = getBestStudent(list_of_students, size);
    test_student.printData();
}   