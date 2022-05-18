#include <iostream>
#include <vector>

template<class It, class T>
It find2(It first, It last, T value)
{
    for (; first != last; ++first)
    {
        if (*first == value)
        {
            return first;
        }
    }

    return first;
}

template<class It>
void print(It first, It last)
{
    for (; first != last; ++first)
    {
        std::cout << *first << ' ';
    }

    std::cout << std::endl;
}

template<class T>
class ReverseIterator
{
 public:
    ReverseIterator(T* ptr): m_ptr{ptr}
    {}

    bool operator!=(const ReverseIterator& other) const
    {
        return m_ptr != other.m_ptr;
    }

    bool operator==(const ReverseIterator& other) const
    {
        return m_ptr == other.m_ptr;
    }

    // TODO: other comparisions

    ReverseIterator& operator++()
    {
        --m_ptr;
        return *this;
    }

    ReverseIterator operator++(int)
    {
        ReverseIterator cpy{*this};
        --m_ptr;
        return cpy;
    }

    ReverseIterator& operator--()
    {
        ++m_ptr;
        return *this;
    }

    ReverseIterator operator--(int)
    {
        ReverseIterator cpy{*this};
        ++m_ptr;
        return cpy;
    }

    // TODO: +, -, +=, -=

    T& operator*()
    {
        return *m_ptr;
    }

    const T& operator*() const
    {
        return *m_ptr;
    }

    T* operator->()
    {
        return m_ptr;
    }

    const T* operator->() const
    {
        return m_ptr;
    }

    operator bool() const
    {
        return m_ptr != nullptr;
    }

    operator T*() const
    {
        return m_ptr;
    }
 private:
    T* m_ptr;
};

template<class T, size_t m_size>
struct Array
{
    size_t size() const;
    T* begin();
    const T* begin() const; 
    T* end();
    const T* end() const;

    // TODO: const
    ReverseIterator<T> rbegin();
    ReverseIterator<T> rend();
 
    T m_arr[m_size];
};

template<class T, size_t m_size>
size_t Array<T, m_size>::size() const
{
    return m_size;
}

template<class T, size_t m_size>
T* Array<T, m_size>::begin()
{
    return m_arr;
}

template<class T, size_t m_size>
const T* Array<T, m_size>::begin() const
{
    return m_arr;
}

template<class T, size_t m_size>
T* Array<T, m_size>::end()
{
    return m_arr + m_size;
}

template<class T, size_t m_size>
const T* Array<T, m_size>::end() const
{
    return m_arr + m_size;
}

template<class T, size_t m_size>
ReverseIterator<T> Array<T, m_size>::rbegin()
{
    return ReverseIterator<T>{end() - 1};
}

template<class T, size_t m_size>
ReverseIterator<T> Array<T, m_size>::rend()
{
    return ReverseIterator<T>{begin() - 1};
}

int main()
{
    Array<int, 3> arr{1, 2, 3};

    print(std::rbegin(arr), std::rend(arr));

    std::vector<int> v{1,2,3};

    print(std::crbegin(v), std::crend(v));

    return 0;
}