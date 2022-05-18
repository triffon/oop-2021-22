#include "University.h"


#include <iostream>

void University::reallocate()
{
    Student** newData = new Student*[capacity*2];
    capacity *= 2;
    for (int i = 0; i < m_size; ++i)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

University::University()
{
    capacity = 8;
    m_size = 0;
    data = new Student*[capacity];

}

University::~University()
{
    for (int i = 0; i < m_size; ++i)
    {
        delete data[i];
    }

    delete[] data;
}

void University::sort(bool(*cmp)(const Student&, const Student&))
{
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = i + 1; j < m_size - i; ++j)
        {
            if (cmp(*data[j], *data[j-1]))
            {
                Student* temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
            }
        }
    }
}

void University::filter(bool(*pred)(const Student&))
{
    for (int i = 0; i < m_size; ++i)
    {
        if (pred(*data[i]))
        {
            std::cout << *data[i];
        }
    }
}

University& University::operator +=(const Student& st)
{
    if (m_size == capacity)
    {
        reallocate();
    }
    data[m_size++] = new Student(st);

    return *this;
}

University& University::operator -=(int fn)
{
    for (int i = 0; i < m_size; ++i)
    {
        if (data[i]->getFn() == fn)
        {
            std::swap(data[i], data[--m_size]);
            delete data[m_size];
            break;
        }
    }

    return *this;
}

std::ostream& operator <<(std::ostream& out, const University &obj)
{
    out << obj.m_size << '\n';

    for (int i = 0; i < obj.m_size; ++i)
    {
        out << *obj.data[i];
    }

    return out;
}

std::istream& operator >>(std::istream& in, University &obj)
{
    int curSize;
    in >> curSize;
    for (int i = 0; i < curSize; ++i)
    {
        Student temp;
        in >> temp;
        obj += temp;
    }

    return in;
}