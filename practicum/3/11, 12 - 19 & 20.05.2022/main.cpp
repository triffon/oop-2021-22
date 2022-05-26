#include <iostream>

#include "Array.hpp"

template <typename T>
T add1(const T &num) {
    return num + 1;
}

template <typename T>
T print(const T &num) {
    std::cout << num << " ";
    return num;
}

template <typename T>
bool even(const T &num) {
    return num % 2 == 0;
}

int main() {
    Array<int> asd;
    asd.add(1);
    asd.add(2);
    asd.add(3);
    asd.add(4);
    asd.add(5);
    asd.map(add1);
    Array<int> asd1 = asd.filter(even);
    asd1.map(print);
}