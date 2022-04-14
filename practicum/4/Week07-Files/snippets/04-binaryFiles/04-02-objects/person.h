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
    Person(const char* firstName, const char* lastName, const unsigned int age);

    friend std::ostream& operator << (std::ostream& out, const Person& person);
};