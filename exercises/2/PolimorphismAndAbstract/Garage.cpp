#include "Garage.h"

void Garage::copy(const Garage& other)
{
	size = other.size;
	capacity = other.capacity;
	cars = new Car * [capacity];
	for (int i = 0; i < size;i++)
	{
		cars[i] = other.cars[i]->clone();
	}
}

void Garage::destroy()
{
	for (int i = 0; i < size;i++)
	{
		delete[] cars[i];
	}
	delete[] cars;
}

Garage::Garage()
{
	size = 0;
	capacity = 5;
	cars = new Car * [capacity];
}

Garage::~Garage()
{
	destroy();
}

void Garage::add(Car* addedCar)
{
	if (size == capacity)
	{

	}
	cars[size++] = addedCar->clone();
}
