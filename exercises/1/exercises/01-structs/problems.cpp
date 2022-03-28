#include <iostream>
#include <algorithm>
#include <cstring>

struct MismatchResult
{
    const int * first{};
    const int * second{};
};

// 1 2 (3)
// 1 2 (X)

MismatchResult mismatch(const int * first_1, const int * last_1, const int * first_2, const int * last_2)
{
    while (first_1 != last_1 && first_2 != last_2 && *first_1 == *first_2)
    {
        ++first_1;
        ++first_2;
    }

    return { first_1, first_2 };
}

struct MinmaxElementResult
{
    const int * min{};
    const int * max{};
};

// HW: This with fewer comparisons
MinmaxElementResult minmax_element(const int * first, const int * last)
{
    const int * min{first};
    const int * max{first};

    for (++first; first != last; ++first)
    {
        if (*first < *min)
        {
            min = first;
        }
        else if (*first >= *max)
        {
            max = first;
        }
    }

    return { min, max };
}

struct Student
{
    int id{};
    char name[32]{};
};

Student read_student()
{
    Student student;
    std::cin >> student.id;
    std::cin.ignore();
    std::cin.clear();
    std::cin.getline(student.name, 32);

    return student;
}

void print_student(const Student& student)
{
    std::cout << student.id << ": " << student.name << '\n';
}

void read_students(Student * first, Student * last)
{
    for (; first != last; ++first)
    {
        *first = read_student();
    }
}

void print_students(const Student * first, const Student * last)
{
    for (; first != last; ++first)
    {
        print_student(*first);
    }
}

int compare_students(const Student& lhs, const Student& rhs)
{
    return lhs.id - rhs.id;
    // return std::strcmp(lhs.name, rhs.name);
    // return rhs.id - lhs.id;
}

Student * min_element(Student * first, Student * last)
{

    Student * min{first};

    for (++first; first != last; ++first)
    {
        if (compare_students(*first, *min) < 0)
        {
            min = first;
        }
    }

    return min;
}

void sort_students(Student * first, Student * last)
{
    for (; first != last; ++first)
    {
        std::iter_swap(first, min_element(first, last));
    }
}

int main()
{
    Student students[3];

    read_students(students, std::end(students));
    sort_students(students, std::end(students));
    print_students(students, std::end(students));

    return 0;
}