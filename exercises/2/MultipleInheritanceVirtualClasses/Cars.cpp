#include "Cars.h"

Car::Car()
{
	model = nullptr;
	fuelConsumption = 0;
}

Car::Car(const char* name, int fuelC)
{
	model = new char[strlen(name) + 1];
	strcpy_s(model, strlen(name) + 1, name);
	fuelConsumption = fuelC;
}

Car::Car(const Car& other)
{
	model = new char[strlen(other.model) + 1];
	strcpy_s(model, strlen(other.model) + 1, other.model);
	fuelConsumption = other.fuelConsumption;
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		delete[] model;
		model = new char[strlen(other.model) + 1];
		strcpy_s(model, strlen(other.model) + 1, other.model);
		fuelConsumption = other.fuelConsumption;
	}
	return *this;
}

Car::~Car()
{
	delete[] model;
}

UpgradedCar::UpgradedCar()
{
	companyName = nullptr;
}

UpgradedCar::UpgradedCar(const char* name, int fuelC, const char* companyName) : Car(name, fuelC)
{
	this->companyName = new char[strlen(companyName) + 1];
	strcpy_s(this->companyName, strlen(companyName) + 1, companyName);
}

UpgradedCar::UpgradedCar(const UpgradedCar& other) : Car(other)
{
	companyName = new char[strlen(other.companyName) + 1];
	strcpy_s(companyName, strlen(other.companyName) + 1, other.companyName);
}

UpgradedCar& UpgradedCar::operator=(const UpgradedCar& other)
{
	if (this != &other)
	{
		Car::operator=(other);
		delete[] companyName;
		companyName = new char[strlen(other.companyName) + 1];
		strcpy_s(companyName, strlen(other.companyName) + 1, other.companyName);
	}
	return *this;
}

UpgradedCar::~UpgradedCar()
{
	delete[] companyName;
}
