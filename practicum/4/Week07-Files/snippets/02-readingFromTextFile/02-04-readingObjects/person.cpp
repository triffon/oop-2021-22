#include "person.h"
#include <cstring>

Person::Person() : age(0)
{
    strcpy(firstName, "");
    strcpy(lastName, "");
} 

std::istream& operator >> (std::istream& in, Person& person)
{
    in >> person.firstName >> person.lastName >> person.age;

    return in;
}

std::ostream& operator << (std::ostream& out, const Person& person)
{
    out << "First name: " << person.firstName << "\n";
    out << "Last name: " << person.lastName << "\n";
    out << "Age: " << person.age << "\n";

    return out;
}