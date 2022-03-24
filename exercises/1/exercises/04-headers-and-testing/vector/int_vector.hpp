#pragma once

#include <iostream>

class IntVector
{
 public:
    IntVector() = default;
    explicit IntVector(size_t);
    IntVector(const IntVector&); // = delete
    IntVector& operator=(const IntVector&);
    ~IntVector();

    void print() const;
    // method: push_back
    // input: 1 integer
    // output: void
    // add an int to the end of the vector
    void push_back(int);

    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    int * data();
    const int * data() const;

    int& front();
    const int& front() const;

    int& back();
    const int& back() const;

    void swap(IntVector&);
 private:
    int * m_data{nullptr};
    size_t m_size{0};
    size_t m_capacity{0};

    void expand(size_t);
};
