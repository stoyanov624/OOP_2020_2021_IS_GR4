# Сериализация и Десериализация
## Дефиниции
### Серелизацията е изкуството да записваме / извеждаме информацията за класовете, които пишем по определен начин, т.е по определени правила, които ние измисляме. Това най - често става чрез предефиниране на оператор <<.

<br>

### Десериализацията е изкуството на база това КАК сме си **сериализирали** информацията така и да я прочетем, най - лесния пример е с демонстрация с Vector 

``` c++
friend std::ostream& operator<<(std::ostream& out, const Vector<T>& vec) {
		size_t size = vec.getSize();
		out << '[';
		for (size_t i = 0; i < size; i++) {
			out << vec[i];
			if(i < size - 1) {
				out << ',';
			}
		}

		out << ']';
		
		return out;
	}
```

``` c++
// това е оператор >> в случай, че сме записали вектор в следния формат : [1,2,3]
	friend std::istream& operator>>(std::istream& in, Vector<T>& vec) {
    
		char c;
		T element;
		Vector<T> resultVector;
		in >> c; // прочитаме знак '['
		// проверяваме c дали е станало ']' и с in.peek()   проверяваме следващия елемент дали не е станал ']'
	
		while(c != ']' && in.peek() != ']') { 
			in >> element; // прочитаме си елемента;
			resultVector.push_back(element); // слагаме го  в резултатния вектор
			in >> c; // прочитаме си запетайката
		}
	
		vec = resultVector;
		return in;
	    
    }
```

``` c++
// main.cpp
Vector<int> vec;
std::cin >> vec; // при въвеждане на [1,2,3] ще запишем във вектора елементите 1 2 и 3
std::cout << std::endl << vec;  // тук ще ги изпринтираме.
```


### Помощни методи от istream и ostream
- ostream -> seekp - https://www.cplusplus.com/reference/ostream/ostream/seekp/
- ostream -> tellp - http://www.cplusplus.com/reference/ostream/ostream/tellp/
- istream -> seekg - https://www.cplusplus.com/reference/istream/istream/seekg/
- istream -> peek - https://www.cplusplus.com/reference/istream/istream/peek/
- istream -> tellg - https://www.cplusplus.com/reference/istream/istream/tellg/