#include <iostream>
#include <cstring>

const std::size_t MAX_NAME_SIZE = 50;

// the default access modifier is 'public'
struct PersonAsStruct
{
    int age;
    char name[MAX_NAME_SIZE];
};

// the default access modifier is 'private'
class PersonAsClass
{
public:
    int age;
    char name[MAX_NAME_SIZE];
};

int main ()
{
    PersonAsStruct structPerson;
    structPerson.age = 18;
    strcpy(structPerson.name, "Dani");

    PersonAsClass classPerson;
    // classPerson --> we cannot access anything that is not explicitly set as public

    return 0;
}