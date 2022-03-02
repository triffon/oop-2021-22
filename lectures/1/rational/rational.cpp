#include <iostream>
#include <numeric>
#include "rational.hpp"
// using namespace std;

Rational::Rational() {
    numer = 0;
    denom = 1;
}

Rational::Rational(long _numer, long _denom) {
    numer = _numer;
    denom = _denom;
    normalize();
}

void Rational::print() const {
    std::cout << numer << '/' << denom;
}

void Rational::printnl() const {
    print();
    std::cout << std::endl;
}

double Rational::toDouble() const {
    return (double)numer / denom;
}

void Rational::read() {
    std::cin >> numer;
    // прочитане на наклонена черта
    // char c;
    // cin >> c;
    std::cin.ignore();
    std::cin >> denom;
}

void Rational::normalize() {
    unsigned g = std::gcd(abs(numer), abs(denom));
    numer /= g;
    denom /= g;
}

Rational multiply(Rational const& p, Rational const& q) {
    return Rational(p.getNumerator()   * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

Rational add(Rational const& p, Rational const& q) {
    return Rational(p.getNumerator()   * q.getDenominator() + p.getDenominator() * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}
