#ifndef __COMPANY_HPP
#define __COMPANY_HPP

#include "team.hpp"

class Company {
  private:
    char *name;
    Team *teams;
    size_t numberTeams;

  public:
    Company();
    Company(const char *name, const Team *teams, size_t numberTeams);
    Company(const Company &a);
    ~Company();

    const char *getName() const;
    void setName(const char *name);
    bool hasEmployee(const char *name);

    Company &operator=(const Company &a);
};

#endif // __COMPANY_HPP
