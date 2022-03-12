#include "company.hpp"
#include "team.hpp"
#include <cstring>

#pragma warning(disable : 4996)

Company::Company() {
    this->name = nullptr;
    this->teams = nullptr;
    this->numberTeams = 0;
}

Company::Company(const char *name, const Team *teams, size_t numberTeams) : Company() {
    this->setName(name);
    this->teams = new Team[numberTeams];
    for (size_t i = 0; i < numberTeams; i++) {
        this->teams[i] = Team(teams[i].getName(), teams[i].getEmployees(), teams[i].getNumberEmployees());
    }
    this->numberTeams = numberTeams;
}

Company::~Company() {
    if (this->name != nullptr) {
        delete[] this->name;
    }
    if (this->teams != nullptr) {
        delete[] this->teams;
    }
}

const char *Company::getName() const {

    return this->name;
}

void Company::setName(const char *name) {
    if (this->name != nullptr) {
        delete[] this->name;
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

bool Company::hasEmployee(const char *name) {
    for (size_t i = 0; i < this->numberTeams; i++) {
        for (size_t j = 0; j < this->teams[i].getNumberEmployees(); j++) {
            if (strcmp(this->teams[i].getEmployees()[j].getName(), name) == 0) {
                return true;
            }
        }
    }
    return false;
}
