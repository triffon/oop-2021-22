#ifndef ASSISTANT_H
#define ASSISTANT_H

#include "Student.h"
#include "Teacher.h"

class Assistant : public Student, public Teacher {
public:
	Assistant(std::string_view name, const int number, const double salary);
};

#endif // !ASSISTANT_H
