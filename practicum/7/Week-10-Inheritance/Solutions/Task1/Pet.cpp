#include "Pet.h"
#include <cstring>
#include <iostream>

Pet::Pet():Animal(), owner(nullptr) {
	changeOwner("No Owner", 0);
}

Pet::Pet(const char* name, unsigned age, const char* owner, unsigned phone):Animal(name, age), owner(nullptr) {
	changeOwner(owner, phone);
}

Pet::Pet(const Pet& other):Animal(other), owner(nullptr) {
	changeOwner(other.owner, other.phone);
}

Pet& Pet::operator=(const Pet& other) {
	if (this != &other) {
		Animal::operator=(other);
		changeOwner(other.owner, other.phone);
	}

	return *this;
}
Pet::~Pet() {
	delete[] owner;
}

void Pet::print() const {
	Animal::print();
	std::cout << owner << ", " << phone << std::endl;
}
void Pet::changeOwner(const char* name, unsigned phone) {
	if (owner)
		delete[] owner;

	owner = new char[strlen(name) + 1];
	strcpy_s(owner, strlen(name) + 1, name);

	this->phone = phone;
}