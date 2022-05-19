#include <iostream>
#include <string>
#include <ios>
#include <vector>
#include <iterator>

struct Student
{
    std::string name;
    int number;
};

std::ostream& operator<<(std::ostream& out, const Student& s)
{
    return out << s.name << ' ' << s.number;
}

bool operator<(const Student& lhs, const Student& rhs)
{
    return lhs.number < rhs.number;
}

template<typename It, typename Predicate>
bool all_of(It first, It last, Predicate p)
{
    for (; first != last; ++first)
    {
        if (!p(*first))
        {
            return false;
        }
    }

    return true;
}

template<typename It, typename Predicate>
bool any_of(It first, It last, Predicate p)
{
    for (; first != last; ++first)
    {
        if (p(*first))
        {
            return true;
        }
    }

    return false;
}

template<typename It, typename Predicate>
bool none_of(It first, It last, Predicate p)
{
    for (; first != last; ++first)
    {
        if (p(*first))
        {
            return false;
        }
    }

    return true;
}

// map [1,2,3] -> double_number -> [2,4,6]
// transform

template<typename InputIt, typename OutputIt, typename UnaryOperation>
OutputIt transform2(InputIt first, InputIt last, OutputIt output_first, UnaryOperation f)
{
    for (; first != last; ++first)
    {
        *output_first = f(*first);
        ++output_first;
    }

    return output_first;
}

// filter [1,2,3] -> even -> [2]
// copy_if
template<typename InputIt, typename OutputIt, typename UnaryPredicate>
OutputIt copy_if2(InputIt first, InputIt last, OutputIt output_first, UnaryPredicate p)
{
    for (; first != last; ++first)
    {
        if (p(*first))
        {
            *output_first = *first;
            ++output_first;
        }
    }

    return output_first;
}

// find_if
template<typename InputIt, typename UnaryPredicate>
InputIt find_if2(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first)
    {
        if (p(*first))
        {
            return first;
        }
    }

    return first;
}

template<typename InputIt, typename Comparator>
InputIt min_element(InputIt first, InputIt last, Comparator cmp)
{
    InputIt min{first};

    for (++first; first != last; ++first)
    {
        if (cmp(*first, *min))
        {
            min = first;
        }
    }

    return min;
}

template<typename InputIt, typename Comparator>
void selection_sort(InputIt first, InputIt last, Comparator cmp)
{
    for (; first != last; ++first)
    {
        std::iter_swap(first, min_element(first, last, cmp));
    }
}


template<typename InputIt>
InputIt min_element(InputIt first, InputIt last)
{
    InputIt min{first};

    for (++first; first != last; ++first)
    {
        if (*first < *min)
        {
            min = first;
        }
    }

    return min;
}

template<typename InputIt>
void selection_sort(InputIt first, InputIt last)
{
    for (; first != last; ++first)
    {
        std::iter_swap(first, min_element(first, last));
    }
}

// reduce [1,2,3] -> 0 -> +
// 0 + 1 + 2 + 3
// reduce [1,2,3] -> 1 -> *
// accumulute

template<typename InputIt, typename ValueType, typename BinaryOperation>
ValueType accumulute2(InputIt first, InputIt last, ValueType init, BinaryOperation op)
{
    for (; first != last; ++first)
    {
        init = op(init, *first);
    }

    return init;
}

int main()
{
    int arr[]{
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    std::cout << accumulute2(std::cbegin(arr), std::cend(arr), 0, std::plus<int>{});

    return 0;
}