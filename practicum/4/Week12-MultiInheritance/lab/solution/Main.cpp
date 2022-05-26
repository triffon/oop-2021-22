#include <iostream>

#include "Assistant.h"

int main() {
	Assistant* svilen = new Assistant("Svilen Andonov", 43665, 400);

	std::cout << svilen->getName() << std::endl;
	std::cout << svilen->getNumber() << std::endl;
	std::cout << svilen->getSalary() << std::endl;

	delete svilen;

	return 0;
}
