#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : virtual public Person {
public:
	Student(std::string_view name, const int number);

	const int getNumber() const;

protected:
	int m_number;
};

#endif // !STUDENT_H
