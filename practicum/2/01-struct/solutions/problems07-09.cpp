#include <iostream>

const int MAX_NAME_LEN = 64;

struct Student 
{
    char name[MAX_NAME_LEN];
    unsigned facultyNum;
};


void read(Student& st)
{
    std::cin >> st.name >> st.facultyNum;
}


void print(const Student& st)
{
    std::cout << "Name: " << st.name << ", FN: " << st.facultyNum;
}


int main()
{
    // const int CONST = 5;     // For storing just 5 students
    // Student arr[CONST];

    int numOfStudents;
    std::cin >> numOfStudents;

    Student* arr = new (std::nothrow) Student[numOfStudents];
    if (!arr)
    {
        std::cerr << "Not enough memory!\n";
        return -1;
    }

    for (int i = 0; i < numOfStudents; i++)
        read(arr[i]);

    std::cout << '\n';

    for (int i = 0; i < numOfStudents; i++)
    {
        print(arr[i]);
        std::cout << '\n';
    }

    delete[] arr;

    return 0;
}
