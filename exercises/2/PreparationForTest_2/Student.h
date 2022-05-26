#pragma once
#include <iostream>

class Student
{
private:
	char* name;
	int facultyNumber;
	char* specialty;
	int grade;
	long specialNumber;
	void destroy();
	void copy(const Student& other);
public:
	void print() const;
	int getFacultyNumber() const;
	int getGrade() const;
	void setFacultyNumber(int _f);
	void setGrade(int _g);
	void setName(char* _n);
	Student();
	Student(const char*, int _faculty, const char* _specialty, int _grade, long _specialNumber);
	Student(const Student& other);
	Student& operator =(const Student& other);
	~Student();

	bool operator ==(const Student& other);
	bool operator !=(const Student& other);
	int operator()(int number);

	friend std::ostream& operator<<(std::ostream& out, const Student& st);
	friend std::istream& operator>>(std::istream& in, Student& st);

	Student& operator++();
	const Student operator++(int incrementor);

	Student operator+(const Student & right);
	Student& operator+=(const Student& right);

	void invite();
};