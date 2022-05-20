#include "Student.h"

void Student::destroy()
{
	delete[] name;
	delete[] specialty;
}

void Student::copy(const Student& other)
{
	facultyNumber = other.facultyNumber;
	grade = other.grade;
	specialNumber = other.specialNumber;
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	specialty = new char[strlen(other.specialty) + 1];
	strcpy_s(specialty, strlen(other.specialty) + 1, other.specialty);
}

void Student::print() const
{
	std::cout << "Name: " << name << "  fac Number: " << facultyNumber << " Grade: " << grade << std::endl;
}

int Student::getFacultyNumber() const
{
	return facultyNumber;
}

int Student::getGrade() const
{
	return grade;
}

void Student::setFacultyNumber(int _f)
{
	facultyNumber = _f;
}

void Student::setGrade(int _g)
{
	grade = _g;
}

void Student::setName(char* _n)
{
	delete[] name;
	name = new char[strlen(_n) + 1];
	strcpy_s(name, strlen(_n) + 1, _n);
}

Student::Student() : facultyNumber(70000), grade(5)
{
	specialNumber = -1;
	name = new char[2];
	strcpy_s(name, 2, "a");
	specialty = new char[2];
	strcpy_s(specialty, 2, " ");
}

Student::Student(const char* _name, int facultyNumber, const char* _specialty, int _grade, long _specialNumber)
{
	this->facultyNumber = facultyNumber;
	grade = _grade;
	specialNumber = _specialNumber;

	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
	specialty = new char[strlen(_specialty) + 1];
	strcpy_s(specialty, strlen(_specialty) + 1, _specialty);
}

Student::Student(const Student& other)
{
	copy(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Student::~Student()
{
	destroy();
}

bool Student::operator==(const Student& other)
{
	return this->grade == other.grade;
}

bool Student::operator!=(const Student& other)
{
	return !(*this == other);
}

int Student::operator()(int number)
{
	return specialNumber;
}

Student& Student::operator++()
{
	grade++;
	return *this;
}

const Student Student::operator++(int incrementor)
{
	Student temp(*this);
	this->grade++;

	return temp;
}

Student Student::operator+(const Student& right)
{
	Student st;
	st.facultyNumber = right.facultyNumber;
	return st;
}

Student& Student::operator+=(const Student& right)
{
	*this = *this + right;
	return *this;
}

void Student::invite()
{
	std::cout << "Welcome to room 404";
}

std::ostream& operator<<(std::ostream& out, const Student& st)
{
	out << st.name << " " << st.facultyNumber << " " << st.grade;

	return out;
}

std::istream& operator>>(std::istream& in, Student& st)
{
	char name[64];
	int facultyNumber;
	int grade;

	in >> name >> st.facultyNumber >> st.grade;

	st.setName(name);

	return in;
}
