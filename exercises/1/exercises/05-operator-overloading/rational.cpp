#include "rational.hpp"
#include <cassert>
#include <utility>

int gcd(int a, int b)
{
    while (a != 0 && b != 0)
    {
        std::swap(a, b);
        b = b % a;
    }

    return a != 0 ? a : b;
}

rational::rational(int nom, int denom):
    m_nom{nom},
    m_denom{denom}
{
    normalize();
}

void rational::normalize()
{
    assert(m_denom != 0);

    int divisor{gcd(m_nom, m_denom)};
    m_nom = m_nom / divisor;
    m_denom = m_denom / divisor;
}

int rational::nom() const
{
    return m_nom;
}

int rational::denom() const
{
    return m_denom;
}

rational operator+(const rational& lhs, const rational& rhs)
{
    return rational{
        lhs.nom() * rhs.denom() + rhs.nom() * lhs.denom(),
        lhs.denom() * rhs.denom()
    };
}

rational operator+(const rational& lhs, int rhs)
{
    return lhs + rational(rhs);
}

rational operator+(int lhs, const rational& rhs)
{
    return rhs + lhs;
}

rational operator*(const rational& lhs, const rational& rhs)
{
    return rational{
        lhs.nom() * rhs.nom(),
        lhs.denom() * rhs.denom()
    };
}

rational operator*(const rational& lhs, int rhs)
{
    return lhs * rational(rhs);
}

rational operator*(int lhs, const rational& rhs)
{
    return rhs * lhs;
}

bool operator==(const rational& lhs, const rational& rhs)
{
    return lhs.nom() == rhs.nom() && lhs.denom() == rhs.denom();
}

bool operator<(const rational& lhs, const rational& rhs)
{
    return lhs.nom() * rhs.denom() < rhs.nom() * lhs.denom();
}

bool operator!=(const rational& lhs, const rational& rhs)
{
    return !(lhs == rhs);
}

bool operator<=(const rational& lhs, const rational& rhs)
{
    return lhs == rhs || lhs < rhs;
}

bool operator>(const rational& lhs, const rational& rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const rational& lhs, const rational& rhs)
{
    return !(lhs < rhs);
}

rational operator-(const rational& self)
{
    return rational{
        -self.nom(),
        self.denom()
    };
}

rational& rational::operator+=(const rational& other)
{
    return *this = *this + other;
}

rational& rational::operator+=(int other)
{
    return *this = *this + other;
}

rational& rational::operator++()
{
    return *this += 1;
}

rational rational::operator++(int)
{
    rational copy{*this};
    ++*this;
    return copy;
}

rational::operator bool() const
{
    return m_nom != 0;
}

rational::operator double() const
{
    return static_cast<double>(m_nom) / m_denom;
}

std::ostream& operator<<(std::ostream& out, const rational& number)
{
    return out << number.nom()
               << "/"
               << number.denom();
}

std::istream& operator>>(std::istream& in, rational& number)
{
    in >> number.m_nom >> number.m_denom;
    number.normalize();
    return in;
}
