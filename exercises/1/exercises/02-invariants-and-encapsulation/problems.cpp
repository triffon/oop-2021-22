#include <iostream>
#include <cassert>
#include <cmath>

// struct

struct point2d
{
    double x;
    double y;
};

// pod - plain old data

struct triangle_alpha
{
    double a;
    double b;
    double c;

    // a + b > c
    // b + c > a
    // a + c > b
    // a > 0 
    // b > 0
    // c > 0
};

// invariant

// class

// encapsulation

// public
// private

struct triangle_beta
{
        int something_public{17};
    private:
        double a{};
        double b{};
        double c{};
    public:
        int other_public{3};
};

// class

class triangle
{
    public:
        // constructor, ctor
        triangle() = default;

        triangle(double a, double b, double c);
        // accessor, selector, getter
        double a() const;
        double b() const;
        double c() const;

        // setter, mutator, mutater
        void set_a(double a);
        void set_b(double b);
        void set_c(double c);

        double perimeter() const;
        double semiperimeter() const;
        double area() const;
    private:
        double m_a{1};
        double m_b{1};
        double m_c{1};

        bool valid() const;
};

int main()
{   
    triangle t{3,4,5};
    std::cout << t.area() << std::endl;
    return 0;
}

double triangle::a() const
{
    return m_a;
}

bool triangle::valid() const
{
    return m_a > 0 && m_b > 0 && m_c > 0 &&
            m_a + m_b > m_c &&
            m_a + m_c > m_b &&
            m_b + m_c > m_a;
}

triangle::triangle(double a, double b, double c):
    m_a{a},
    m_b{b},
    m_c{c}
{
    assert(valid());
}

double triangle::b() const
{
    return m_b;
}

double triangle::c() const
{
    return m_c;
}

// setter, mutator, mutater
void triangle::set_a(double a)
{
    m_a = a;
    assert(valid());
}

void triangle::set_b(double b)
{
    m_b = b;
    assert(valid());
}

void triangle::set_c(double c)
{
    m_c = c;
    assert(valid());
}

double triangle::perimeter() const
{
    return m_a + m_b + m_c;
}

double triangle::semiperimeter() const
{
    return perimeter() / 2;
}

double triangle::area() const
{
    double p = semiperimeter();
    return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
}