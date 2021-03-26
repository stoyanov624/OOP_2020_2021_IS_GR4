#include <iostream>
#include "Point.h"
#include "Line.h"
// Принтира елементите на масив (независимо от неговия тип)

// Смята средноаритметично на масив (стига масива да е с числени стойности или от обекти с предефенирани оператоти + и /).

template <size_t SIZE,typename T>
void print(T (&array)[SIZE]) {
	for (size_t i = 0; i < SIZE; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

template <size_t SIZE, typename T>
T average(T (&array)[SIZE]){
	T sum = 0;
	for (size_t i = 0; i < SIZE; i++) {
		sum += array[i];
	}
	return (T)sum / SIZE;
}

template <typename T>
void swap (T& symbol1, T& symbol2){
	T temp;
	temp = symbol1;
	symbol1 = symbol2;
	symbol2 = temp;
}

template <size_t SIZE, typename T>
unsigned int indexMax(T (&arr)[SIZE])
{
	unsigned int indexOfMaxElement = 0;
	for(size_t i = 1; i<SIZE; ++i)
	{
		if(arr[i] > arr[indexOfMaxElement])
		{
			indexOfMaxElement = i;
		}
	}
	return indexOfMaxElement;
}

template <size_t SIZE, typename T>
unsigned int indexMin(T (&arr)[SIZE])
{
	unsigned int indexOfMinElement = 0;
	for (size_t i = 1;i<SIZE;i++)
	{
		if(arr[i] < arr[indexOfMinElement])
		{
			indexOfMinElement = i;
		}
	}
	return indexOfMinElement;
}

// void swap(T elem1, T elem2)
// unsigned int indexMax(T* arr)
// unsigned int indexMin(T* arr)

int main () {
    Point<int> p1(1,2);
    Point<int> p2(1,3);

    Line<int> line(p1,p2);

    std::cout << line;
}