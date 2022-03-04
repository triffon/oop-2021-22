#pragma once
#ifndef __TEAM_HPP
#define __TEAM_HPP

#include "worker.hpp"

class Team {
private:
	char *name = nullptr;
	Worker *employees;
	size_t numberEmployees;

public:
	Team(const char *name, Worker *employees, size_t numberEmployees);
	~Team();

	const char *getName() const;
	void setName(const char *name);
};
#endif // __TEAM_HPP