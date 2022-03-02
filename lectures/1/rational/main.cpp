#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

struct Rational;

struct Rational {
    long numer, denom;

    Rational() {
        numer = 0;
        denom = 1;
    }

    Rational(long _numer, long _denom) {
        numer = _numer;
        denom = _denom;
        normalize();
    }

    long getNumerator()   const { return numer; }
    long getDenominator() const { return denom; }

    void print() {
        cout << numer << '/' << denom;
    }

    void printnl() {
        print();
        cout << endl;
    }

    double toDouble() {
        return (double)numer / denom;
    }

    void read() {
        cin >> numer;
        // прочитане на наклонена черта
        // char c;
        // cin >> c;
        cin.ignore();
        cin >> denom;
    }

    void normalize() {
        unsigned g = gcd(abs(numer), abs(denom));
        numer /= g;
        denom /= g;
    }
};

Rational multiply(Rational const& p, Rational const& q) {
    return Rational(p.getNumerator()   * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

Rational add(Rational const& p, Rational const& q) {
    return Rational(p.getNumerator()   * q.getDenominator() + p.getDenominator() * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

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

Rational ratexp(unsigned k, unsigned n) {
    Rational result;
    for(int i = 0; i <= n; i++)
        result = add(result, Rational(power(k, i), fact(i)));
    return result;
}

int f(int);

int f(int x) { return x * x; }

extern int r;
int r = 2;

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
    const unsigned N = 13;
    const unsigned K = 0;
    ratexp(K, N).printnl();
    cout << ratexp(K, N).toDouble() << endl;
}

int main(int, char**) {
    testRational();
}
