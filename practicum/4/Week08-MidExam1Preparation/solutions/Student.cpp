#include "Student.h"


#include <cstring>
#include <cmath>


Student::Student() : name(nullptr) {}

Student::~Student()
{
    delete[] name;
}

Student& Student::operator =(const Student &other)
{
    if (this != &other)
    {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        fn = other.fn;
        group = other.group;
        averageGrade = other. averageGrade;
    }

    return *this;
}

Student::Student(const char* name, int fn, int group, int averageGrade)
    : name(new char[strlen(name) + 1]), fn(fn), group(group), averageGrade(averageGrade)
{
    strcpy(this->name, name);
}

Student::Student(const Student &other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    fn = other.fn;
    group = other.group;
    averageGrade = other. averageGrade;
}

bool Student::operator <(const Student &other)
{
    double EPS = 1.0/(1<<30);
    if (std::abs(averageGrade - other.averageGrade) < EPS)
    {
        return fn < other.fn;
    }

    return averageGrade < other.averageGrade;
}

bool Student::operator ==(const Student &other)
{
    return fn == other.fn;
}

std::ostream& operator <<(std::ostream& out, const Student &obj)
{
    out << obj.name << ' ' << obj.fn << ' ' << obj.group << ' ' << obj.averageGrade << '\n';

    return out;
}

std::istream& operator >>(std::istream& in, Student &obj)
{
    char buffer[1025] = {'\0',};
    in >> buffer;
    in >> obj.fn >> obj.group >> obj.averageGrade;

    return in;
}

int Student::getFn() const
{
    return fn;
}