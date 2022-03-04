#include "team.hpp"

#ifndef __COMPANY_HPP
#define __COMPANY_HPP

struct Company {
	char *name;
	Team *teams;
	size_t numberTeams;
};


#endif // __COMPANY_HPP
