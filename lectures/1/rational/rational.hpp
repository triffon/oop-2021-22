//#pragma once

#ifndef __RATIONAL_HPP
#define __RATIONAL_HPP

class Rational {
private:
    // ниво 0: представяне
    // numer е цяло число
    // denom е положително число
    // gcd(numer,denom) = 1
    long numer, denom;

    // ниво 1: вътрешна функция за нормализация
    void normalize();

    // ниво 1: конструктори
public:
    // конструктор с параметри по подразбиране
    Rational(long _numer = 0, long _denom = 1);

    // ниво 1: селектори за достъп
    long getNumerator()   const { return numer; }
    long getDenominator() const { return denom; }

    // ниво 1: селектори за извеждане
    void print()   const;
    void printnl() const;

    // ниво 1: селектор за конвертиране
    double toDouble() const; 

    // ниво 1: мутатор за въвеждане
    void read();

    // ниво 1: селектор за сравнение
    bool equals(Rational const& p) const;
};

// ниво 2: аритметични операции за умножение и събиране
Rational multiply(Rational const& p, Rational const& q);
Rational add(Rational const& p, Rational const& q);

#endif