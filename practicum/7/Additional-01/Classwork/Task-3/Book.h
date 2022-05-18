#pragma once
#include "MyString.cpp"

class Book
{
private:
    MyString name;
    MyString author;
    unsigned yearOfRelease;
    unsigned price;

    friend std::ostream& operator<<(std::ostream& os, const Book& obj);
    friend std::istream& operator>>(std::istream& is, Book& obj);

public:
    Book(const char* name, const char* author, unsigned year, unsigned price);
    //getters&&setters
    unsigned getPrice() const{
        return price;
    }
    void printBook() const;
};

Book::Book(const char *name, const char *author, unsigned year, unsigned price)
    : name(name), author(author), yearOfRelease(year), price(price)
{
}

void Book::printBook() const
{
    std::cout << name.c_str() << ' ' << author.c_str() << ' ' << yearOfRelease << ' ' << price << '\n';
}

std::ostream &operator<<(std::ostream &os, const Book &obj)
{
    os << obj.name << obj.author;
    os.write(reinterpret_cast<const char*>(&obj.yearOfRelease), sizeof(unsigned));
    os.write(reinterpret_cast<const char*>(&obj.price), sizeof(unsigned));
    return os;
}

std::istream &operator>>(std::istream &is, Book &obj)
{
    is >> obj.name >> obj.author;
    is.read(reinterpret_cast<char*>(&obj.yearOfRelease), sizeof(unsigned));
    is.read(reinterpret_cast<char*>(&obj.price), sizeof(unsigned));
    return is;
}