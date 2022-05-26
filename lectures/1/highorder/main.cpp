#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>

using nextfun = int (*)(int);
using mathfun = double (*)(double);
using mathop  = double (*)(double, double);

double accumulate(mathop op, double nv,
                  double a, double b,
                  auto f, nextfun next) {
    double result = nv;
    for(int i = a; i <= b; i = next(i))
        result = op(result, f(i));
    return result;
}

double multiply(double x, double y) { return x * y; }
double add(double x, double y) { return x + y; }
int plus1(int x) { return x + 1; }

unsigned fact(unsigned n) {
    return accumulate(multiply, 1, 1, n, [](double x) { return x; }, plus1);
}

// !!! template <double x>
/*
double gx;
double constx(double i) { return gx; }
*/

double power(double x, long n) {
    // !!! gx = x;
    if (n < 0)
        return 1 / power(x, -n);
    return accumulate(multiply, 1, 1, n, [x](double i) { return x; }, plus1);
}

/*
double expterm(double i) {
    return power(gx, i) / fact(i);
}
*/

double myexp(double x, unsigned n) {
    // !!! gx = x;
    return accumulate(add, 0, 0, n,
                      [x](double i){ return power(x, i) / fact(i); }, plus1);
}

/*
mathfun gf;
double derivative(double x) {
    const double DX = 1E-6;
    return (gf(x + DX) - gf(x)) / DX;
}
*/

auto derive(auto f) {
// !!!    gf = f;
    const double DX = 1E-6;
    return [f,DX](double x) { return (f(x + DX) - f(x)) / DX; };
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

void testExp() {
    const double PRECISION = 1E-3;
    assert(fabs(myexp(0, 10) - 1) < PRECISION);
    assert(fabs(myexp(1, 10) - exp(1)) < PRECISION);
    std::clog.precision(6);
    std::clog.setf(std::ios::fixed);
    std::clog << myexp(2.3, 13) << ' ' << exp(2.3) << std::endl;
    assert(fabs(myexp(2.3, 13) - exp(2.3)) < PRECISION);
}

void assertDoubleEqual(double x, double y, double precision = .1) {
    std::clog << "Testing " << x << " = " << y << std::endl;
    assert(fabs(x - y) < precision);
}

void testDerive() {
    assertDoubleEqual(derive([](double x) { return x * x; })(5), 10);
    assertDoubleEqual(derive(sin)(3), cos(3));
    assertDoubleEqual(derive(exp)(5), exp(5));
    assertDoubleEqual(derive(derive([](double x) { return x * x * x; }))(5), 30);
    assertDoubleEqual(derive(derive(sin))(3), -sin(3));
    assertDoubleEqual(derive(derive(exp))(5), exp(5));
}

void testAccumulate() {
    testFact();
    testPower();
    testExp();
    testDerive();
}

int main(int, char**) {
    std::cout << (long)main << std::endl;
    std::cout << (void*)strcpy << std::endl;
    // testFunctionPointers();
    testAccumulate();
}
