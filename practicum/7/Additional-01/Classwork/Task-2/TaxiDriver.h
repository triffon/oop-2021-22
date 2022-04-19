#pragma once
#include<iostream>
class TaxiDriver {
public:
	TaxiDriver();
	TaxiDriver(const char* name, size_t salary);
	TaxiDriver(const TaxiDriver& other);
	TaxiDriver& operator=(const TaxiDriver& other);
	~TaxiDriver();

	bool isBusy() const {
		return busy;
	}

	const char* getName() const {
		return name;
	}

	void setBusy(bool busy) {
		this->busy = busy;
	}

	friend std::istream& operator>>(std::istream& in, TaxiDriver& driver);
	friend std::ostream& operator<<(std::ostream& out, const TaxiDriver& driver);

private:
	void copy(const char* name, size_t salary, bool busy);

	char* name;
	size_t salary;
	bool busy;
};