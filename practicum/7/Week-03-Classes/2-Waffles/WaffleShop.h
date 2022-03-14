#pragma once
#include "Waffle.h"
#include <iostream>

class WaffleShop {
public:
	WaffleShop(size_t capacity)
		:waffles(nullptr), size(0), capacity(capacity), income(0), expenses(0) {
		waffles = new Waffle[capacity];
	}

	void sellWaffle() {
		size--;
		income += waffles[size].getSellPrice();
	}

	void orderWaffles(Brand brand, size_t amount) {
		if (amount > capacity - size)
			amount = capacity - size;

		for (size_t i = 0; i < amount; ++i) {
			waffles[size].setBrand(brand);
			expenses += waffles[size].getBuyPrice();
			size++;
		}
	}

	void orderWaffles(Brand brand) {
		orderWaffles(brand, capacity - size);
	}

	size_t getCount(Brand brand) const {
		size_t count = 0;
		for (size_t i = 0; i < size; ++i) {
			if (waffles[i].getBrand() == brand)
				++count;
		}
	}

	size_t getCount(double grams) const {
		size_t count = 0;
		for (size_t i = 0; i < size; ++i) {
			if (waffles[i].getGrams() == grams)
				++count;
		}
	}

	double getIncome() const {
		return income - expenses;
	}

	void printInventory() const {
		for (size_t i = 0; i < size; ++i)
			waffles[i].print();
		std::cout << "--------\n";
	}

private:
	Waffle* waffles;
	size_t size;
	size_t capacity;

	double income;
	double expenses;
};