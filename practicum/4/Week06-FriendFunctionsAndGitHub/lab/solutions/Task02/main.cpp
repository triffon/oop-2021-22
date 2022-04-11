#include <iostream>

#include "WashingMachine.h"

int main()
{
	int n;
	std::cout << "n = ";
	std::cin >> n;

	WashingMachine optimal;
	std::cin >> optimal;

	for (int i = 1; i < n; i++)
	{
		WashingMachine newMachine;

		std::cin >> newMachine;

		if (newMachine > optimal)
		{
			optimal = newMachine;
		}
	}

	std::cout << optimal;

	return 0;
}