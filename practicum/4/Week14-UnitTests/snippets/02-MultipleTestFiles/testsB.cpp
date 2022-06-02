//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "classB.h"

TEST_CASE("test class B")
{
    B b;

    REQUIRE(b.f() == 7);
    REQUIRE(b.g() == 'L');
}