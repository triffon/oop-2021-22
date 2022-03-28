#include "MyString.h"
#include <exception>

MyString::MyString(const char *str) : mCapacity{strlen(str) + 1}
{
    this->str = new char[mCapacity];
    strncpy(this->str, str, mCapacity);
}

MyString::MyString(const MyString &source) : mCapacity{strlen(source.str) + 1}
{
    str = new char[mCapacity];
    strncpy(str, source.str, mCapacity);
}

MyString &MyString::operator=(const MyString &rhs)
{
    if (this != &rhs)
    {
        delete[] this->str;
        this->mCapacity = strlen(rhs.str) + 1;
        this->str = new char[this->mCapacity];
        strncpy(str, rhs.str, mCapacity);
    }
    return *this;
}

MyString::~MyString()
{
    delete[] str;
}

bool MyString::empty() const
{
    return strlen(this->str) == 0;
}

char &MyString::at(unsigned int pos)
{   if (pos >= mCapacity || pos < 0)
    {
        throw std::exception();
    }
    return str[pos];
}

unsigned int MyString::size() const
{
    return strlen(str);
}

unsigned int MyString::capacity() const
{
    return this->mCapacity;
}

const char *MyString::c_str() const
{
    return this->str;
}

void MyString::resize()
{
    char* temp = new char[mCapacity];
    strncpy(temp, str, mCapacity);
    delete[] str;
    mCapacity *=2;
    str = new char[mCapacity];
    strncpy(str,temp,mCapacity/2);
    delete[] temp;

    // char* temp = new char[mCapacity*2];
    // strncpy(temp, str, mCapacity);
    // delete[] str;
    // str = temp;
    // mCapacity*=2;  VARIANT 2
}

void MyString::push_back(char c)
{
    unsigned int len = strlen(str);
    if (len + 1 >= mCapacity)
    {
        resize();
    }
    str[len] = c;
    str[len + 1] = '\0';
}