#include "Students.h"

void Students::add(const Student& st)
{
	if (students.pushBack(st))
	{
		std::cout << "Student: " << st.getName() << "was successfully added\n";
	}
	else
	{
		std::cout << "There was an error when adding student\n";
	}
}

void Students::dosthOnlyForStudents() const
{
	int size = students.getSize();
	for (int i = 0; i < size; i++)
	{
		students[i].sthSpecificForStudent();
	}
}
