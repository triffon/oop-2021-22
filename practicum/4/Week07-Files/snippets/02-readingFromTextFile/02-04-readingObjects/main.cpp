#include <iostream>
#include <fstream>
#include "person.h"

int main ()
{
    std::ifstream people("people.txt"); 

    if (!people.is_open()) // always check if the opening is successfull
    {
        std::cout << "Problem while opening the file" << std::endl;
        return 1;
    }

    // Reading the file line by line

    Person tempPerson;
    while (!people.eof()) // reading until end of file
    {
        people >> tempPerson; // only if operator >> is overloaded
        // !!! ifstream is a istream (will show this again when we talk about inheritance)
        std::cout << tempPerson << std::endl;
    }

    people.close();

    return 0;
}