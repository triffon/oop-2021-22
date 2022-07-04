#include "factorielSolver.h"
#include <stdexcept>

long long FactorielSolver::solve(long long n)
{
    if (n < 0)
    {
        throw std::invalid_argument("not defined for negative numbers");
    }

    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * solve(n - 1);
}