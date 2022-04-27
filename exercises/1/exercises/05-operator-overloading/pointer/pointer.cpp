#include <iostream>

struct test
{
    int x;
};

class pointer
{
 public:
    pointer() = default;

    explicit pointer(const test& number):
        m_ptr{new test{number}}
    {}

    ~pointer()
    {
        delete m_ptr;
    }

    pointer(const pointer& other):
        m_ptr{new test{*other.m_ptr}}
    {}

    // copy and swap
    pointer& operator=(const pointer& other)
    {
        pointer copy{other};
        std::swap(m_ptr, copy.m_ptr);
        return *this;
    }

    test& operator*()
    {
        return *m_ptr;
    }

    const test& operator*() const
    {
        return *m_ptr;
    }

    test * operator->()
    {
        return m_ptr;
    }

    const test * operator->() const
    {
        return m_ptr;
    }
 private:
    test * m_ptr{nullptr};
};

int main()
{
    test t{10};
    std::cout << t.x;

    pointer p{t};

    std::cout << (*p).x;

    test * ptr{&t};

    std::cout << (*ptr).x;
    std::cout << ptr->x;

    std::cout << p->x;
    return 0;
}