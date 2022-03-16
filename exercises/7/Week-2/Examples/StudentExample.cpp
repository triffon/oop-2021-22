/*
    Problem: Write a C++ class that represents a student. A student has first,
             middle & last names (char*), a faculty number (unsigned int)
             and a faculty (enum). Create appropriate constructor, destructor
            and methods to access the fields of a student.
*/

#include <iostream>
#include <string.h>

using namespace std;

enum Faculty
{
    FMI,
    CF,
    FF
};

class Student
{
private:
    char *firstName;
    char *middleName;
    char *lastName;

    Faculty faculty;

    unsigned int facultyNumber;

public:
    Student(const char *firstName, const char *middleName, const char *lastName, unsigned int facultyNumber, Faculty faculty)
    {
        this->faculty = faculty;
        this->facultyNumber = facultyNumber;

        this->firstName = new char[strlen(firstName)];
        strcpy(this->firstName, firstName);

        this->middleName = new char[strlen(middleName)];
        strcpy(this->middleName, middleName);

        this->lastName = new char[strlen(lastName)];
        strcpy(this->lastName, lastName);
    }

    ~Student()
    {
        delete[] firstName;
        delete[] middleName;
        delete[] lastName;
    }

    char *getFirstName() const
    {
        return firstName;
    }

    char *getMiddleName() const
    {
        return middleName;
    }

    char *getLastName() const
    {
        return lastName;
    }

    Faculty getFaculty() const
    {
        return faculty;
    }

    unsigned int getFacultyNumber() const
    {
        return facultyNumber;
    }
};

void printStudent(Student &student)
{
    cout << "First Name    : " << student.getFirstName() << endl;
    cout << "Middle Name   : " << student.getMiddleName() << endl;
    cout << "Last Name     : " << student.getLastName() << endl;
    cout << "Faculty       : " << student.getFaculty() << endl;
    cout << "Faculty Number: " << student.getFacultyNumber() << endl;
}

int main()
{
    Student first("Ivan", "Ivanov", "Petrov", 12345, FMI);
    Student second("Petar", "Ivanov", "Ivanov", 54321, CF);

    printStudent(first);
    printStudent(second);

    return 0;
}
