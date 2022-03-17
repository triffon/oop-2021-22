#include "team.hpp"

#ifndef __COMPANY_HPP
#define __COMPANY_HPP

class Company {
  private:
    char *name;
    Team *teams;
    size_t numberTeams;

  public:
    Company();
    Company(const char *name, const Team *teams, size_t numberTeams);
    ~Company();

    const char *getName() const;
    void setName(const char *name);
    bool hasEmployee(const char *name);
};

#endif // __COMPANY_HPP
