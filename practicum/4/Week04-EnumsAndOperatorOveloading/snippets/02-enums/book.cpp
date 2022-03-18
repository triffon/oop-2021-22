#include "book.h"
#include <cstring>
#include <cassert>
#include <iostream>

Book::Book()
{
    strcpy(this->name, "");
    this->yearOfPublication = 0;
}

Book::Book(const char* name, const int yearOfPublication, BookType type)
{
    assert(name != nullptr);

    strcpy(this->name, name);
    this->yearOfPublication = yearOfPublication;
    this->type = type;
}

const char* Book::getName() const
{
    return this->name;
}

BookType Book::getType() const
{
    return this->type;

}

void Book::setType(BookType type)
{
    this->type = type;
}

void Book::print()
{
    assert(this->name != nullptr);

    std::cout << this->name << ", " << this->yearOfPublication << std::endl;
}