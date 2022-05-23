#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

class Teacher : virtual public Person {
public:
	Teacher(std::string_view name, const double salary);

	const double getSalary() const;

protected:
	double m_salary;
};

#endif // !TEACHER_H
