#include "person.h"
#include <cstring>
#include <iostream>

Person::Person(const char* firstName, const char* lastName, const unsigned int age) : age(age)
{
    strcpy(this->firstName, firstName);
    strcpy(this->lastName, lastName);
} 

Person::Person() : Person("", "", 0) {}

std::ostream& operator << (std::ostream& out, const Person& person)
{
    out << person.firstName << " " << person.lastName << ", " << person.age << " years old";

    return out;
}