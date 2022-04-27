#pragma once
#include "TaxiDriver.h"
#include "Order.h"
class TaxiCentral {
public:
	TaxiCentral(const char* name);
	TaxiCentral(const TaxiCentral& other);
	TaxiCentral& operator=(const TaxiCentral& other);
	~TaxiCentral();

	void addTaxiDriver(const char* name, size_t salary);
	bool makeOrder(const char* sourceAddress, const char*destinationAddress);
	bool makeOrder(const char* sourceAddress, const char* destinationAddress, const char* taxiDriverName);

	void cancelOrder(const char* sourceAddress, const char* destinationAddress);

	void printTaxiDrivers() const;
	void printOrders() const;

	friend std::ostream& operator<<(std::ostream& out, const TaxiCentral& central);

private:
	void copy(const char* name, TaxiDriver* drivers, Order* orders);
	void clear();

	void dResize();
	void oResize();

	char* name;
	TaxiDriver* drivers;
	Order* orders;

	size_t dSize;
	size_t oSize;

	size_t dCap;
	size_t oCap;
};