#pragma once
#include <cstring>
#include <iostream>
#include <fstream>
class MyString
{
private:
    char *mStr;
    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
    friend std::istream& operator>>(std::istream& is, MyString& obj);
public:
    const char* c_str() const;

    MyString(const char *str = "\0");
    MyString(const MyString &source);
    MyString &operator=(const MyString &rhs);
    MyString(MyString &&source);
    MyString &operator=(MyString &&rhs);
    ~MyString();
};


std::ostream &operator<<(std::ostream &os, const MyString &obj)
{
    size_t len = strlen(obj.mStr)+1;
    os.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
    os.write(obj.mStr, len);
    return os;
}


std::istream &operator>>(std::istream &is, MyString &obj)
{
    delete[] obj.mStr;
    size_t len = 0;
    is.read(reinterpret_cast<char*>(&len), sizeof(size_t));
    obj.mStr = new char[len];
    is.read(obj.mStr, len);
    return is;
}