#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "list.h"

TEST_CASE("Test default constructor")
{
    List<int> intList;

    REQUIRE(intList.isEmpty());
    REQUIRE(intList.getSize() == 0);
    REQUIRE(intList.getCapacity() == 2);
}

TEST_CASE("Test add")
{
    List<int> intList;
    intList.add(5);

    REQUIRE_FALSE(intList.isEmpty());
    REQUIRE(intList.getSize() == 1);
    REQUIRE(intList.getCapacity() == 2);
}

TEST_CASE("Test resize")
{
    List<int> intList;
    intList.add(5);
    intList.add(6);
    intList.add(7);
    
    REQUIRE_FALSE(intList.isEmpty());
    REQUIRE(intList.getSize() == 3);
    REQUIRE(intList.getCapacity() == 4);

    intList.add(8);
    intList.add(9);

    REQUIRE(intList.getSize() == 5);
    REQUIRE(intList.getCapacity() == 8);
}

TEST_CASE("Test uniqueness")
{
    List<int> intList;
    intList.add(5);
    intList.add(5);
    intList.add(5);
    
    REQUIRE_FALSE(intList.isEmpty());
    REQUIRE(intList.getSize() == 1);
    REQUIRE(intList.getCapacity() == 2);
}

TEST_CASE("Test copy constructor")
{
    List<int> intList;
    intList.add(5);
    intList.add(6);
    intList.add(7);

    REQUIRE_FALSE(intList.isEmpty());
    REQUIRE(intList.getSize() == 3);
    REQUIRE(intList.getCapacity() == 4);

    List<int> copy(intList);
    copy.add(8);
    copy.add(9);

    REQUIRE(intList.getSize() == 3);
    REQUIRE(intList.getCapacity() == 4);
    REQUIRE(copy.getSize() == 5);
    REQUIRE(copy.getCapacity() == 8);
}

TEST_CASE("Test operator =")
{
    List<int> intList;
    intList.add(5);
    intList.add(6);
    intList.add(7);

    REQUIRE_FALSE(intList.isEmpty());
    REQUIRE(intList.getSize() == 3);
    REQUIRE(intList.getCapacity() == 4);

    List<int> copy;
    copy.add(1);
    
    copy = intList;
    copy.add(8);
    copy.add(9);

    REQUIRE(intList.getSize() == 3);
    REQUIRE(intList.getCapacity() == 4);
    REQUIRE(copy.getSize() == 5);
    REQUIRE(copy.getCapacity() == 8);
}

TEST_CASE("Test removeAt")
{
    List<int> intList;

    intList.add(5);
    intList.add(6);
    intList.add(7);
    intList.add(8);

    REQUIRE(intList.getSize() == 4);

    intList.removeAt(3);

    REQUIRE(intList.getSize() == 3);

    REQUIRE_THROWS_AS(intList.removeAt(3), std::invalid_argument);
}

TEST_CASE("Test operator []")
{
    List<int> intList;

    intList.add(5);
    intList.add(6);
    intList.add(7);
    intList.add(8);  

    REQUIRE(intList[0] == 5);
    REQUIRE(intList[1] == 6);
    REQUIRE(intList[2] == 7);
    REQUIRE(intList[3] == 8);

    REQUIRE_THROWS_AS(intList[4], std::invalid_argument); 
}