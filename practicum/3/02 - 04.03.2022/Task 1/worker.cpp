#include "worker.hpp"
#include <cstring>
#pragma warning (disable : 4996 )

Worker::Worker() {}

Worker::Worker(const char *name, double salary, Worker *boss) {
	this->setName(name);
	this->salary = salary;
	this->boss = boss;
}

Worker::~Worker() {
	if (this->name != nullptr) {
		delete[] this->name;
	}
}

const char *Worker::getName() const {
	return this->name;
}

void Worker::setName(const char *name) {
	if (this->name != nullptr) {
		delete[] this->name;
	}

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}