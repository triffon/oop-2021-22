#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "classA.h"

TEST_CASE("test class A")
{
    A a;

    REQUIRE(a.f() == 5);
    REQUIRE(a.g() == 'P');
}