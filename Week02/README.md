# Седмица 02 - Класове

### Основната черта, която отличава С++ от С е обектно-ориентираното програмиране. В частност дефинирането на потребителски типове. Днес ще започнем да навлизаме в ООП на по-подробно ниво и ще работим с класове. Класовете, подобно на структурите, се използват за да очертаят формата на даден обект(от реалния свят). Докато в структурите дефинирахме само полетата(данните) на обекта и ги обработвахме чрез външни функции, при класовете данните и функциите, които обработват тези данни са комбинирани заедно в дефиницията на класа. Данните и функциите се наричат членове (член-данни и член-функции/методи) на класа. 

## Дефиниция на клас
```c++
class <Name> {
   <public|private|protected>:
      <data1>;   
      <data2>;  
      <data3>;   
        ...
      <method1>;
      <method2>;
};
```
## Модификатори за достъп
+ public
+ private
+ protected

## Дефиниране на обект
```c++
<Name> object1;
<Name> object2;
```
## Достъп до членовете на даден обект
Както при структури се осъществява с оператор за достъп(.).
```c++
object1.<data1>;
object2.<method1>;
```

## Методи на класа
### Може да се дефинират вътре в класа, но може в класа да е само прототипа/дефиницията на функцията, а самата дефиниция да е извън класа. За второто преди дефиницията се използва **<Name>::<name_of_method>**, :: - scope resolution operator.

## Конструктори 
### Това са първите по-специални методи за даден клас. Те се използват за инициалнизация на обектите на класа. Тази функция се извиква автоматично, когато се създаде някъде обект от дадения клас. Основна характеристика на конструкторите е, че те имат същото име, като името на класа и нямат тип на върната стойност. 
### **Типове констриктори:**
- По подразбиране
- С параметри
- За копиране

## Селектори и мутатори/Setters & Getters 
### Tова са други методи на класа, които са ни необходими за да работим с данните на класа. Селекторите се използват, за да вземем стойност на дадена член-данна, а мутаторите са ни необходими за да променим дадена член-данна.

## Oператори
### Tова са оператори, който работят върху типа. Пример събирането за цели числа, конкатанацията на  два низа, обединението на две множества и тн.(Разгледани са на лекции).

## *this
### Всеки обект има достъп до адреса си в паметта, чрез указателя **this**. Той е НЕявен(не го пишем) параметър на всяки метод на класа, затова в тялото на метода можем да го използваме за да работим директно с обекта в паметта.

## ООП Принципи

* ### Енкапсулация
* ### Абстракция
* ### Наследяване (ще разглеждаме по - късно в курса)
* ### Полиморфизъм (ще разглеждаме по - късно в курса)

## Енкапсулация
### Енкапсулацията е принципът, който казва, че към компонентите на нашите класове не трябва да има директен достъп от външния свят. Защо? Защото не искаме всеки да има директен достъп и да прави каквито си иска промени. Пример ако вашата кола я разглеждате като клас с член данни двигател, гуми и т.н няма да искате всеки да има пряк достъп до тях и да ги ръчка както сметне за добре нали? Идеята на енкапсулацията е да имаме публично ограничени член данни в полето private и публични методи (може и член данни), чрез които моделираме какъв достъп до нашия клас има външния свят. Колкото по - недостъпни и *скрити* са нашите данни толкова по - силна е *Енкапсулацията* им.

## Абстракция
### Абстракция е принципът, който казва, че начинът, по който функционира нашия обект трябва да бъде скрит от външния свят и да не се интересуваме с каква сложност е написан той. Това позволява на потребителя да надгражда сложността без да разбира и дори да се замисля за скритата сложност. Отново пример от реалния живот ще бъде нашата кола, ние знаем как да караме една кола, но не е задължително да знаем как точно работи двигателя, как е направен и т.н. 
  
