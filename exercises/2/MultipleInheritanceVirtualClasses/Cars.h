#pragma once
#include <iostream>
#include <cstring>

class Car {
private:
	char* model;
	int fuelConsumption;
public:
	Car();
	Car(const char* name, int fuelC);
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();
	void printDetails() const {
		std::cout << model << ", " << fuelConsumption << '\n';
	}
};

class UpgradedCar : public Car {
private:
	char* companyName;
public:
	UpgradedCar();
	UpgradedCar(const char* name, int fuelC, const char* companyName);
	UpgradedCar(const UpgradedCar& other);
	UpgradedCar& operator=(const UpgradedCar& other);
	~UpgradedCar();
	void printUpdatedDetails() const {
		printDetails();
		std::cout << companyName  << '\n';
	}
};

class UpgradedCarNewDetails : public UpgradedCar {
private:
	int addedFuelConsumption;
public:
	UpgradedCarNewDetails() {
		addedFuelConsumption = 0;
	}
	UpgradedCarNewDetails(const char* name, int fuelC, const char* companyName, int addedFC) : UpgradedCar(name, fuelC, companyName) {
		addedFuelConsumption = addedFC;
	}
	void print() const {
		printUpdatedDetails();
		std::cout << addedFuelConsumption << '\n';
	}
};