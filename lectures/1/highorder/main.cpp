#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>

using nextfun = int (*)(int);
using mathfun = double (*)(double);
using mathop  = double (*)(double, double);

double accumulate(mathop op, double nv,
                  double a, double b,
                  mathfun f, nextfun next) {
    double result = nv;
    for(int i = a; i <= b; i = next(i))
        result = op(result, f(i));
    return result;
}

double multiply(double x, double y) { return x * y; }
int plus1(int x) { return x + 1; }
double id(double x) { return x; }

unsigned fact(unsigned n) {
    return accumulate(multiply, 1, 1, n, id, plus1);
}

// !!! template <double x>
double gx;
double constx(double i) { return gx; }

double power(double x, long n) {
    gx = x;
    if (n < 0)
        return 1 / power(x, -n);
    return accumulate(multiply, 1, 1, n, constx, plus1);
}

void f() {
    std::cout << "f()\n";
}

void g() {
    std::cout << "g()\n";
}


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

void testFact() {
    assert(fact(0) == 1);
    assert(fact(1) == 1);
    assert(fact(5) == 120);
    assert(fact(7) == 5040);
}

void testPower() {
    assert(power(5, 0) == 1);
    assert(power(2, 5) == 32);
    assert(power(3, 3) == 27);
    assert(power(2, 10) == 1024);
    assert(power(0, 5) == 0);
    assert(power(1, 5) == 1);
    assert(power(2, -2) == .25);
    assert(fabs(power(3, -5) - 0.004115226) < 1E-6);
}

void testAccumulate() {
    testFact();
    testPower();
}

int main(int, char**) {
    std::cout << (long)main << std::endl;
    std::cout << (void*)strcpy << std::endl;
    // testFunctionPointers();
    testAccumulate();
}
