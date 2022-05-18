#pragma once

#include "Student.h"

class University
{
private:
    Student** data;
    size_t capacity;
    size_t m_size;

    void reallocate();

public:
    University();
    ~University();
    void sort(bool(*cmp)(const Student&, const Student&));
    void filter(bool(*pred)(const Student&));
    University& operator +=(const Student& st);
    University& operator -=(int fn);
    friend std::ostream& operator <<(std::ostream& out, const University &obj);
    friend std::istream& operator >>(std::istream& in, University &obj);

};