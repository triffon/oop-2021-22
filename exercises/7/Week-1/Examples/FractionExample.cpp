/*
    Problem: Write a C++ struct that represents a fraction. Provide capabilities
             for addition, substraction, division and multiplication.
*/

#include <iostream>
#include <math.h>

using namespace std;

struct Fraction
{
    int numerator;
    int denominator;

    static int gcd(int a, int b)
    {
        if (a == b)
        {
            return a;
        }

        return a > b ? gcd(a - b, b) : gcd(a, b - a);
    }

    Fraction reduce()
    {
        int divisor = gcd(abs(this->numerator), abs(this->denominator));

        this->numerator /= divisor;
        this->denominator /= divisor;

        return *this;
    }

    Fraction add(Fraction other)
    {
        Fraction result;

        result.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
        result.denominator = this->denominator * other.denominator;

        return result.reduce();
    }

    Fraction substract(Fraction other)
    {
        Fraction result;

        result.numerator = this->numerator * other.denominator - other.numerator * this->denominator;
        result.denominator = this->denominator * other.denominator;

        return result.reduce();
    }

    Fraction divide(Fraction other)
    {
        Fraction result;

        result.numerator = this->numerator * other.denominator;
        result.denominator = this->denominator * other.numerator;

        return result.reduce();
    }

    Fraction multiply(Fraction other)
    {
        Fraction result;

        result.numerator = this->numerator * other.numerator;
        result.denominator = this->denominator * other.denominator;

        return result.reduce();
    }
};

int main()
{
    Fraction a{1, 2}, b{3, 4};

    Fraction c = a.add(b);
    Fraction d = a.substract(b);
    Fraction e = a.divide(b);
    Fraction f = a.multiply(b);

    cout << a.numerator << "/" << a.denominator << " + " << b.numerator << "/" << b.denominator << " = " << c.numerator << "/" << c.denominator << endl;
    cout << a.numerator << "/" << a.denominator << " - " << b.numerator << "/" << b.denominator << " = " << d.numerator << "/" << d.denominator << endl;
    cout << a.numerator << "/" << a.denominator << " / " << b.numerator << "/" << b.denominator << " = " << e.numerator << "/" << e.denominator << endl;
    cout << a.numerator << "/" << a.denominator << " * " << b.numerator << "/" << b.denominator << " = " << f.numerator << "/" << f.denominator << endl;

    return 0;
}
