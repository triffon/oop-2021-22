#include <iostream>
#include <cmath>
#include "rational.hpp"
using namespace std;

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
    cout << r.getNumerator() << '/' << r.getDenominator() << endl;
    r = Rational(2, 3);
    r.printnl();
    // Rational q(5, 6);
    Rational q = Rational(5, 6);
    q.printnl();
    cout << q.toDouble() << endl;
    q.read();

    q.printnl();
    r.print();
    cout << " * ";
    q.print();
    cout << " = ";
    multiply(r, q).printnl();

    r.print();
    cout << " + ";
    q.print();
    cout << " = ";
    add(r, q).printnl();

    cout.precision(15);
    cout << exp(1) << endl;
    const unsigned N = 11;
    const unsigned K = 1;
    ratexp(K, N).printnl();
    cout << ratexp(K, N).toDouble() << endl;
}

int main(int, char**) {
    testRational();
}
