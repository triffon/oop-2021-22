#pragma once
#include "DynamicArray.h"
#include "Student.h"


class Students {
private:
	DynamicArray<Student> students;
public:
	void add(const Student& st);
	void dosthOnlyForStudents() const;
};