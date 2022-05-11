#pragma once
#include <iostream>
#include <cstring>
#include "String.h"

class CarAbs {
private:
	String model;
	int fuelConsumption;
public:
	CarAbs()
	{
		fuelConsumption = 0;
	}
	CarAbs(const char* name, int fuelC) : model(name)
	{
		fuelConsumption = fuelC;
	}
	void printDetails() const {
		std::cout << model << ", " << fuelConsumption << '\n';
	}
};

class UpgradedCarAbs : public CarAbs {
private:
	String companyName;
public:
	UpgradedCarAbs() {};
	UpgradedCarAbs(const char* name, int fuelC, const char* companyName) : CarAbs(name, fuelC), companyName(companyName) {}
	void printUpdatedDetails() const {
		printDetails();
		std::cout << companyName << '\n';
	}
};

class UpgradedCarNewDetailsAbs : public UpgradedCarAbs {
private:
	int addedFuelConsumption;
public:
	UpgradedCarNewDetailsAbs() {
		addedFuelConsumption = 0;
	}
	UpgradedCarNewDetailsAbs(const char* name, int fuelC, const char* companyName, int addedFC) : UpgradedCarAbs(name, fuelC, companyName) {
		addedFuelConsumption = addedFC;
	}
	void print() const {
		printUpdatedDetails();
		std::cout << addedFuelConsumption << '\n';
	}
};