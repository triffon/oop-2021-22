#include <iostream>
#include <algorithm>

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

    void swap(IntVector&);
 private:
    int * m_data{nullptr};
    size_t m_size{0};
    size_t m_capacity{0};

    void expand(size_t);
};

// RAII
// Resource acquisition is initialization

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
        expand(m_capacity * 2);
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

// rule of 3

// rule of 0

// business logic class -> grade book -> rule of 0
// resource management class -> vector -> follow the rule of 3

int main()
{
    IntVector vec(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    vec.print();

    vec = vec;

    vec.print();
    return 0;
}

