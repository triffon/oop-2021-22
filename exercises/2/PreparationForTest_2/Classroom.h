#pragma once
#include "Student.h" 

using predicate = bool (*)(const Student&);

class Classroom
{
private:
	Student* students;
	int capacity;
	int size;
	void copy(const Classroom& other);
	void resize();
public:
	Classroom();
	Classroom(int capacity);
	Classroom(const Classroom& other);
	Classroom& operator =(const Classroom& other);
	~Classroom();
	void addStudent(const Student& newStudent);
	void print() const;
	void invite(predicate p) const;
	//void sort(bool gabd, bool ascending = true);
};