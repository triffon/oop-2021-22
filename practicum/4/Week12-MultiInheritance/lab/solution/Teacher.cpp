#include "Teacher.h"

Teacher::Teacher(std::string_view name, const double salary)
			: Person(name), m_salary(salary) {
}

const double Teacher::getSalary() const {
	return m_salary;
}
