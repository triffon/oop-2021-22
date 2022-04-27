#include <iostream>
#include "../files/product.hpp";

template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void f(T x) {
    x << x >> x;
    delete x;
    int a[x];
}

void testSwap() {
    int a = 3, b = 5;
    std::cout << a << ' ' << b << std::endl;
    swap<>(a, b);
    std::cout << a << ' ' << b << std::endl;
    double x = 3.58, y = 5.813;
    std::cout << x << ' ' << y << std::endl;
    swap<>(x, y);
    std::cout << x << ' ' << y << std::endl;
    // !!! f(2);
}

template <typename T>
size_t readArray(T* array, std::istream& is = std::cin) {
    std::cout << "Моля, въведете брой елементи: ";
    size_t count;
    is >> count;
    for(int i = 0; i < count; i++) {
        std::cout << "Моля, въведете елемент с индекс " << i << ": ";
        is >> array[i];
    }
    return count;
}

template <typename T>
void writeArray(T* array, size_t count, char const* name = "a", std::ostream& os = std::cout) {
    for(int i = 0; i < count; i++) {
        os << name << '[' << i << "] = " << array[i] << std::endl;
    }
}

template <typename T>
unsigned countOccurrences(T* array, size_t count, T const& element) {
    unsigned occurrences = 0;
    for(int i = 0; i < count; i++) {
        if (array[i] == element)
            occurrences++;
    }
    return occurrences;
}

void testReadWriteArray() {
    const int MAX = 10;
    int array[MAX];
    size_t numbersCount = readArray(array);
    writeArray(array, numbersCount, "array");
    std::cout << "Числото 3 се среща " << countOccurrences(array, numbersCount, 3)
              << "пъти " << std::endl;

    Product products[MAX];
    writeArray(products, readArray(products), "products");
    Product chair(103, "Хубав стол", 29.90);
    //  countOccurrences(products, 3, chair);

}

int main() {
    //testSwap();
    testReadWriteArray();
}
