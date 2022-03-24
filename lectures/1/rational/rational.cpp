#include <iostream>
#include <numeric>
#include "rational.hpp"
#include "rational.hpp"
// using namespace std;

Rational::Rational(long _numer, long _denom)
    : numer(_numer), denom(_denom) {
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
    // Rational p;
    // !!! this = &p;
    normalize();
}

void Rational::normalize() {
    if (denom == 0) {
        // !!!     throw "Подаден е знаменател 0!";
        std::cerr << "Подаден знаменател 0, игнорира се" << std::endl;
        numer = 0;
        denom = 1; 
    }
    unsigned g = std::gcd(std::abs(numer), std::abs(denom));
    numer /= g;
    denom /= g;
    if (denom < 0) {
        numer = -numer;
        denom = -denom;
    }
}

Rational multiply(Rational const& p, Rational const& q) {
    return Rational(p.getNumerator()   * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

Rational add(Rational const& p, Rational const& q) {
    return Rational(p.getNumerator()   * q.getDenominator() + p.getDenominator() * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

bool lessThan(Rational const& p, Rational const& q) {
    // !!! return p.toDouble() < q.toDouble();
    // !!! return p.numer * q.denom < p.denom * q.numer;
    return p.getNumerator() * q.getDenominator() < q.getNumerator() * p.getDenominator();
    // if (X) return true; else return false;   <-> return X;
    // return X ? true : false;      <-> return X;
}

inline bool Rational::equals(Rational const& p) const {
    return numer == p.numer && denom == p.denom;
}