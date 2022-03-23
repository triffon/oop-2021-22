#include <iostream>
#include <cmath>
#include "rational.hpp"
// using namespace std;

struct Rational;

int f(int);

int f(int x) { return x * x; }

extern int r;
int r = 2;

unsigned fact(unsigned n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

double power(double x, int n) {
    if (n == 0)
        return 1;
    if (n > 0)
        return x * power(x, n - 1);
    // n < 0
    return 1 / power(x, -n);
}

// ниво 3: приложна програма
Rational ratexp(unsigned k, unsigned n) {
    Rational result;
    for(int i = 0; i <= n; i++)
        result = add(result, Rational(power(k, i), fact(i)));
    return result;
}

void testRational() {
    Rational r;
    r = Rational();
    std::cout << r.getNumerator() << '/' << r.getDenominator() << std::endl;
    r = Rational(2, 3);
    r.printnl();
    // Rational q(5, 6);
    Rational q = Rational(5, 6);
    q.printnl();
    std::cout << q.toDouble() << std::endl;
    q.read();

    q.printnl();
    r.print();
    std::cout << " * ";
    q.print();
    std::cout << " = ";
    multiply(r, q).printnl();

    r.print();
    std::cout << " + ";
    q.print();
    std::cout << " = ";
    add(r, q).printnl();

    std::cout.precision(15);
    std::cout << exp(1) << std::endl;
    const unsigned N = 11;
    const unsigned K = 1;
    ratexp(K, N).printnl();
    std::cout << ratexp(K, N).toDouble() << std::endl;

    // Rational s(5);
    Rational s = 5;
    // !!! Rational s(&r);
    Rational r2 = r;
    Rational r3(r);
    Rational r4 = Rational(r);
}

int main(int, char**) {
    testRational();
}
