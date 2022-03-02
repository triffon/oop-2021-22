#include "Wallet.h"
#include <iostream>

void Wallet::witdraw(double amount)
{
	if (amount > money)
	{
		std::cout << "Not enough money in your bank account\n";
		return;
	}
	money -= amount;
	std::cout << "Widraw success";
}
