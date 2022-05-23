#ifndef FURNITUREHOUSE_H
#define FURNITUREHOUSE_H

#include "Furniture.h"

class FurnitureHouse {
public:
	FurnitureHouse();
	FurnitureHouse(const FurnitureHouse& other);
	~FurnitureHouse();

	size_t size() const;

	Furniture* getFurnitureAtID(const int id) const;

	void print() const;

	Furniture* operator[](const int index);
	const Furniture* operator[](const int index) const;

	FurnitureHouse& operator+=(Furniture* furniture);
	FurnitureHouse& operator-=(Furniture* furniture);

	FurnitureHouse& operator=(const FurnitureHouse& other);

private:
	Furniture** m_data;
	size_t m_size;
	size_t m_capacity;

	void deleteData();
	void allocData(size_t newCapacity);
	void copy(const FurnitureHouse& other);

	Furniture* getFurnitureAtIndex(const int index) const;
};

#endif // !FURNITUREHOUSE_H
