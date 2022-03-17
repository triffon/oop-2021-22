#include "WaffleShop.h"

int main() {

	WaffleShop fmi(10);

	fmi.orderWaffles(BOYKO, 3);
	fmi.printInventory();
	
	fmi.sellWaffle();
	
	fmi.orderWaffles(BOROVETS, 10);
	fmi.printInventory();

	fmi.sellWaffle();
	fmi.sellWaffle();
	fmi.sellWaffle();

	fmi.printInventory();
	std::cout << fmi.getIncome() << std::endl;


	return 0;
}