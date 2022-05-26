#include "Assistant.h"

Assistant::Assistant(std::string_view name, const int number, const double salary)
	: Student(name, number), Teacher(name, salary), Person(name) {
}
