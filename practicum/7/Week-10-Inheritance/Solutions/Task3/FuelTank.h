#pragma once
#include "insufficent_fuel.h"
class FuelTank
{
	double capacity;
	double currLevel;
public:
	FuelTank(double cap) : capacity(cap), currLevel(cap)
	{}
	void use(double toUse);
	void fill(double toRefill);
};

