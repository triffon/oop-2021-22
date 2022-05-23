#include "Student.h"

Student::Student(std::string_view name, const int number)
			: Person(name), m_number(number) {
}

const int Student::getNumber() const {
	return m_number;
}
