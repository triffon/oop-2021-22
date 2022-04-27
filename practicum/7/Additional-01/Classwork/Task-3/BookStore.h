#pragma once
#include "Book.h"
#include "Utils.h"

class BookStore
{
private:
    MyString name;
    Book* books;
    int booksCount;
public:
    BookStore();

    unsigned sumOfBooksPrice() const;
    bool operator<(const BookStore& rhs) const;
    void sort();
    ~BookStore();
};

BookStore::BookStore() : name("DefaultName"), books(nullptr), booksCount(0)
{
}

bool BookStore::operator<(const BookStore &rhs) const
{
    return this->sumOfBooksPrice() < rhs.sumOfBooksPrice();
}

unsigned int BookStore::sumOfBooksPrice() const
{
    unsigned sum = 0;
    for (int i = 0; i < booksCount; i++)
    {
        sum += books[i].getPrice();
    }
    return sum;
}

void BookStore::sort()
{
    mergeSort(books,0, booksCount-1);
}

BookStore::~BookStore()
{
    delete[] books;
}
