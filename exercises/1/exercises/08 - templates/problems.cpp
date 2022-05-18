#include <iostream>

template<class It, class T>
It find(It first, It last, T value)
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

int main()
{
    const int arr[3]{0, 2, 1};

    std::cout << find(std::begin(arr), std::end(arr), 1) - std::begin(arr);

    return 0;
}