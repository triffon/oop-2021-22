#include "Animal.h"
#include <iostream>

int main() {

	Animal a("Pesho", "Kon", 12);
	Animal b("Gosho Petrov", "Ovca Golqma", 3);

	a.writeToTextFile("Jivotinki.txt");
	//b.writeToTextFile("Jivotinki.txt");

	a.serialize("animals.dat");

	std::cout << "Enter name, breed and age: \n";
	std::cin >> b;
	std::cout << b;

	return 0;
}