#include "int_vector.hpp"

#include <algorithm>

IntVector::IntVector(size_t capacity):
    m_data{new int[capacity]},
    m_size{0},
    m_capacity{capacity}
{}

IntVector::~IntVector()
{
    delete [] m_data;
}

void IntVector::print() const
{
    if (m_size == 0)
    {
        std::cout << "Empty\n";
        return;
    }

    for (size_t i{0}; i < m_size; ++i)
    {
        std::cout << m_data[i] << ' ';
    }

    std::cout << '\n';
}

void IntVector::push_back(int element)
{
    if (m_size == m_capacity)
    {
        expand(m_capacity == 0 ? 1 : m_capacity * 2);
    }

    m_data[m_size++] = element;
}

void IntVector::expand(size_t capacity)
{
    m_capacity = capacity;
    int * temp{new int[m_capacity]};
    std::copy(m_data, m_data + m_size, temp);
    delete [] m_data;
    m_data = temp;
}

IntVector::IntVector(const IntVector& other):
    m_data{new int[other.m_capacity]},
    m_size{other.m_size},
    m_capacity{other.m_capacity}
{
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
}

// Copy and Swap Idiom
IntVector& IntVector::operator=(const IntVector& other)
{
    IntVector copy{other};
    swap(copy);
    return *this;
} // Dtor of copy

void IntVector::swap(IntVector& other)
{
    using std::swap;
    swap(m_data, other.m_data);
    swap(m_size, other.m_size);
    swap(m_capacity, other.m_capacity);
}

size_t IntVector::size() const
{
    return m_size;
}

size_t IntVector::capacity() const
{
    return m_capacity;
}

bool IntVector::empty() const
{
    return m_size == 0;
}

int * IntVector::data()
{
    return m_data;
}

const int * IntVector::data() const
{
    return data();
}

// overloading
int& IntVector::front()
{
    return *m_data;
}

const int& IntVector::front() const
{
    return *m_data;
}

int& IntVector::back()
{
    return *(m_data + m_size - 1);
}

const int& IntVector::back() const
{
    return *(m_data + m_size - 1);
}