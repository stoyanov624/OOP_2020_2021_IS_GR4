# Exceptions
## Дефиниция
### Exceptions или изключения са проблеми, които се появяват по време на изпълнението на програмата. В С++ exception се ползва като отговор на частните случаи които може да се появят като например опит за деление на 0.
### Те ни позволяват да прехвърлим контрола от една част на кода на друга като в С++ това се изпълнява чрез ключовите думи: try, catch и throw.
- throw - Програмата "хвърля" exception когато се появи частен случай.
- catch - Програмата "хваща" exception и придоставя решение за дадения частен случай.
- try - try е част от кода в която се проверява за частен случай и при намирането на такъв кода от нея не се изпълнява, а вместо това се "хвърля" exception. Синтаксиса е такъв че винаги try е следван от един или повече catch.

``` c++
    #include <iostream>

    double division(int a, int b) {
    if( b == 0 ) { //в случая понеже не може да делин на 0 "хвърляме" exception, който в дадения пример е от тип const char*
        throw "Division by zero condition!";
    }
    return (a/b);
    }

    int main () {
    int x = 50;
    int y = 0;
    double z = 0;
    
    try {
        z = division(x, y);
        cout << z << endl;
    } catch (const char* msg) { //в catch очакваме ако има частен случай той да "хвърли" exception от тип const char*
        cout << msg << endl;
    }

    return 0;
    }
```
### Типа на exception, който "хвърляме" може да е от примитивните типове данни, но е по-добре да е обект. Има стандартни exception-ни (наследяващи std::exception), които можем да ползваме или можем да си направим custom exception.
### Стандартните:
- logic_error
    - invalid_argument
    - domain_error
    - length_error
    - out_of_range
    - future_error(C++11)
- bad_optional_access(C++17)
- runtime_error
    - range_error
    - overflow_error
    - underflow_error
    - regex_error(C++11)
    - system_error(C++11)
        - ios_base::failure(C++11)
        - filesystem::filesystem_error(C++17)
    - tx_exception(TM TS)
    - nonexistent_local_time(C++20)
    - ambiguous_local_time(C++20)
    - format_error(C++20)
    - bad_typeid
    - bad_cast
        - bad_any_cast(C++17)
    - bad_weak_ptr(C++11)
    - bad_function_call(C++11)
    - bad_alloc
        - bad_array_new_length(C++11)
    - bad_exception
    - ios_base::failure(until C++11)
    - bad_variant_access(C++17)

### custom exception:

``` c++
    class MyException : public std::exception
    {
    public:
        //overridng the method what() of std::exception
        virtual const char* what() const noexcept override { //const noexcept означава че този метод не може да "хвърля" exception-ни
            return "My error happened\n";
        }
    };
```

## Примери

``` c++
    #include <iostream>
    #include <exception>

    class InvalidArea : public std::exception //създаваме си custom exception
    {
    public:
        virtual const char* what() const noexcept override{
          //метода връща съобщение обясняващо проблема който е уловен от този exception
            return "In a square the area must be equal to the side ^ 2\n"; 
        }
    };

    class Square //класа представлява квадрат който за целта на този пример има член данна за 
                 //дължината на страната и член данна за лицето на квадрата
    {
    private:
        double side;
        double area;

    public:
        Square()
        {
            side = 1;
            area = 1;
        }

        Square(double _side, double _area) 
        {
            //тук използваме exception за да валидираме подадените на конструктура данни.
            try
            {
                if (_side * _side != _area) //ако данните не изпълняват даденото условие "хвърляме" exception
                    throw InvalidArea();
    
                std::cout << "Did it get to this part of the code?\n";
                side = _side;
                area = _area;
            }
            catch (InvalidArea& err) //очакваме exception от тип InvalidArea
            {
                std::cout << err.what();
                //за да може да продължи програмата даваме дефалтните стойности за член данните на класа
                side = 1;
                area = 1;
            }
        }

        void setSquare(double _side, double _area) //за целта на примера този метод дава стойност и на side и на area
        {
            if (_side * _side != _area) //ако не е изпълнено условието отново "хвърляме" exception 
                throw InvalidArea();    //но този път try и catch са в мейна. 

            side = _side;
            area = _area;
        }

        void print()
        {
            std::cout << "side = " << side << " area = " << area << '\n';
        }
    };

    int main()
    {
        Square sq1(5, 7);
        sq1.print();

        Square sq2;
        double side, area;
        std::cin >> side;
        std::cin >> area;
        
        try
        {
            sq2.setSquare(side, area); //тук когато метода "хвърля" exception той не 
                                       //се изпълнява а вместо това се изпълнява кода в дадения catch
        }
        catch (InvalidArea& err)
        {
            std::cout << err.what();
            sq2.setSquare(side, side * side);
        }

        sq2.print();
    }
```
``` c++
    class MyException : public std::exception
    {
    public:
        virtual const char* what() {
            return "My error happened\n";
        }
    };
```

###Примери

``` c++
    class Dynamic
    {
    private:
        int* arr;
        size_t size;
        size_t capacity;

    public:
        Dynamic()
        {
            size = 4;
            capacity = 4;
            arr = new int[capacity];
            arr[0] = 0;
            arr[1] = 1;
            arr[2] = 2;
            arr[3] = 3;
        }

        ~Dynamic()
        {
            delete[] arr;
        }

        int getAt(size_t index)
        {
            if (size <= index || index < 0)
                throw std::out_of_range("Index is out of range for this Dynamic\n");

            return arr[index];
        }

        void pushBack(int elem)
        {
            if (size >= capacity)
                throw std::overflow_error("Dynamic is full\n");

            arr[size++] = elem;
        }

        void print()
        {
            for (size_t i = 0; i < size; i++)
                std::cout << arr[i] << ' ';
            std::cout << '\n';
        }
    };

    int main()
    {
    Dynamic dyn;
    size_t index = 20;

    try //понеже индекса който подаваме на метода getAt е твърде голям метода няма да може да се изпълни 
    {   //и ще "хвърли" exception, но в случай в който се изпълни е възможно втория 
        //метод да хвърли exception затова имаме предвиден catch и за него
        int temp = dyn.getAt(index);
        dyn.pushBack(temp);
    }
    catch (std::out_of_range& err)
    {
        std::cout << err.what();
    }
    catch (std::overflow_error& err) //Ако сложим за стойност на index число между 0 и 3 ще метода getAt
    {                                //ще се изпълни без грешка, но метода pushBack ще "хвърли" exception 
        std::cout << err.what();
    }

    dyn.print()
    }
```
