#include <iostream>
#include <functional>

// Напишете функция map, която приема масив и функция, и връща нов масив, който е резултат от функцията, 
// приложена върху масива.

template <class T>
using Modifier = std::function<void(T&)>;

// void multiplyNumber(int &x) {
//     x *= 2;
// }

void addOne(int &x) {
    x++;
}

template <class T>
void map(T* arr, size_t size_arr, Modifier<T> modifier) {
    for (size_t i = 0; i < size_arr; i++) {
        modifier(arr[i]);
    }
}

template <class T>
void printArr(T* arr, size_t size_arr) {
    for (size_t i = 0; i < size_arr; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Напишете функция filter, която приема масив и функция, която връща булева стойност. 
// filter трябва да върне нов масив, който е съставен само от елементите на масива, 
// за които функцията е върнала стойност true.
 


bool isEven(const int &number) {
    return number % 2 == 0;
}

template <class T>
T* filter(T* arr, size_t size_arr,bool(*checker)(const T&)) {
	T *array = new T[size_arr];
	for (size_t i = 0, k = 0; i < size_arr; ++i)
    {
        if(checker(arr[i]))
        {
			array[k] = arr[i];
			k++;
		}
    }
    return array;
}

int main () {
    int arr[5] = {1,2,3,4,5};
    size_t size = 5;
    // map(arr,5,multiplyNumber);
    // map(arr,5,addOne);
    
    // std::function<void(int&)> funcptr1 = [] (int& x) -> void{x *= 2;};
    // std::function<void(int&)> funcptr2 = [] (int& x) -> void{x *= 3;};
    // map(arr,size,funcptr1);
    // map(arr,size,funcptr2);

    int * result = filter(arr,size,isEven);
    printArr(arr,size);
}