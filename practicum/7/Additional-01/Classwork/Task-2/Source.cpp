#include "TaxiCentral.h"
#include <iostream>

int main() {
	TaxiCentral OK("OK SuperShano");

	OK.addTaxiDriver("Misho Volana", 100);
	OK.addTaxiDriver("Sasho Shefa", 1000);

	OK.makeOrder("FMI", "Rektorata");
	OK.makeOrder("FMI", "Studentski", "Sasho Shefa");

	OK.printOrders();
	OK.printTaxiDrivers();

	std::cout << OK;

	OK.cancelOrder("FMI", "Rektorata");

	std::cout << OK;

	return 0;
}