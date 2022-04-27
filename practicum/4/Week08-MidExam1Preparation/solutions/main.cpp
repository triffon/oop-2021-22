#include "University.h"

#include <iostream>

int main()
{
    std::ofstream file("temp.txt", std::ios::trunc);

    if (!file.is_open())
    {
        std::cout << "Error!";
        return 1;
    }

    University u;

    Student p("Pesho", 82214, 4, 6.00);
    Student l("Lubo", 82197, 4, 6.00);
    
    u += p;
    u += l;

    file << u;

    file.close();

    return 0;
}