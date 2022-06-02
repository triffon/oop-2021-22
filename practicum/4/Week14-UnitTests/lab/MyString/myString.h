#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
class MyString
{
private:
    char* string;
    std::size_t size;

    void copy(const MyString& other);
    void deallocate();
    void resize();

public:
    MyString();
    MyString(const char* string);
    MyString(const MyString& other);
    MyString& operator = (const MyString& other);
    ~MyString();

    void clear();

    char& at(std::size_t pos);
    const char& at(std::size_t pos) const;

    char& operator [] (std::size_t pos);
    const char& operator [] (std::size_t pos) const;

    char& front();
    const char& front() const;

    char& back();
    const char& back() const;

    bool empty() const;

    std::size_t getSize() const;
    const char* c_str() const;

    void push_back(char c);
    void pop_back();

    MyString& operator += (char c);
    MyString& operator += (const MyString& rhs);

    MyString operator + (char c) const;
    MyString operator + (const MyString& rhs) const;

    bool operator == (const MyString &rhs) const;
    bool operator < (const MyString &rhs) const;

    friend std::ostream& operator << (std::ostream& out, const MyString& string); 
    
};

#endif