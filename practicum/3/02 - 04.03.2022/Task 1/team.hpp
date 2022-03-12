#pragma once
#ifndef __TEAM_HPP
#define __TEAM_HPP

#include "worker.hpp"

class Team {
  private:
    char *name;
    Worker *employees;
    size_t numberEmployees;

  public:
    Team();
    Team(const char *name, const Worker *employees, size_t numberEmployees);
    ~Team();

    const Worker *getEmployees() const;
    size_t getNumberEmployees() const;

    const char *getName() const;
    void setName(const char *name);
};
#endif // __TEAM_HPP
