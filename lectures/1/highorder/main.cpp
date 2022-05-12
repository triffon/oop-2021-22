#include <iostream>
#include <cstring>

void f() {
    std::cout << "f()\n";
}

void g() {
    std::cout << "g()\n";
}

int plus1(int x) { return x + 1; }

void testFunctionPointers() {
    std::cout << (void*)f << std::endl;
    std::cout << (void*)g << std::endl;
    std::cout << "Коя функция искате да извикам? ";
    char c;
    std::cin >> c;
    std::cout << "Колко пъти да я извикам? ";
    unsigned count;
    std::cin >> count;

    using procedure = void (*)();

    //void (*fptr)() = testFunctionPointers;
    procedure fptr = testFunctionPointers;
    switch(c) {
        case 'f' : fptr = f; break;
        case 'g' : fptr = g; break;
    }
    // !!! fptr = plus1;
    for(int i = 0; i < count; i++)
        fptr();
        //(*fptr)();
}

int main(int, char**) {
    std::cout << (long)main << std::endl;
    std::cout << (void*)strcpy << std::endl;
    testFunctionPointers();
}
