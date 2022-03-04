#include <iostream>
#include <cstring>

struct Employee {
	char name[32];
	double salary;
	Employee *boss;
};

struct Team {
	char name[32];
	Employee employees[32];
	size_t numberEmployees;
};

struct Company {
	char name[32];
	Team teams[32];
	size_t numberTeams;
};

bool hasEmployee(const Company &c, const char *name) {
	for (size_t i = 0; i < c.numberTeams; i++) {
		for (size_t j = 0; j < c.teams[i].numberEmployees; j++) {
			if (strcmp(c.teams[i].employees[j].name, name) == 0)
				return true;
		}
	}

	return false;
}

void printMainBoss(const Employee &e) {
	const Employee *curr = &e;
	if (curr->boss == nullptr) {
		std::cout << "No boss" << std::endl;
		return;
	}
	     //(*curr).boss
	while (curr->boss != nullptr) {
		curr = curr->boss;
	}

	std::cout << curr->name << std::endl;
}

int main() {
	Employee pesho = { "pesho", 2.0, nullptr };
	Employee gosho = { "gosho", 1.0, &pesho };
	Employee stamat = { "stamat", 1.0, &gosho };
	Employee ivancho = { "ivancho", 1.0, &stamat };

	Team t1 = { "t1", {pesho}, 1};
	Team t2 = { "t2", {gosho}, 1 };
	Company c = { "peshogosho", {t1, t2}, 2 };
	std::cout << hasEmployee(c, "asd") << std::endl;
	std::cout << hasEmployee(c, "pesho") << std::endl;

	printMainBoss(pesho);
	printMainBoss(gosho);
	printMainBoss(stamat);
	printMainBoss(ivancho);
	return 0;
}