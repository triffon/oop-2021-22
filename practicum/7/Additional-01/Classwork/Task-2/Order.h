#pragma once
#include "TaxiDriver.h"

class Order {
public:
	Order();
	Order(const char* srcAddr, const char* destAddr, TaxiDriver* driver);
	Order(const Order& other);
	Order& operator=(const Order& other);
	~Order();

	const char* getSrcAddr() const {
		return srcAddr;
	}

	const char* getDestAddr() const {
		return destAddr;
	}

	friend std::istream& operator>>(std::istream& in, Order& order);
	friend std::ostream& operator<<(std::ostream& out, const Order& order);

private:
	void copy(const char* srcAddr, const char* destAddr, TaxiDriver* driver);
	void clear();

	char* srcAddr;
	char* destAddr;
	TaxiDriver* driver;
};