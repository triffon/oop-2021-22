#include "book.h"
#include <cstring>
#include <cassert>
#include <iostream>

Book::Book()
{
    strcpy(this->name, "");
    this->yearOfPublication = 0;
}

Book::Book(const char* name, const int yearOfPublication)
{
    assert(name != nullptr);

    strcpy(this->name, name);
    this->yearOfPublication = yearOfPublication;
}

const char* Book::getName()
{
    return this->name;
}

void Book::print()
{
    assert(this->name != nullptr);

    std::cout << this->name << ", " << this->yearOfPublication << std::endl;
}