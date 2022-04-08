#include <iostream>
#include <fstream>
#include "person.h"

int main ()
{
    Person person1("Peter", "Kolev", 20), 
           person2("Mirela", "Nikolova", 17),
           person3("Borislav", "Draganov", 45);

    std::ofstream peopleOut("people.bin", std::ios::binary);

    if (!peopleOut.is_open())
    {
        std::cout << "Problem while opening the file" << std::endl;
        return 1;
    }

    peopleOut.seekp(0);

    std::cout << sizeof(Person) << std::endl;

    // writing three people to a binary file, note the parameter of the 'sizeof' function
    peopleOut.write(reinterpret_cast<const char*>(&person1), sizeof(Person));
    peopleOut.write(reinterpret_cast<const char*>(&person2), sizeof(Person));
    peopleOut.write(reinterpret_cast<const char*>(&person3), sizeof(Person));

    peopleOut.close();


    Person temp;

    std::ifstream peopleIn("people.bin", std::ios::binary);

    if (!peopleIn.is_open())
    {
        std::cout << "Problem while opening the file" << std::endl;
        return 1;
    }

    peopleIn.seekg(0);
    // reading the first person
    peopleIn.read(reinterpret_cast<char*>(&temp), sizeof(Person));

    std::cout << temp << std::endl;

    peopleIn.seekg(2 * sizeof(Person), std::ios::beg);
    // moving the 'get' pointer 2 times the size of the Person class after the beginning of the file
    // which means we will print the third one
    peopleIn.read(reinterpret_cast<char*>(&temp), sizeof(Person));

    std::cout << temp << std::endl;

    peopleIn.close();

    return 0;
}