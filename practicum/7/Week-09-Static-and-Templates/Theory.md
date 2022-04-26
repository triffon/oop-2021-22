## Static

В C++ има три случая, в които може да се използва `static`:

- За статична променлива във функция: променливата се създава веднъж и съществува до края на програмата. Ако се вика многократно функцията, променливата помни стойността от предното извикване.   
```c++
void printSum(int n){
    static int sum = 0; //променливата се инициализира само при първото извикване на фунцкията
    sum += n;

    std::cout << sum << '\n';
}

int main(){
    printSum(5); // 5
    printSum(4); // 9
    printSum(1); // 10

    return 0;
}
```
- За статични член-данни на клас: също се инициализира само веднъж и е обща за всеки обект от този тип, тоест принадлежи на класа като цяло, а не на конкретния обект. Не може да се инициализира в конструктора.

```c++
class Object{
public:
    static int count;
    Object(){
        // count = 15; // Тук не се инициализира, а 
                   // сменяме стойността на съществуваща променлива
        count++;
    }
};

int Object::count = 0; // Тук се инициализира

int main(){
    std::cout << Object::count; // 0 

    Object first;
    std::cout << first.count; // 1 // 16

    Object second;
    std::cout << second.count;  // 2 // 16
    std::cout << first.count;   // 2 // 16
    std::cout << Object::count; // 2 // 16 
}
```
- За статични методи на клас: методите също са общи за класа и не се отнасят за конкретни различни обекти, за това в тях няма указателя `this`. Могат да достъпват само други статични данни или методи.

```c++
class Object{
public:
    //...
    static int count;
    static void printCount(){
        std::cout << count;
        std::cout << n; // НЕ!
    }
private:
    int n;
};

int main(){
    Object first;

    first.printCount(); // Може, но не е добра практика
    Object::printCount(); // ДА
}
```

## Templates

Когато трябва функция или клас да работи за повече от един тип данни, може типа да се подаде като параметър.
За целта пишем `template <typename T>` или `template <class T>` над функцията/класа.

```c++
template <typename Type>
void print(Type t){
    std::cout << t; //окей стига типът който подаваме да има дефиниран operator<<
}

int main(){
    print<int>(5); 
    print<char>('a');
    print<double>(3.14);
    // компилаторът ще генерира кода за функцията 
    // за съответния тип само ако се извика за него
    // това, което ние сме написали е шаблон, по който да го направи
}
```
```c++
template <typename Type>
class DynamicArray{
public:
    DynamicArray();
    // и т.н.

    void add(Type element);
private:
    void resize();

    Type* arr;
    size_t size;
    size_t capacity;
};

int main(){
    DynamicArray<unsigned> uArr;
    uArr.add(5);
    uArr.add(4.12331); // ще кастне до int

    DynamicArray<double> dArr;
    dArr.add(5.1);
}
```

- Може да има повече от един параметризиран тип:
```c++
template <typename T, typename U>
void print(T obj1, U obj2){
    std::cout << obj1 << " " << obj2;
}
```

- Може да има стойност по подразбиране за типа:
```c++
template <typename T, typename U = int>
void print(T obj1, U obj2){ 
    std::cout << obj1 << " " << obj2;
}

int main(){
    print<char, double>('a', 2.1);
    print<double>(2.1, 1); // <double, int> 

    return 0;
}
```

