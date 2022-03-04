#include "team.hpp"
#include "worker.hpp"
#pragma warning (disable : 4996)

#include <cstring>

Team::Team(const char *name, Worker *employees, size_t numberEmployees) {
	this->setName(name);

	this->employees = new Worker[numberEmployees];
	for (size_t i = 0; i < numberEmployees; i++) {
		this->employees[i] = Worker(employees[i].getName(), 200, nullptr);
	}
	this->numberEmployees = numberEmployees;
}


Team::~Team() {
	if (this->name != nullptr) {
		delete[] this->name;
	}
	
	delete[] this->employees;
}

const char *Team::getName() const {
	return this->name;
}

void Team::setName(const char *name) {
	if (this->name != nullptr) {
		delete[] this->name;
	}

	this->name = new char[strlen(name)];
	strcpy(this->name, name);
}