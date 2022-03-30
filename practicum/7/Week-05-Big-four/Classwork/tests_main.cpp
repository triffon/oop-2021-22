#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyString.cpp"

TEST_CASE("Default ctor"){
    MyString m;
    
    CHECK(m.empty() == true);
}

TEST_CASE("Ctor w/ param") {
    const char* str = "Hello!";
    MyString m(str);

    CHECK(strcmp(str, m.c_str()) == 0);
}

TEST_CASE("Copy ctor"){
    const char* str = "Hello!";
    MyString m(str);

    REQUIRE(strcmp(str, m.c_str()) == 0);

    MyString m1(m);

    CHECK(strcmp(m.c_str(), m1.c_str()) == 0);
}

TEST_CASE("Operator="){
    MyString m("zdr");
    MyString m1("ko pr");

    m1 = m;
    CHECK(strcmp(m.c_str(), m1.c_str()) == 0);
}

TEST_CASE("Empty works correctly"){
    MyString m;
    MyString m1("zdr");

    CHECK(m.empty());
    CHECK(!m1.empty());
}

TEST_CASE("at"){
    MyString m;
    MyString m1("zdr");

    CHECK_THROWS(m.at(1));
    CHECK(m.at(0) == '\0');
    //CHECK_THROWS(m1.at(1) == 'd');
    //CHECK_THROWS(m1.at(5));
}

TEST_CASE("Size & capacity correctly for empty and normal MyString"){
    MyString m;
    MyString m1("zdr");
    MyString m2;

    CHECK(m.size() == 0);
    CHECK(m1.size() == 3);
    CHECK(m.size() == m2.size());
    CHECK(m.capacity() == m2.capacity());
}

TEST_CASE("c_str"){
    const char* str = "zdr";
    MyString m;
    MyString m1(str);

    CHECK(strcmp(m.c_str(),"\0") == 0);
    CHECK(strcmp(m1.c_str(), str) == 0);
}

TEST_CASE("push_back"){
    MyString m;
    MyString m1("zdr");

    m.push_back('c');
    m1.push_back('e');

    CHECK(strcmp(m.c_str(), "c") == 0);
    CHECK(strcmp(m1.c_str(), "zdre") == 0);
}
