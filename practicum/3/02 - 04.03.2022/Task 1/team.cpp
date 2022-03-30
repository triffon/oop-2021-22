#include "team.hpp"
#include "worker.hpp"
#pragma warning(disable : 4996)

#include <cstring>

Team::Team() {
    this->name = nullptr;
    this->employees = nullptr;
    this->numberEmployees = 0;
}

Team::Team(const char *name, const Worker *employees, size_t numberEmployees) : Team() {
    this->setName(name);

    this->employees = new Worker[numberEmployees];
    for (size_t i = 0; i < numberEmployees; i++) {
        this->employees[i] = employees[i];
    }
    this->numberEmployees = numberEmployees;
}

Team::Team(const Team &a) : Team() {
    this->setName(a.name);
    this->employees = new Worker[a.getNumberEmployees()];
    for (int i = 0; i < a.getNumberEmployees(); i++) {
        this->employees[i] = a.employees[i];
    }
    this->numberEmployees = a.getNumberEmployees();
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

const Worker *Team::getEmployees() const {
    return this->employees;
}

size_t Team::getNumberEmployees() const {
    return this->numberEmployees;
}

Team &Team::operator=(const Team &o) {
    if (this == &o) {
        return *this;
    }
    this->setName(o.name);
    if (this->employees != nullptr) {
        delete[] this->employees;
    }
    this->employees = new Worker[o.numberEmployees];
    for (size_t i = 0; i < o.numberEmployees; i++) {
        this->employees[i] = o.employees[i];
    }
    this->numberEmployees = o.numberEmployees;

    return *this;
}
