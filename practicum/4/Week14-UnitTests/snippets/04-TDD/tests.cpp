#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "factorielSolver.h"

TEST_CASE("basic")
{
    FactorielSolver solver;

    CHECK(solver.solve(0) == 1);
    CHECK(solver.solve(1) == 1);

    CHECK(solver.solve(3) == 6);
    CHECK(solver.solve(4) == 24);
    CHECK(solver.solve(2) == 2);

    CHECK_THROWS_AS(solver.solve(-5), std::invalid_argument);

    CHECK(solver.solve(20) == 2432902008176640000);
}