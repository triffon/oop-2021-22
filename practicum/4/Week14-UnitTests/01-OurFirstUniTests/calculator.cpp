#include "calculator.h"
#include <stdexcept>

double Calculator::sum(double first, double second)
{
    return first + second;
}
    
double Calculator::diff(double first, double second)
{
    return first - second;
}

double Calculator::divide(double first, double second)
{
    if (second == 0)
    {
        throw std::invalid_argument("cannot divide by 0");
    }
    return first / second;
}

double Calculator::multiply(double first, double second)
{
    return first * second;
}