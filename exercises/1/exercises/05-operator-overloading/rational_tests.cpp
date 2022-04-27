#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../external/doctest.h"

#include "rational.hpp"

TEST_CASE("gcd") {
    CHECK(gcd(15, 20) == 5);
    CHECK(gcd(10, 10) == 10);
    CHECK(gcd(24, 1) == 1);
    CHECK(gcd(0, 20) == 20);
}

TEST_CASE("ctor") {
    rational number;

    CHECK(number.nom() == 0);
    CHECK(number.denom() == 1);

    number = rational{10};

    CHECK(number.nom() == 10);
    CHECK(number.denom() == 1);

    number = rational{1,2};

    CHECK(number.nom() == 1);
    CHECK(number.denom() == 2);

    number = rational{2, 4};

    CHECK(number.nom() == 1);
    CHECK(number.denom() == 2);
}

TEST_CASE("adding rationals") {
    rational lhs{1,2};
    rational rhs{1,2};

    rational result{lhs + rhs};
    rational expected{1};

    CHECK(result == expected);
}

TEST_CASE("adding with ints") {
    rational rat{1,2};
    int integer{1};

    rational result{rat + integer};
    rational expected{3,2};

    CHECK(result == expected);

    result = integer + rat;

    CHECK(result == expected);
}

TEST_CASE("multiplication") {
    rational lhs{1,2};
    rational rhs{2,3};

    rational result{lhs * rhs};
    rational expected{1, 3};
    
    CHECK(result == expected);
}

TEST_CASE("multiplying with ints") {
    rational rat{1,2};
    int integer{2};

    rational result{rat * integer};
    rational expected{1};

    CHECK(result == expected);

    result = integer * rat;

    CHECK(result == expected);
}

TEST_CASE("comparison") {
    rational lhs{1,3};
    rational rhs{2,3};

    CHECK(lhs < rhs);
    CHECK(rhs > lhs);
    CHECK(lhs <= lhs);
    CHECK(rhs >= lhs);
    CHECK(lhs != rhs);

    rhs = rational{1,2};

    CHECK(lhs < rhs);
    CHECK(rhs > lhs);
    CHECK(lhs <= lhs);
    CHECK(rhs >= lhs);
    CHECK(lhs != rhs);

    rhs = lhs;

    CHECK(lhs == rhs);
    CHECK(!(lhs != rhs));
    CHECK(lhs <= rhs);
    CHECK(rhs <= lhs);
    CHECK(rhs >= lhs);
    CHECK(lhs >= rhs);
}

TEST_CASE("unary minus") {
    rational rat{1,2};

    CHECK(-rat == rational{-1, 2});

    CHECK(-rational() == rational());
}

TEST_CASE("infix ++") {
    rational rat{1,2};

    rational result{3,2};

    CHECK(++rat == result);
}

TEST_CASE("postfix ++") {
    rational rat{1,2};
    rational old{rat};

    rational result{3,2};

    CHECK(rat++ == old);
    CHECK(rat == result);
}

TEST_CASE("casting to bool") {
    CHECK(static_cast<bool>(rational{1,2}) == true);

    CHECK(static_cast<bool>(rational{0, 1}) == false);
}

// TODO: Fix double comparisions
TEST_CASE("casting to bool") {
    CHECK(static_cast<double>(rational{0,1}) == 0);
    CHECK(static_cast<double>(rational{1,2}) == 0.5);
}
