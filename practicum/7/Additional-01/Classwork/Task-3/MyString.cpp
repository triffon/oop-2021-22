#include "MyString.h"

MyString::MyString(const char *str) : mStr(new char[strlen(str) + 1])
{
    strncpy(mStr, str, strlen(str) + 1);
}

MyString::MyString(const MyString &source)
{
    size_t len = strlen(source.mStr) + 1;
    mStr = new char[len];
    strncpy(mStr, source.mStr, len);
}

MyString &MyString::operator=(const MyString &rhs)
{
    if (this != &rhs)
    {
        delete[] mStr;
        size_t len = strlen(rhs.mStr) + 1;
        mStr = new char[len];
        strncpy(mStr, rhs.mStr, len);
    }
    return *this;
}

MyString::MyString(MyString &&source) : mStr(source.mStr)
{
    source.mStr = nullptr;
}

MyString &MyString::operator=(MyString &&rhs)
{
    if (this != &rhs)
    {
        delete[] mStr;
        mStr = rhs.mStr;
        rhs.mStr = nullptr;
    }
    return *this;
}

MyString::~MyString()
{
    delete[] mStr;
}


const char *MyString::c_str() const
{
    return mStr;
}