#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
	Person(std::string_view name);

	std::string_view getName() const;

protected:
	std::string m_name;
};

#endif // !PERSON_H
