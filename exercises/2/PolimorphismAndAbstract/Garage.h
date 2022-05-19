#pragma once
#include "Cars.h"

class Garage {
private:
	Car** cars;
	int size;
	int capacity;
	void copy(const Garage& other);
	void destroy();
public:
	Garage();
	Garage(const Garage& other);
	Garage& operator =(const Garage& other);
	~Garage();
	void add(Car* addedCar);
};