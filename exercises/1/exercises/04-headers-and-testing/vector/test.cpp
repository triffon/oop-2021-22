#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../../external/doctest.h"

#include "int_vector.hpp"

TEST_CASE("default ctor") {
    IntVector vec;

    CHECK(vec.size() == 0);
    // Testing implementation detail, not cool
    CHECK(vec.capacity() == 0);
    CHECK(vec.data() == nullptr);
}

TEST_CASE("ctor") {
    const size_t capacity{10};

    IntVector vec(capacity);

    CHECK(vec.size() == 0);
    CHECK(vec.capacity() == capacity);
    CHECK(vec.data() != nullptr);
}

// TDD - Test Driven Development

TEST_CASE("front") {
    const int element{10};
    const int wrong_element{42};

    IntVector v;
    v.push_back(element);
    v.push_back(wrong_element);

    SUBCASE("return reference to element") {
        CHECK(v.front() == element);
    }
    
    SUBCASE("mutate element through reference") {
        const int new_element{20};

        v.front() = new_element;

        CHECK(v.front() == new_element);
    }
}

TEST_CASE("back") {
    const int element{10};
    const int wrong_element{42};

    IntVector v;
    v.push_back(wrong_element);
    v.push_back(element);

    SUBCASE("return reference to element") {
        CAPTURE(v.size());
        CAPTURE(v.capacity());
        CHECK(v.back() == element);
    }
    
    SUBCASE("mutate element through reference") {
        const int new_element{20};

        v.back() = new_element;

        CHECK(v.back() == new_element);
    }
}

TEST_CASE("push_back") {
    const size_t initial_capacity{3};
    const size_t wrong_element{17};
    const int new_element{10};

    IntVector v(initial_capacity);
    v.push_back(wrong_element);
    v.push_back(wrong_element);

    const size_t initial_size{v.size()};

    // [17, 17, ?]

    SUBCASE("adds 1 element to the end of the vector") {
        v.push_back(new_element);

        CHECK(v.back() == new_element);
        CHECK(v.size() == initial_size + 1);
    }

    SUBCASE("expands the vector if needed") {
        // 17, 17, ?
        const size_t new_elements{3};

        for (size_t i{0}; i < new_elements; ++i)
        {
            v.push_back(new_element);
        }

        CHECK(v.back() == new_element);
        CHECK(v.capacity() > initial_capacity);
        CHECK(v.size() == initial_size + new_elements);
    }

    SUBCASE("with empty vector") {
        IntVector empty;

        SUBCASE("expands empty vectors") {
            empty.push_back(new_element);
            CHECK(empty.capacity() > 0);
            CHECK(empty.back() == new_element);
            CHECK(empty.size() == 1);
        }
    }
}