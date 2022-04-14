#pragma once

#include <cstddef>
#include <fstream>

const std::size_t MAX_NAME_SIZE = 50;

class Person
{
private:
    char firstName[MAX_NAME_SIZE];
    char lastName[MAX_NAME_SIZE];
    unsigned int age;

public:
    Person();

    friend std::istream& operator >> (std::istream& in, Person& person);
    friend std::ostream& operator << (std::ostream& out, const Person& person);
};