#pragma once
#include <iostream>
#include <cstring>
#include <stdexcept>

enum Brand {
	INVALID = -1,

	SPOKO,
	BOROVETS,
	BOYKO,

	COUNT
};

// These arrays will be the same for every waffle object.
	// Later we will learn how to contain them in the class
	// definition, so that we don't pollute the global scope,
	// but for now we'll think of them as just global constants.
const char* brandNames[COUNT] = { "Spoko", "Borovets", "Boyko" };
const double brandBuyPrices[COUNT] = { 0.30, 0.33, 0.40 };
const double brandSellPrices[COUNT] = { 0.60, 0.80, 1.99 };
const double brandGrams[COUNT] = { 80, 101, 80 };

class Waffle {
public:
	Waffle() :brand(INVALID), grams(-1), buyPrice(-1), sellPrice(-1) {};

	void setBrand(Brand brand) {
		if (brand >= COUNT || brand <= INVALID)
			throw std::invalid_argument("This is not a waffle brand");

		this->brand = brand;
		grams = brandGrams[brand];
		buyPrice = brandBuyPrices[brand];
		sellPrice = brandSellPrices[brand];
	}

	Brand getBrand() const {
		return brand;
	}

	double getGrams() const {
		return grams;
	}

	double getBuyPrice() const {
		return buyPrice;
	}

	double getSellPrice() const {
		return sellPrice;
	}

	void print() const {
		std::cout << brandNames[brand] << ", " << grams << "g., " << sellPrice << "lv.\n";
	}

private:
	Brand brand;
	double grams;
	double buyPrice;
	double sellPrice;
};