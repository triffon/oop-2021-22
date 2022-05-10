#include "FuelTank.h"

void FuelTank::use(double toUse)
{
	if (toUse > currLevel) {
		throw insufficent_fuel("Too much fuel used");
	}
	currLevel -= toUse;
}

void FuelTank::fill(double toRefill)
{
	if (currLevel + toRefill > capacity) {
		currLevel = capacity;
	}
	else {
		currLevel += toRefill;
	}
}
