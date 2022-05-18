// Exam Problem
// Base 
// Derived1, Derived2, ...
// Container -> std::vector<Base*> / Base**, size, capacity

// Formula = Number | (Formula Op Formula)
// Op = + | - | * | /

// (1 + 2)

// ((1 + 2)*3)
// (1+2) * 3

// evaluate()
// cout << formula

#include <iostream>
#include <cassert>

class Formula
{
 public:
    Formula() = default;
    virtual ~Formula() = default;

    float evaluate() const;
    std::ostream& print(std::ostream&) const;

    virtual Formula * clone() const = 0;
 private:
    virtual float do_evaluate() const = 0;
    virtual std::ostream& do_print(std::ostream&) const = 0;
 protected:
    Formula(const Formula&) = default;
    Formula& operator=(const Formula&) = default;
};

float Formula::evaluate() const
{
    return do_evaluate();
}

std::ostream& Formula::print(std::ostream& out) const
{
    return do_print(out);
}

std::ostream& operator<<(std::ostream& out, const Formula& f)
{
    return f.print(out);
}

class Number : public Formula
{
 public:
    Number(float);
    Number * clone() const final;
 private:
    float m_value{};

    float do_evaluate() const final;
    std::ostream& do_print(std::ostream&) const final;
};

Number::Number(float value):
    m_value{value}
{}

Number * Number::clone() const
{
    return new Number{*this};
}

float Number::do_evaluate() const
{
    return m_value;
}

std::ostream& Number::do_print(std::ostream& out) const
{
    return out << m_value;
}

class Operation: public Formula
{
 public:
    Operation(const Formula*, char, const Formula*);
    ~Operation();

    Operation* clone() const final;
 private:
    // TODO: follow rule of 0
    Formula * m_lhs;
    Formula * m_rhs;
    char m_op;

    float do_evaluate() const final;
    std::ostream& do_print(std::ostream&) const final;
 protected:
    Operation(const Operation&);
    Operation& operator=(const Operation&);
};

Operation* Operation::clone() const
{
    return new Operation{*this};
}

std::ostream& Operation::do_print(std::ostream& out) const
{
    // (1 + 1) -> lhs 1, op +, rhs 1
    out << "(";
    m_lhs->print(out);
    out << m_op;
    m_rhs->print(out);
    out << ")";
    return out;
}

float Operation::do_evaluate() const
{
    float lhs_value{m_lhs->evaluate()};
    float rhs_value{m_rhs->evaluate()};

    switch(m_op)
    {
        case '+':
            return lhs_value + rhs_value;
        case '-':
            return lhs_value - rhs_value;
        case '*':
            return lhs_value * rhs_value;
        case '/':
            assert(rhs_value != 0);
            return lhs_value / rhs_value;
        default:
            assert(false && "Invalid Formula");
    }
}

Operation::Operation(const Formula* lhs, char op, const Formula* rhs):
    m_lhs{lhs->clone()},
    m_rhs{rhs->clone()},
    m_op{op}
{
    assert(op == '+' || op == '-' || op == '*' || op == '/');
}

Operation::~Operation()
{
    delete m_lhs;
    delete m_rhs;
}

Operation::Operation(const Operation& other):
    m_lhs{other.m_lhs->clone()},
    m_rhs{other.m_rhs->clone()},
    m_op{other.m_op}
{}

Operation& Operation::operator=(const Operation& other)
{
    // Copy
    Operation copy{other};
    
    // Swap
    using std::swap;
    swap(m_lhs, copy.m_lhs);
    swap(m_rhs, copy.m_rhs);
    swap(m_op, copy.m_op);

    return *this;
}

// HW: Parser = String -> Formula*
// "(1+2)" -> Operation(Number(1), Number(2), "+")

Operation operator+(const Formula& lhs, const Formula& rhs)
{
    return Operation(&lhs, '+', &rhs);
}

Operation operator*(const Formula& lhs, const Formula& rhs)
{
    return Operation(&lhs, '*', &rhs);
}

int main()
{
    Number n1{10};
    Number n2{2};

    Operation op{&n1, '-', &n2};

    Operation op2{&op, '*', &op};

    std::cout << op2;

    std::cout << " = " << op2.evaluate();

    std::cout << std::endl;

    std::cout << "===========================\n";

    Operation op3{op2 * op2};

    std::cout << op3 << " = " << op3.evaluate() << std::endl;

    return 0;
}