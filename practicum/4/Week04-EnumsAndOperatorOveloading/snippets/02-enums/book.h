#pragma once

#include <cstddef>
#include "bookType.h"

const std::size_t MAX_BOOK_NAME_SIZE = 100;

class Book
{
private:
    char name[MAX_BOOK_NAME_SIZE];
    int yearOfPublication;
    BookType type;

public:
    Book();
    Book(const char* name, const int yearOfPublication, BookType type);

    const char* getName() const;
    BookType getType() const;

    void setType(BookType type);

    void print();
};