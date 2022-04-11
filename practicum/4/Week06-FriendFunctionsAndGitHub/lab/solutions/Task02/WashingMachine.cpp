#include "WashingMachine.h"
#include <cassert>
#include <cstring>
#include <iostream>

WashingMachine::WashingMachine()
{
	strcpy(this->make, "");
	strcpy(this->model, "");
	this->capacity = 0;
	this->electricity = 0;
	this->water = 0;
}

WashingMachine::WashingMachine(const char* make, const char* model, const int capacity, const double electricity, const double water)
{
	this->setMake(make);
	this->setModel(model);
	this->setCapacity(capacity);
	this->setElectricity(electricity);
	this->setWater(water);
}

void WashingMachine::setMake(const char* make)
{
	assert(make != nullptr);
	strcpy(this->make, make);
}

void WashingMachine::setModel(const char* model)
{	
	assert(model != nullptr);
	strcpy(this->model, model);
}

void WashingMachine::setCapacity(const int capacity)
{
	this->capacity = capacity;
}

void WashingMachine::setElectricity(const double electricity)
{
	this->electricity = electricity;
}

void WashingMachine::setWater(const double water)
{
	this->water = water;
}

const char* WashingMachine::getMake() const
{
	return this->make;
}

const char* WashingMachine::getModel() const
{
	return this->model;
}

int WashingMachine::getCapacity() const
{
	return this->capacity;
}

double WashingMachine::getElectricity() const
{
	return this->electricity;
}

double WashingMachine::getWater() const
{
	return this->water;
}

//Логиката е,че по-голямо връща по оптималната машина
bool WashingMachine::operator > (const WashingMachine& other) const
{
	if (this->capacity > other.capacity)
	{
		return true;
	}
	
	if(this->capacity == other.capacity && this->electricity < other.electricity)
	{
		return true;
	}
	
    if(this->electricity == other.electricity && this->water < other.water)
	{
		return true;
	}

	return false;
}

std::istream& operator >> (std::istream& in,  WashingMachine& machine)
{
	
    std::cout << "Enter make: ";
    in >> machine.make;
	
    std::cout << "Enter model: ";
    in >> machine.model;
	
    std::cout << "Enter laundry capacity (in kg): ";
    in >> machine.capacity;
	
    std::cout << "Enter electricity consumption: ";
    in >> machine.electricity;

	std::cout << "Enter water consumption: ";
	in >> machine.water;

    return in;
}

std::ostream& operator << (std::ostream& out, const WashingMachine& machine)
{
    out << machine.make << " " << machine.model << std::endl; 

    return out;
}