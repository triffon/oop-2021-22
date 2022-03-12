#include "worker.hpp"
#include <cstring>
#include <iostream>
#pragma warning(disable : 4996)

Worker::Worker() {
    this->name = nullptr;
    this->salary = 0;
    this->boss = nullptr;
}

Worker::Worker(const char *name, double salary, Worker *boss) : Worker() {
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

void Worker::printCEO() const {
    if (this->boss != nullptr) {
        this->boss->printCEO();
    } else {
        std::cout << this->getName() << std::endl;
    }
}
