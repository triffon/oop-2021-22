#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "calculator.h"

TEST_CASE("test addition")
{
    Calculator calculator;

    REQUIRE(calculator.sum(5, 6) == 11);
    REQUIRE_EQ(calculator.sum(4, 8), 12);
}

TEST_CASE("test multiplication")
{
    Calculator calculator;

    //CHECK(calculator.multiply(2.356, 3.876) == 9.131856);
    REQUIRE(calculator.multiply(2.356, 3.876) == doctest::Approx(9.131856));
}

TEST_CASE("test division")
{
    Calculator calculator;

    REQUIRE(calculator.divide(5,2) == doctest::Approx(2.5));
    REQUIRE_THROWS(calculator.divide(10, 0));
    REQUIRE_THROWS_AS(calculator.divide(15, 0), std::invalid_argument);
    REQUIRE_NOTHROW(calculator.divide(5,2));
}