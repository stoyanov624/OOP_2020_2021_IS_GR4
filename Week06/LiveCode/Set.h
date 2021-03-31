#pragma once
const size_t MAX_CAPACITY = 50;

template <class T>
class Set {
private:
	T set[MAX_CAPACITY];
	size_t size;
public:
	Set();
	void addNewElement(const T&);
	bool elementIsInSet(const T&) const;
	void printSet() const;
	Set operator+(const T&);
	Set& operator+=(const T&);
    Set& operator=(const Set&);
    T& operator[](size_t);
};

template <class T>
Set<T>::Set() : size(0) {};

template <class T>
bool Set<T> :: elementIsInSet(const T& element) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if(set[i] == element)
			return true;
	}
	return false;
}

template <class T>
void Set<T> :: addNewElement(const T& element){
	if(this->size >= MAX_CAPACITY || elementIsInSet(element)){
		return;
	}
	set[size++] = element;
}

template <class T>
void Set<T>::printSet() const {
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << this->set[i] << " ";
	}
    std::cout << std::endl; 
}
 
template <class T>
Set<T> Set<T>::operator+(const T& element)
{
	Set<T> result;
	result = *this;
	result.addNewElement(element);
    return result;
}

// String s = "hell";
// s = s + 'o';   s=*this 'o'=element
//int elem
//set + elem;

template <class T>
Set<T>& Set<T>:: operator+=(const T& element)
{
	*this = *this + element;
    return *this;
}

template <class T>
Set<T>& Set<T>::operator=(const Set& other_set) {
    if(this != &other_set) {
        this->size = other_set.size;

        for (size_t i = 0; i < size; i++) {
            this->set[i] = other_set.set[i];
	    } 
    }
    return *this;
}

template <class T>
T& Set<T>::operator[](size_t index) {
    if(index >= 0 && index <= size) {
        return set[index];
    }

    return set[0];
} 