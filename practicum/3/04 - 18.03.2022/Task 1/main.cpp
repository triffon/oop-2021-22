#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define EPS 1e-3
#include "doctest.h"

#include "Vector3D.h"
#include <cmath>

TEST_CASE("TEST LENGHT 0") {
    Vector3D v(0, 0, 0);

    CHECK_LT(v.getLenght() - 0, EPS);
}

TEST_CASE("TEST LENGHT 1") {
    Vector3D v(1, 0, 0);

    CHECK_LT(v.getLenght() - 1, EPS);
}

TEST_CASE("TEST LENGHT 2") {
    Vector3D v(1, 1, 0);

    CHECK_LT(v.getLenght() - sqrt(2), EPS);
}

TEST_CASE("TEST LENGHT 3") {
    Vector3D v(1, 1, 1);

    CHECK_LT(v.getLenght() - sqrt(3), EPS);
}

TEST_CASE("TEST LENGHT 4") {
    Vector3D v(7, 12, 5);

    CHECK_LT(v.getLenght() - sqrt(49 + 144 + 25), EPS);
}

////////////////////////////////////////////////////////

TEST_CASE("TEST NORMALIZE") {
    Vector3D v(2, 0, 0);
    v.normalize();

    CHECK_LT(v.getLenght() - 1, EPS);
    CHECK_LT(v.x - 1, EPS);
    CHECK_LT(v.y - 0, EPS);
    CHECK_LT(v.z - 0, EPS);
}

TEST_CASE("TEST NORMALIZE 2") {
    Vector3D v(2, 2, 2);
    v.normalize();

    CHECK_LT(v.getLenght() - 1, EPS);
    CHECK_LT(v.x - 1 / sqrt(3), EPS);
    CHECK_LT(v.y - 1 / sqrt(3), EPS);
    CHECK_LT(v.z - 1 / sqrt(3), EPS);
}

TEST_CASE("TEST NORMALIZE 3") {
    Vector3D v(1, 2, 6);
    v.normalize();

    CHECK_LT(v.getLenght() - 1, EPS);
    CHECK_LT(v.x - 1 / sqrt(41), EPS);
    CHECK_LT(v.y - 2 / sqrt(41), EPS);
    CHECK_LT(v.z - 6 / sqrt(41), EPS);
}

////////////////////////////////////////////////////////

TEST_CASE("TEST SUM 1") {
    Vector3D v1(0.2, 0.3, 0.4);
    Vector3D v2(1.4, 0.5, 3.2);
    Vector3D result = sum(v1, v2);

    CHECK_LT(abs(result.x - 1.6), EPS);
    CHECK_LT(abs(result.y - 0.8), EPS);
    CHECK_LT(abs(result.z - 3.6), EPS);
}

TEST_CASE("TEST SUM 2") {
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    Vector3D result = sum(v1, v2);

    CHECK_LT(abs(result.x - 5), EPS);
    CHECK_LT(abs(result.y - 7), EPS);
    CHECK_LT(abs(result.z - 9), EPS);
}

////////////////////////////////////////////////////////

TEST_CASE("TEST PRODUCT WITH SCALAR 1") {
    Vector3D v(2, 3, 4);
    double mult = 3;
    Vector3D prod = product(v, mult);

    CHECK_LT(abs(prod.x - 6), EPS);
    CHECK_LT(abs(prod.y - 9), EPS);
    CHECK_LT(abs(prod.z - 12), EPS);
}
TEST_CASE("TEST PRODUCT WITH SCALAR 2") {
    Vector3D v(0, 0, 0);
    double mult = 3;
    Vector3D prod = product(v, mult);

    CHECK_LT(abs(prod.x - 0), EPS);
    CHECK_LT(abs(prod.y - 0), EPS);
    CHECK_LT(abs(prod.z - 0), EPS);
}

TEST_CASE("TEST PRODUCT WITH SCALAR 3") {
    Vector3D v(2.2, 1.2, 2.1);
    double mult = 3;
    Vector3D prod = product(v, mult);

    CHECK_LT(abs(prod.x - 6.6), EPS);
    CHECK_LT(abs(prod.y - 3.6), EPS);
    CHECK_LT(abs(prod.z - 6.3), EPS);
}

////////////////////////////////////////////////////////

TEST_CASE("TEST DIFFERENCE") {
    Vector3D v1(8.2, 10.2, 20.1);
    Vector3D v2(4.1, 4.2, 10.0);
    Vector3D difference = diff(v1, v2);

    CHECK_LT(abs(difference.x - 4.1), EPS);
    CHECK_LT(abs(difference.y - 6.0), EPS);
    CHECK_LT(abs(difference.z - 10.1), EPS);
}

TEST_CASE("TEST DIFFERENCE 2") {
    Vector3D v1(28.2, 5.2, 3.1);
    Vector3D v2(24.1, 1.0, 3.0);
    Vector3D difference = diff(v1, v2);

    CHECK_LT(abs(difference.x - 4.1), EPS);
    CHECK_LT(abs(difference.y - 4.2), EPS);
    CHECK_LT(abs(difference.z - 0.1), EPS);
}

////////////////////////////////////////////////////////

TEST_CASE("TEST SCALAR PRODUCT") {
    Vector3D v1(1, 1, 1);
    Vector3D v2(2, 2, 2);
    double prod = productScalar(v1, v2);

    CHECK_LT(abs(prod - 6), EPS);
}
TEST_CASE("TEST SCALAR PRODUCT 2") {
    Vector3D v1(3.2, 4.5, 2.4);
    Vector3D v2(1.2, 1.0, 1.5);
    double prod = productScalar(v1, v2);

    CHECK_LT(abs(prod - 11.94), EPS);
}

////////////////////////////////////////////////////////

TEST_CASE("TEST VECTOR PRODUCT") {
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 7);
    Vector3D prod = productVector(v1, v2);
    
    CHECK_LT(abs(prod.x + 1), EPS);
    CHECK_LT(abs(prod.y - 5), EPS);
    CHECK_LT(abs(prod.z + 3), EPS);
}

TEST_CASE("TEST VECTOR PRODUCT 1") {
    Vector3D v1(1, 0, 0);
    Vector3D v2(0, 1, 0);
    Vector3D prod = productVector(v1, v2);
    
    CHECK_LT(abs(prod.x), EPS);
    CHECK_LT(abs(prod.y), EPS);
    CHECK_LT(abs(prod.z - 1), EPS);
}

TEST_CASE("TEST VECTOR PRODUCT 2") {
    Vector3D v1(1, 0, 0);
    Vector3D v2(0, 1, 0);
    Vector3D prod = productVector(v2, v1);
    
    CHECK_LT(abs(prod.x), EPS);
    CHECK_LT(abs(prod.y), EPS);
    CHECK_LT(abs(prod.z + 1), EPS);
}

TEST_CASE("TEST VECTOR PRODUCT 3") {
    Vector3D v1(4, 8, 7);
    Vector3D v2(10, 42, 33);
    Vector3D prod = productVector(v1, v2);

    CHECK_LT(abs(prod.x + 30), EPS);
    CHECK_LT(abs(prod.y + 62), EPS);
    CHECK_LT(abs(prod.z - 88), EPS);
}