#include <iostream>
#include "team.hpp"

int main() {
	char name[15];
	std::cin >> name;
	Team team(name, nullptr, 0);
	std::cout << team.getName() << std::endl;
}