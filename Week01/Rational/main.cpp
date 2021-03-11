#include <iostream>

struct Rational {
    int numerator;
    int denominator;

     // вместо да правим някакъв метод makeRational, може направо да си направим конструктор, който върши същата работа.
    Rational() {
        numerator = 1;
        denominator = 1;
    }
    
    Rational(int other_numerator, int other_denominator) {
        if(other_denominator == 0) {
            std::cout << "Invalid arguments! We can't have a denominator that is 0!" << std::endl;
            std::cout << "Setting number to 1/1!" << std::endl;
            numerator = 1;
            denominator = 1;
        } else {
            numerator = other_numerator;
            denominator = other_denominator;
        }
        
    }

    int number() {
        return numerator;
    }

    int denom() {
        return denominator;
    }

    void print () {
        std::cout << numerator << std::endl;
        std::cout << '-' << std::endl;
        std::cout << denominator << std::endl;
    }
};

// Пред Rational имаме &, защото искаме да ползваме референция към обекта, който подаваме като аргумент, НЕ искаме да правим копия на обекти, защото ако обектите са по - сложни с много член данни това ще е бавно и некачествено.
Rational productOfRationalNumbers(Rational& rat1, Rational& rat2) {
    Rational result_of_product;
    result_of_product.numerator = rat1.numerator * rat2.numerator;
    result_of_product.denominator = rat1.denominator * rat2.denominator;

    return result_of_product;
}

Rational divisionOfRationalNumbers(Rational& rat1, Rational& rat2) {
    Rational result_of_division;
    result_of_division.numerator = rat1.numerator * rat2.denominator;
    result_of_division.denominator = rat1.denominator * rat2.numerator;

    return result_of_division;
}

Rational getBiggerRationalNumber(Rational& rat1, Rational& rat2) {
     // c++ не се усеща, че вече искаме число с плаваща запетая и трябва да направим явно кастване иначе ако разделим 1 с 2 ще получим 0, а не 0.5

    double calculation1 = (double)rat1.numerator / rat1.denominator;
    double calculation2 = (double)rat2.numerator / rat2.denominator; 

    if(calculation1 >= calculation2) 
        return rat1;

    return rat2;
}

Rational getBiggestRationalNumber(Rational* rat_numbers, size_t size) {
    Rational biggest_rat = rat_numbers[0];

    for (size_t i = 1; i < size; i++) {
        biggest_rat = getBiggerRationalNumber(biggest_rat,rat_numbers[i]);
    }

    return biggest_rat;
    
}


int main () {
    Rational rat1(1,5);
    Rational rat2(1,4);
    Rational rat3(1,3);
    Rational rat4(1,1);
    Rational rat5(2,1);
    Rational rat6(1,10);

    Rational rat_numbers[6] = {rat1,rat2,rat3,rat4,rat5,rat6};
    size_t size = 6;
    Rational rat;
    rat = getBiggestRationalNumber(rat_numbers,size);
    rat.print();
}