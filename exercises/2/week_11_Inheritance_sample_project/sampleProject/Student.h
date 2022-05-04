#pragma once
#include <iostream>

class Student {
private:
	std::string name;
	int facultyNumber;

public:
	const char* getName() const {
		return "";
	}
	void sthSpecificForStudent() const {
		std::cout << " ";
	}
};