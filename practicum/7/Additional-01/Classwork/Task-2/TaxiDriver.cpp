#include"TaxiDriver.h"
#include <cstring>
#include <stdexcept>

const size_t MAX_LEN = 30;
const size_t BUFF_SIZE = 1024;

TaxiDriver::TaxiDriver() {
	copy("\0", 0, false);
}

TaxiDriver::TaxiDriver(const char* name, size_t salary) {
	if (strlen(name) <= MAX_LEN)
		copy(name, salary, false);

	else
		throw std::invalid_argument("TOO LONG NAME\n");
}

TaxiDriver::TaxiDriver(const TaxiDriver& other) {
	copy(other.name, other.salary, other.busy);
}

TaxiDriver& TaxiDriver::operator=(const TaxiDriver& other) {
	if (this != &other) {
		delete[] name;
		copy(other.name, other.salary, other.busy);
	}

	return *this;
}

TaxiDriver::~TaxiDriver() {
	delete[] name;
}

void TaxiDriver::copy(const char* name, size_t salary, bool busy) {
	this->busy = busy;
	this->salary = salary;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

std::istream& operator>>(std::istream& in, TaxiDriver& driver) {

	if (driver.name)
		delete[] driver.name;


	char buff[MAX_LEN];
	in.getline(buff, MAX_LEN);

	driver.name = new char[strlen(buff) + 1];
	strcpy_s(driver.name, strlen(buff) + 1, buff);

	in >> driver.salary;
	in >> driver.busy;

	return in;
}

std::ostream& operator<<(std::ostream& out, const TaxiDriver& driver) {
	out << driver.name << "\n";
	out << driver.salary << "\n";
	out << driver.busy << "\n";

	return out;
}
