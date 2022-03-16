#include <iostream>
#include "stack.hpp"

void convertBase() {
    unsigned n;
    std::cout << "n = ";
    std::cin >> n;

    unsigned base;
    do {
        std::cout << "base = ";
        std::cin >> base;
    } while (base < 2 || base > 10);

    Stack s;
    unsigned k = n;
    while (k > 0) {
        s.push(k % base);
        k /= base;
    }

    std::cout << n << "(10) = ";
    while (!s.empty())
        std::cout << s.pop();
    std::cout << "(" << base << ")" << std::endl;

}

int main(int, char**) {
    convertBase();
}
