#include <iostream>
#include <cstring>
#include <cassert>
#include "myString.h"

MyString::MyString()
{
    this->string = nullptr;
    this->size = 0;
}

MyString::MyString(const char* string)
{
    if (string)
    {
        std::size_t size = strlen(string);

        this->string = new char[size + 1];
        
        strcpy(this->string, string);
        this->size = size;
    }
    else
    {
        this->string = nullptr;
        this->size = 0;
    }
}

void MyString::copy(const MyString& other)
{
    if (other.string)
    {
        char* buffer = nullptr;

        try
        {
            buffer = new char[other.size + 1];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return;
        }

        strcpy(buffer, other.string);
        
        this->string = buffer;
        this->size = other.size;
    }
    else
    {
        this->string = nullptr;
        this->size = 0;
    }
}

void MyString::deallocate()
{
    if (this->string)
    {
        delete[] this->string;
    }
}

void MyString::clear()
{
    this->deallocate();

    this->string = nullptr;
    this->size = 0;
}

MyString::MyString(const MyString& other)
{
    this->copy(other);
}

MyString& MyString::operator = (const MyString& other)
{
    if (this != &other)
    {
        this->clear();
        this->copy(other);
    }

    return *this;
}

MyString::~MyString()
{
    this->clear();
}

char& MyString::at(std::size_t pos)
{
    if (pos >= this->size)
    {
        throw std::out_of_range("Invalid index");
    }

    return this->string[pos];
}

const char& MyString::at(std::size_t pos) const
{
    if (pos >= this->size)
    {
        throw std::out_of_range("Invalid index");
    }

    return this->string[pos];
}

char& MyString::operator [] (std::size_t pos)
{
    assert(pos < this->size);

    return this->string[pos];
}

const char& MyString::operator [] (std::size_t pos) const
{
    assert(pos < this->size);

    return this->string[pos];
}

char& MyString::front()
{
    assert(!this->empty());

    return this->string[0];
}

const char& MyString::front() const
{
    assert(!this->empty());

    return this->string[0];
}

char& MyString::back()
{
    assert(!this->empty());

    return this->string[this->size - 1];
}

const char& MyString::back() const
{
    assert(!this->empty());

    return this->string[this->size - 1];
}

bool MyString::empty() const
{
    return this->size == 0;
}

std::size_t MyString::getSize() const
{
    return this->size;
}

void MyString::push_back(char c)
{
    if (c == '\0')
    {
        return;
    }

    std::size_t newSize = this->size + 1;
    char* newString = nullptr;
    
    try
    {
        newString = new char[newSize + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    if (!this->empty())
    {
        strcpy(newString, this->string);
    }
    newString[this->size] = c;
    newString[newSize] = '\0';

    this->clear();
    this->string = newString;
    this->size = newSize;
}

void MyString::pop_back()
{
    assert(this->size != 0);

    if (this->size == 1)
    {
        this->clear();
        return;
    }

    this->string[this->size - 1] = '\0';
    --this->size;
}

MyString& MyString::operator += (char c)
{
    this->push_back(c);

    return *this;
}

MyString& MyString::operator += (const MyString& rhs)
{
    if (!this->string)
    {
        *this = rhs;
        return *this;
    }

    if (rhs.string)
    {
        std::size_t newSize = this->size + rhs.size;
        char* newString = nullptr;

        try
        {
            newString = new char[newSize + 1];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return *this;
        }

        strcpy(newString, this->string);
        strcat(newString, rhs.string);
        newString[newSize] = '\0';

        this->clear();
        this->string = newString;
        this->size = newSize;
    }

    return *this;
}

MyString MyString::operator + (char c) const
{
    MyString result = *this;
    result += c;

    return result;
}

MyString MyString::operator + (const MyString& rhs) const
{
    MyString result = *this;
    result += rhs;

    return result;
}

const char* MyString::c_str() const
{
    return this->string;
}

bool MyString::operator == (const MyString &rhs) const
{
    if (this->size != rhs.size)
    {
        return false;
    }

    if (this->empty())
    {
        return true;
    }

    return strcmp(this->string, rhs.string) == 0;
}

bool MyString::operator < (const MyString &rhs) const
{
    if (this->empty())
    {
        return true;
    }

    if (rhs.empty())
    {
        return false;
    }

    return strcmp(this->string, rhs.string) < 0;
}

std::ostream& operator << (std::ostream& out, const MyString& string)
{
    for (std::size_t i = 0; i < string.size; ++i)
    {
        out << string.string[i];
    }

    return out;
}