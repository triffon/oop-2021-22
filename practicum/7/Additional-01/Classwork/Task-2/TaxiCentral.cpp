#include "TaxiCentral.h"

TaxiCentral::TaxiCentral(const char* name) {

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	dSize = 0;
	oSize = 0;

	dCap = 2;
	oCap = 2;

	drivers = new TaxiDriver[dCap];
	orders = new Order[oCap];
}

TaxiCentral::TaxiCentral(const TaxiCentral& other) {
	//copy(other.name, drivers, orders, dSize, oSize, dCap, oCap);
}

TaxiCentral& TaxiCentral::operator=(const TaxiCentral& other) {
	if (this != &other) {
		//copy(other.name, drivers, orders, двата size, двата cap)
	}

	return *this;
}


TaxiCentral::~TaxiCentral() {
	clear();
}

void TaxiCentral::addTaxiDriver(const char* name, size_t salary) {
	if (dSize >= dCap)
		dResize();

	drivers[dSize] = TaxiDriver(name, salary);
	dSize++;
}

bool TaxiCentral::makeOrder(const char* sourceAddress, const char* destinationAddress) {
	for (size_t i = 0; i < dSize; ++i) {
		if (!drivers[i].isBusy()) {
			if (oSize >= oCap)
				oResize();

			orders[oSize] = Order(sourceAddress, destinationAddress, &drivers[i]);
			++oSize;

			drivers[i].setBusy(true);

			return true;
		}
	}

	return false;
}

bool TaxiCentral::makeOrder(const char* sourceAddress, const char* destinationAddress, const char* taxiDriverName) {
	for (size_t i = 0; i < dSize; ++i) {
		if (!strcmp(drivers[i].getName(), taxiDriverName) && !drivers[i].isBusy()) {
			if (oSize >= oCap)
				oResize();

			orders[oSize] = Order(sourceAddress, destinationAddress, &drivers[i]);
			++oSize;

			drivers[i].setBusy(true);

			return true;
		}
	}

	return false;
}

void TaxiCentral::cancelOrder(const char* sourceAddress, const char* destinationAddress) {
	for (size_t i = 0; i < oSize; ++i) {
		if (!strcmp(orders[i].getSrcAddr(), sourceAddress) && !strcmp(orders[i].getDestAddr(), destinationAddress)) {
			
			drivers[i].setBusy(false);

			orders[i] = orders[oSize - 1];
			oSize--;
		}
	}
}

void TaxiCentral::printTaxiDrivers() const {
	for (size_t i = 0; i < dSize; ++i)
		std::cout << drivers[i] << "\n";
}

void TaxiCentral::printOrders() const {
	for (size_t i = 0; i < oSize; ++i)
		std::cout << orders[i] << "\n";
}

void TaxiCentral::copy(const char* name, TaxiDriver* drivers, Order* orders) {
	//this->name = new char[]...
	//strcpy_s...

	for (size_t i = 0; i < dSize; ++i)
		this->drivers[i] = drivers[i];

	for (size_t i = 0; i < oSize; ++i)
		this->orders[i] = orders[i];
}

void TaxiCentral::clear() {
	delete[] drivers;
	delete[] orders;
}

void TaxiCentral::dResize() {
	dCap *= 2;
	TaxiDriver* dTmp = new TaxiDriver[dCap];

	for (size_t i = 0; i < dSize; ++i) {
		dTmp[i] = drivers[i];
	}

	delete[] drivers;
	drivers = dTmp;
}

void TaxiCentral::oResize(){
	oCap *= 2;

	Order* oTmp = new Order[oCap];

	for (size_t i = 0; i < dSize; ++i) {
		oTmp[i] = orders[i];
	}

	delete[] orders;
	orders = oTmp;
}

std::ostream& operator<<(std::ostream& out, const TaxiCentral& central) {
	for (size_t i = 0; i < central.dSize; ++i)
		std::cout << central.drivers[i] << "\n";

	for (size_t i = 0; i < central.oSize; ++i)
		std::cout << central.orders[i] << "\n";

	return out;
}