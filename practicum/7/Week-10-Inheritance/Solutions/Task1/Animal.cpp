#include "Animal.h"
#include <cstring>
#include <iostream>

Animal::Animal():name(nullptr), age(0) {
	setName("Default Animal");
}

Animal::Animal(const char* name, unsigned age): name(nullptr) {
	setName(name);
	this->age = age;
}

Animal::Animal(const Animal& other) {
	setName(other.name);
	age = other.age;
}
Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		setName(other.name);
		age = other.age;
	}

	return *this;
}

Animal::~Animal() {
	delete[] name;
}

void Animal::print() const {
	std::cout << name << ", " << age << std::endl;
}
void Animal::setName(const char* name) {
	if (this->name)
		delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}