#include <iostream>
#include <fstream>
#include <vector>

// [1,2,3]

template <typename T>
class Vector {
private:
    std::vector<T> vector;

public:
    Vector() : vector() {}

    void push_back(T element) {
        vector.push_back(element);
    }

    size_t size() {
        return vector.size();
    }

    T& operator [](size_t index) {
        return vector[index];
    }

    friend std::ostream& operator<<(std::ostream& out, Vector<T>& vector){
        out << '[';
        size_t size = vector.size();
        for (size_t i = 0; i < size; i++) {
            out << vector[i];
            if(i < size - 1) {
                out << ',';
            }
        }
        out << ']';

        return out;
    } 

    friend std::istream& operator>>(std::istream& in, Vector<T>& vector) {
        char c;
        T element;
        Vector<T> result_vector;

        in >> c;
        while(c != ']' && in.peek() != ']') {
            in >> element;
            result_vector.push_back(element);
            in >> c; // имаме запетайка
        }
        vector = result_vector;
        return in;
    }
};